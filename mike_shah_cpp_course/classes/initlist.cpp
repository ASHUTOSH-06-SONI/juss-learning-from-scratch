#include<iostream>
#include<initializer_list>

struct Userdef{
    Userdef(int a, int b){
        std::cout<<"2 args ctor"<<std::endl;
    }
    /*
    Userdef(std::initializer_list<int> data): m_data(data){
        std::cout<<"init list ctor"<<std::endl;
        m_data = data;
    }
        */
    void printdata(){
        for(auto& it:m_data){
            std::cout<<it<<std::endl;
        }
    }
    ~Userdef(){

    }
    private:
    std::initializer_list<int> m_data;
};
int main(){
    // Userdef u{6,7};// use curly braces and you get init list ctor, so the type is specified here
    Userdef u(6,7); // now the 2 args ctor type is specified here
    u.printdata();
    // lets fafo with the internals
    /* Userdef v{6.7, 6.9}; // throws error coz implicit conversion
    v.printdata();
    curly brace initialization implies that init list will prevent the narrowing of data
    this helps us work with unknown type data
    */
    Userdef w{6,7}; // since there's no init list this time that's set up as a ctor, it finds  2 args ctor
    // curly braces ensure type is integer
    w.printdata();
    return 0;
}