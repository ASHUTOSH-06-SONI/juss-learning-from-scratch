#include<string>
#include<iostream>
#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student{
    // 3 types of info can be stored in a class- public, private, protected 
    // Class ka naam, Student constructor and destructor should be same 
    public:
    // special functions 
        Student();
        ~Student();
        void printname();
    private:  // hidden attributes of our class, can't be called outside the scope unless it's public
        std::string m_name; 
    public:
        std::string x_name;
};

#endif