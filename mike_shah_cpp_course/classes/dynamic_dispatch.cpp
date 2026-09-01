#include<iostream>

// dynamic dispatch- at run time, this helps us find the correct function to call 
class Base{
    public:
        Base(){
            std::cout<<"Base Constructor"<<std::endl;
        }
        ~Base(){
            std::cout<<"Base Destructor"<<std::endl;
        }
        virtual void MemFunc(){      // here this function is rendered virtual, we put it on non static member functions
            // agr idhar virtual laga diya, toh me writing override doesn't change the output, well atleast in this example
            // so juss for good practices, use override in the derived classes
            std::cout<<"Base member function"<<std::endl;
        }
};

class Derived: public Base{
    public:
        Derived(){
            std::cout<<"Derived Constructor"<<std::endl;
        }
        ~Derived(){
            std::cout<<"Derived Destructor"<<std::endl;
        }
        void MemFunc()override{         // and this function ovverrides the func in base class
            std::cout<<"Derived member function"<<std::endl;
        }

};

int main(){
    Base* instance = new Derived;
    //instance->MemFunc();
    // now lets say instead of overriding, i want to see my base mem function, so we do that explicitely
    instance->Base::MemFunc();
    delete instance;
    return 0;
}


