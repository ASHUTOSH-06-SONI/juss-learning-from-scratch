#include<iostream>
#include<cstring>
class Buffer{
private:
    int* data;
    size_t size;

public:
    // constructor class
    Buffer(size_t n): size(n){
        data = new int[n];
        std::cout<<"constructor"<<'\n';
    }
    // destructor class
    ~Buffer() {
        delete[] data;
        std::cout<<"destructor"<<'\n';
    }
    // copy constructor
    Buffer(const Buffer& other): size(other.size){
        data = new int[size];
        std::memcpy(data, other.data, size * sizeof(int));
        std::cout<<"Copy constructor"<<'\n';
    }
    // move constructor
    Buffer(Buffer&& other) noexcept: data(other.data), size(other.size){
        other.data = nullptr;
        other.size = 0;
        std::cout<<"Move Constructor"<<'\n';
    }
};
int main(){
    std::cout<<"Creating a\n";
    Buffer a(5);
    std::cout << "\nCopying a into b\n";
    Buffer b = a;   // calls copy constructor
    std::cout << "\nMoving a into c\n";
    Buffer c = std::move(a);  // calls move constructor
    std::cout << "\nEnd of main\n";
    return 0;
}