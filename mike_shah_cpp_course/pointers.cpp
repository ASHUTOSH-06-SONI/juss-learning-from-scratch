#include<iostream>
using namespace std;
int* returnmemory(){
    int res = 6969; // this was just stack allocated memory
    return &res;
}
int main(){
    // stores x ka address
    int x = 7;
    int* px = &x;
    x = 9; // updating x and so px will point to the location of x, hence the value on de referencing will also be that of x 
    *px = 67; 
    cout<<"x stores: "<<x<<'\n';
    cout<<"x addr "<<&x<<'\n';
    cout<<"px stores: "<<px<<'\n';
    cout<<"px dereferenced: "<<*px<<'\n';
    cout<<*px<<'\n';
    cout<<x<<'\n';
    // pointer pitfalls
    int* px1 = nullptr;
    *px1 = 67;  // dereferencing something you don't have access to.
    while(true){
        int* ptr = new int[10]; // memory leak so this stuff ofccurs until the os eventually crashes 
    }
    int* px2 = returnmemory();  // dangling pointers
    cout<<"on dereferencing: "<<*px<<'\n';  // on purpose galti kar raha hu idhar 
    // pointers.cpp:5:13: error: address of stack memory associated with local variable 'res' returned [-Werror,-Wreturn-stack-address]
    // this happens coz it's not clear when &res goes out of scope, so what even are we de referencing 
    return 0;
}

/* what's the point?
well, here px "points" to x  so basically, you can get multiple variables, sharing or more precisely
pointing to one particular variable's value while being referenced to the target variables address
*/

/* now look at the fun part
i do *px = 67 and now return the value of x 
it shows x = 67
so basically x = 67 got over written by *px ka value even tho x was supposed to be 9
*/