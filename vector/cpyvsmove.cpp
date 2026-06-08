#include<iostream>
#include<cstring>

// this class owns heap memory, it allocates memory, frees memory, owns a resource
class Buffer{
private:
    int* data;
    size_t size;

public:
    Buffer(size_t n): size(n){
        data = new int[n];
        std::cout<<"constructor"<<'\n';
    }
    ~Buffer(){
        delete[] data;
        std::cout<<"destructor"<<'\n';
    }
};
int main(){
    Buffer a(5);
    Buffer b = a;   // a and b point to the same memory, this is shallow copy
    /*
    When program ends:
    b destructor runs -> deletes memory
    a destructor runs -> deletes SAME memory again
    This is why shallow copy is dangerous for resource-owning classes.
    */
    return 0;
}