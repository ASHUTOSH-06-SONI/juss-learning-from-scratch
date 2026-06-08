#include<iostream>
using namespace std;
int main(){
    int* x = new int;
    *x = 67;
    delete x;
    delete x;
    return 0;
} 
/*
trace trap is the warning it gives
The Second Delete tells the OS to free that exact same address again.
The Trap here is that macOS memory manager realizes you are trying to alter a block of memory that you no longer own. 
If allowed, this could lead to heap corruption or a double-free exploit 
where hackers hijack program control- 
hackers can hijack program control by tricking the system into assigning the same block of memory to 
two completely different parts of a program.
By manipulating this shared memory, an attacker can overwrite critical system data, such as function pointers,
to redirect execution to their own malicious code
The fix for this is to safeguard the system, 
the OS instantly halts your program with a hardware breakpoint instruction, which prints out as Trace trap.

lowkey crazy thinking imho
*/