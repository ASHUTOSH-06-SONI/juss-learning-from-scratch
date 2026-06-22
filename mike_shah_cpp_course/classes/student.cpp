// implementation details are stored in this 
#include "student.hpp"
    // special functions 
        Student::Student(){
            std::cout<<"constructor"<<std::endl;
        }
        Student::~Student(){
            std::cout<<"destructor"<<std::endl;
        }
        void Student::printname(){
            std::cout<<"name is : "<< x_name << std::endl;
        }
 

// :: is the scope operator, it basically access the member of a class or namespace 
