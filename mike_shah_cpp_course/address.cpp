#include<iostream>

using namespace std;
void foo(){

}
int main(){
    int x = 67;
    char a= 'a';
    string s = "hsdfjbn";
    cout<<&(x)<<'\n';// address of x
    cout<<(void*)&a<<'\n';
    cout<<(void*)&foo<<'\n';
    cout<<(void*)&main<<'\n';
    cout<<&s<<'\n';
// & also acts as a function so if i do &(x) then the address gets returned  
}

