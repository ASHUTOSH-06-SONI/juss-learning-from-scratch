#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Constructor\n"; }
    ~A() { cout << "Destructor\n"; }
};

int main() {
    void* raw = operator new(sizeof(A));  // raw memory

    A* p = new(raw) A();   // placement new

    p->~A();               // manual destructor

    operator delete(raw);  // free memory
}