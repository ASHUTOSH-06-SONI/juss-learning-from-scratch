#include<iostream>
#include<string>
class Student{
    // 3 types of info can be stored in a class- public, private, protected 
    // Class ka naam, Student constructor and destructor should be same 
    public:
    // special functions 
        Student(){ // constructor, member function
            std::cout<<"constructor"<<std::endl;
        }
        ~Student(){
            // destructor
            std::cout<<"destructor"<<std::endl;
        }
        void printname(){
            std::cout<<"name is : "<<x_name<<std::endl;
        }
    private:  // hidden attributes of our class, can't be called outside the scope unless it's public
        std::string m_name; 
    public:
        std::string x_name;
};
int main(){
    std::cout<<"Start"<<std::endl;
    Student* Ash = new Student;
    delete Ash;   // for a HEAP object if we don't explicitely delete the class, then the destructor isn't called 
    std::cout<<"End"<<std::endl; 
    Student Ashu;  // for a STACK object it doesn't matter, destructor is called anyhow 
    Ashu.x_name = "Ash";  
    Ashu.printname(); 
    return 0;
}