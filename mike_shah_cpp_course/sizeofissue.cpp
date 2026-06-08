#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x = 7; 
    int* px = &x;
    int arr[] = {1,2,3,4,5};
    int* dynamic_arr = new int[1000];
    cout<<"x: "<<sizeof(x)<<'\n';   // integer is 4 bytes
    cout<<"px: "<<sizeof(px)<<'\n';  
    // but pointer is 8 coz 64 bit system, i need to be able to address  any potential piece of memory 
    // and to do that i need 8 bytes to do that on a 64bit system
    cout<<"arr: "<<sizeof(arr)<<'\n';
    // this one takes 20 coz 4 bits* 5 elements = 20 bits totally, but this rule applies only to a STACK ALLOCATED ARRAY
    cout<<"dynamic arr: "<<sizeof(dynamic_arr)<<'\n'; 
    // well here, the datatype is int* so basically its only a pointer pointing to the first integer of the array of 1000 integers.  
    // so again, we just get the pointer size
    vector<int> v; 
    v.push_back(67);
    v.push_back(67);
    v.push_back(67);
    v.push_back(67);
    v.push_back(67);
    v.push_back(67);
    v.push_back(67);    
    v.push_back(67);
    v.push_back(67);
    v.push_back(67);
    v.push_back(67);
    v.push_back(67);
    cout<<"Vector ka size, this will just tell the size of the actual data structure: "<<sizeof(v)<<'\n';
    cout<<"True size of vector, this will tell number of elements: "<<v.size()<<'\n';
}