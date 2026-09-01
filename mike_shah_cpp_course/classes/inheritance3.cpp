#include<iostream>

class Toplevelclass{
    public:
        Toplevelclass(){}
        Toplevelclass(std::string arg){
            std::cout<<"Top level class"<<std::endl;
        }
};

class Base: public Toplevelclass{
    public:
        Base(){
            std::cout<<"Base Constructor"<<std::endl;
        }
        // we're doing this to see which constructor is being called
        Base(std::string name): Toplevelclass(name), m_name(name){
            std::cout<<"Base(Name) Constructor"<<std::endl;
        }
        ~Base(){
            std::cout<<"Base Destructor"<<std::endl;
        }
    private:
        std::string m_name;
};

class Monster: public Base{
    public:
        Monster():Base("default"){
            std::cout<<"Monster Constructor"<<std::endl;
        }
        ~Monster(){
            std::cout<<"Monster Destructor"<<std::endl;
        }
};

int main(){
    //Monster m;
    //std::cout<<"------------------"<<std::endl;
    // Monster badm("ash");  // this throws an error coz child class monster, doesn't have the derived part 
    // now to fix this, in the monster class, we juss update the constructor like this- Monster():Base("default")
    Monster badmonster;
    return 0;
}

