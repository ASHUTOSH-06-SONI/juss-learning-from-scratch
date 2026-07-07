// we're gonna deliberately make some bugs in here and then write it's fixes in this code
#include<iostream>
// pass by value 
class Array{
public: 
    Array(){
        std::cout<<"Ctors"<<std::endl;
    }
    ~Array(){
        std::cout<<"Dtors"<<std::endl;
    }
    Array(const Array&){
        std::cout<<"Copy Ctors"<<std::endl;
    }
    Array& operator=(const Array&){
        std::cout << "Copy Assignment\n";
        return *this;
    }
    void Set_Data(int index, int value);
};
void Print_bugged(Array arr){
    // this function is essentially creating a copy 
    std::cout<<"Inside Print but bugged "<<std::endl;
    /*
    Explanation to why is the copy constructor invoked in the first place
    so lets say there are 2 ppl, A,B
    A asks B for his notebook, but but but that ain't good coz what if A scribbles on B's OG Notebook
    that's bad fs, so Cpp juss takes the safer route, create a copy of B's og Notebook
    so even if A writes on that stuff, nothing happens to B's og book for obvious reasons
    once the work is done, the copy is destroyed by the destructor
    */
}
void Print_kindafixed(Array& arr){
    // No copy is made, but the function is allowed to modify the original object.
    /*
    A just "reads" B's notebook but A can act notorious here and still scribble over it 
    */
    std::cout<<"The Object is still kinda mutable"<<std::endl;
}
// final fix to void print
void Print_fixed(const Array& arr){
    std::cout<<"Inside Print but fixed"<<std::endl;   //Passing by const reference doesn't invoke the copy constructor
    /*
    In this case, by adding const and by pointing to the object, 
    const ensures ki A won't write ANYTHING in B's og Notebook
    and the reference, well, it lets us access the original object without making a copy
    in the first case A says to B- Give me your notebook
    now A says, Just point at your notebook, so A's essentially just "reading" the book

    Another reason as to why this model works is because, lets say we've got some insanely huge data, then making copies won't help
    to get every nanosecond of that speed, you need to find ways to hack out the path that gets work done fast, so instead you just 
    point to the immutable object.
    */
} 
Array Create(){
    Array a;
    return a;
    /*
    In this case, the bug lies in compile time so the difference is in the commands used to run 
    first case : g++ -fno-elide-constructors class3pt2.cpp -o prog && ./prog
    Ctors
    Copy Ctors
    Dtors
    Copy Ctors
    Dtors
    Dtors
    Second case : g++ class3pt2.cpp -o prog && ./prog                        
    Ctors
    Dtors    */
}
/*
In second case, according to compiler why bother creating a, and then then copy it into x?
instead just construct x directly
In first case, we just ask the compiler to show us what would happen without this optimization of removing redundant copying
*/
int main(){
    // bug 1   
    Array a;
    Print_bugged(a);
    std::cout<<'\n';
    Print_kindafixed(a); 
    std::cout<<'\n';
    Print_fixed(a); 
    std::cout<<'\n';
    std::cout<<"========================"<<std::endl;
    // bug 2
    Array x = Create();
    std::cout<<"========================"<<std::endl;
    // bug 3- accidential copy 
    Array b= a;  // this thing invokes the copy constructor
    /* the whole flow is like- constructor invoked, then 
    b=a invokes copy constructor coz copy initialization is done, 
    then b gets destroyed coz main ka scope ends.
    then a gets destroyed */
    std::cout<<"========================"<<std::endl;
    // bug 4
    Array c;
    c = a;  // the thing to notice here is that copy constructor isn't invoked, rather copy assignment
    // why's that
    /* think of it this way, c was already created, so that implies,
    the house is already created, but now we revamp it by doing c= a
    how dis differs from Array b= a ; is that in this case, we've just created a new object called b using a 
    toh that's where the copy constructor gets invoked
    FINALLY TO STATE THE KEY DIFFERENCE, C IS ALREADY CREATED, B IS NEW BORN
    THE MOMENT B IS BORN, IT IS COPIED
    C WAS ALREADY BORN SO NOW WE JUST DO CHANGES TO IT 
    */
    std::cout<<"========================"<<std::endl;
    // bug 5
    Array& ref = a;
    std::cout<<"========================"<<std::endl;
    // bug 6
    const Array& ref2 = a;
}