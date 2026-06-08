#include<iostream>
using namespace std;
int x = 67; // globally scoped variable
int main(){
    {
        int x = 69; 
    }
    // The variable x is declared inside the block (enclosed by curly braces),
    // and it is not accessible outside of that block.
    // Therefore,
    //trying to assign a value to x outside of the block will result in a compile error, 
    // as x is not defined in that scope. 
    {int x = 420;} 
    cout<<x<<'\n';
    return 0;
}  

// if i put int behind all x, then only the global variable will be printed
// other wise the last local variable will be printed.