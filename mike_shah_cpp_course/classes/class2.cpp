#include<iostream>
#include<string>
class vector_ash{
    public:
        float x,y,z;
};
int main(){
    vector_ash my_vector;
    my_vector.x = 1.0f;
    my_vector.y = 2.0f;
    my_vector.z = 3.0f;
    vector_ash notmyvector= my_vector;  // copy assignment 
    std::cout<< my_vector.x << ", " << my_vector.y << ", " << my_vector.z <<std::endl;
    std::cout<< notmyvector.x << ", " << notmyvector.y << ", " << notmyvector.z <<std::endl;
    return 0;
}