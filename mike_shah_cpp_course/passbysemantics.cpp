#include<iostream>

using namespace std;
// pass by value
void foo(int arg){
    arg = 6769;
    cout<<&arg<<'\n';
}
// pass by reference
void bar(int& arg){
    arg = 6967;
    cout<<&arg<<'\n';
}

int main(){
    int x = 67;
    foo(x);
    cout<<x<<" "<<&x<<'\n';
}


// pbv is basically creating 2 variables, 1 is base whose value can't be modified, one is the target, whose val is modified
// the target is basically gonna copy the base value and then uspe jo kaand karna hai krr lo
// pbr me there's just 1 variable base and instead of keeping copies, we just change the base directly, but if we wanna ensure that it isn't modified,
// just keep const 