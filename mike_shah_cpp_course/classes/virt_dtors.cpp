#include<iostream>

// dynamic dispatch- at run time, this helps us find the correct function to call 
class Base{
    public:
        Base(){
            std::cout<<"Base Constructor"<<std::endl;
            basedata = new int[10];
        }
        virtual ~Base(){
            std::cout<<"Base Destructor"<<std::endl;
            delete[] basedata;

        }
        virtual void MemFunc(){     
            std::cout<<"Base member function"<<std::endl;
        }
    int* basedata;
};

/*
Fault ?, there's some allocations that aren't done yet
so again, base destructor pe virtual lagana is important
*/
class Derived: public Base{
    public:
        Derived(){
            std::cout<<"Derived Constructor"<<std::endl;
            deriveddata = new int[15];
        }
        ~Derived(){
            std::cout<<"Derived Destructor"<<std::endl;
        }
        void MemFunc()override{        
            std::cout<<"Derived member function"<<std::endl;
            delete[] deriveddata;
        }
    int* deriveddata;
};

int main(){
    Base* instance = new Derived;
    instance->MemFunc();
    delete instance;
    return 0;
}


