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
    Buffer b = a;
    return 0;
}