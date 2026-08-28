#include<iostream>
class Base{
    public:
        Base(){
            std::cout<<"Base Constructor"<<std::endl;
        }
        ~Base(){
            std::cout<<"Base Destructor"<<std::endl;
        }
        int m_base_public_mem_var;
    protected:
        int m_base_protected_mem_var;
    private:
        int m_base_private_mem_var;
};
class Derived: public Base{
    public:
        Derived(){
            std::cout<<"Derived Constructor"<<std::endl;
            m_base_public_mem_var = 6769;
            m_base_protected_mem_var = 6767;
            // m_base_private_mem_var = 6969; // only this one shows issues
            // protected means- you're not allowed to be seen from the outside world, 
            // but you can be seen in the class that you're derived from
            // // this stuff can be modified in child class, but not in main
        }
        ~Derived(){
            std::cout<<"Derived Destructor"<<std::endl;
        }

};

int main(){
    Derived d;
    d.m_base_public_mem_var = 67;
    // d.m_base_protected_mem_var = 69;  already squiggles, not even gonna compile
    // d.m_base_private_mem_var = 69420; same issue
    return 0;
}