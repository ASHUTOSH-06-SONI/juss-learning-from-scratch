#include<iostream>
#include "arr.hpp"
Array::Array(){
    std::cout<<"Constructor"<<std::endl;
    for(int i =0; i<10; i++){
        data.push_back(i);
    }
}
Array::~Array(){
}
Array::Array(const Array& rhs){
            std::cout<<"Copy Constructor"<<std::endl;
            for(int i =0; i<rhs.data.size(); i++){
                data.push_back(rhs.data[i]);
            }
}
Array& Array::operator=(const Array &rhs){
    std::cout<<"Copy Assignment Operator"<<std::endl;
    if(&rhs == this ){
        return *this;
    }
    data.clear();
    for(int i =0; i<rhs.data.size();i++){
        data.push_back(rhs.data[i]);
    }
    return *this;
}

void Array::Set_Data(int index, int value){
    data[index]= value;
}
void Array::Printdata(){
    for(int i =0; i<data.size();i++){
        std::cout<<data[i]<<std::endl;
    }
}
int main(){
    Array ashu_array;
    ashu_array.Set_Data(0,676767);
    ashu_array.Set_Data(1,67);
    ashu_array.Set_Data(2,677);
    Array ashu_array2;
    ashu_array2= ashu_array;// copy assignment operator  
    ashu_array2.Printdata();
    ashu_array2.Printdata();
    return 0;
}