// std vector isn't just any array
// we construct objects inside it, destroy manually, free raw memory
// new T = allocation and construction
// op new allocates raw memory
// op delete calls the destructor
// placement new 

#include <iostream>
// constructor is a special member function that is automatically called when an object of a class is created
class A {
public:
    A() { std::cout << "Constructor\n"; }
    ~A() { std::cout << "Destructor\n"; }
};
class B {
public:
    ~B() { std::cout << "Destroyed\n"; }
};
class c {
public:
    c();                 // default constructor
    c(int x);            // parameterized
    c(const c& other);   // copy constructor
    c(c && other);        // move constructor
};
/*
void* raw = operator new(sizeof(B));
B* obj = new(raw) B();
HEAD
obj->~B();           // valid
obj->~B();           //  valid
c6cbbe5 (Added custom vector implementation and gitignore)
operator delete(raw);
*/
int main() {
    A* p = new A();
    // if i use delete;, output is constructor then destructor
    // else its just constructor
    // new allocates memory and constructs an object in that memory
    // when we run delete, destructor runs and so delete does the total opp of new that is, destruct the object and free the memory
    delete p;
    // operator new basically allocates raw memory, returns void* , it doesn't construct ANY THING 
    void* raw = operator new(sizeof(int));
    // placement new- memory is there but object isn't so basically, Construct an int at memory location raw.
    int* q = new(raw) int(42);
    // Now the object exists.
    std::cout << *q << "\n";
    // You MUST manually call the destructor. 
    // q->~int(); For primitive types, nothing else is needed. This line's to destroy object
    operator delete(raw); // free memory
    // Because you split allocation and construction manually.
    return 0;
}
