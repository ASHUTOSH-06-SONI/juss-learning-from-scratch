#include<iostream>
#include<string>
#include "student.hpp"
int main(){
    std::cout<<"Start"<<std::endl;
    Student* Ash = new Student;
    delete Ash;   // for a HEAP object if we don't explicitely delete the class, then the destructor isn't called 
    std::cout<<"End"<<std::endl; 
    Student Ashu;  // for a STACK object it doesn't matter, destructor is called anyhow 
    Ashu.x_name = "Ash";  
    Ashu.printname(); 
    return 0;
    Student ashu; 
    ashu.x_name = "not skill issue";
    ashu.printname();
}