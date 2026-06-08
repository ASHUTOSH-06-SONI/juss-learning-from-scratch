#include<iostream>
#include<numeric>
#include<iterator>
#include<array>
using namespace std;

int main(){
    array<int,100> ids;
    iota(begin(ids),end(ids),0);
    ids.at(99)=9;
    for(int i:ids){
        cout<<i<<'\n';
    }    
   array<int,3> x;
   fill(begin(x),end(x),1024);
   for(int i:x ){   // this will print garbage values coz they aren't initialized
        cout<<i<<'\n';
   }
}

// iota basically is a quick way to fill your array  