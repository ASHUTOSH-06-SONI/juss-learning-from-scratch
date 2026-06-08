#include<iostream>
using namespace std;
int main(){
    int arr[]= {1,3,5,7,9};
    int* px= arr;
    cout<<arr[0]<<'\n';
    cout<<px<<'\n';
    px++; 
// so this moves by 4 bytes coz each box in arr is 4 bytes, toh for any given data type, when we increment it, it moves according to the 
// size of data type for 1 box or 1 unit's equivalent  and on de referencing, jis bhi dabbe pe vo point kar raha hai, usi ka data dikha dega 
    cout<<px<<'\n';
    cout<<*px<<'\n';   // so this basically points to the element ka address 
    cout<<*(px+0)<<'\n';
    cout<<*(px+1)<<'\n';
    cout<<*(px+2)<<'\n';
    cout<<*(px+3)<<'\n';
    cout<<*(px+4)<<'\n';
// even array offset will work the same way here so, *(array+n) will give the same output the way *(px+n) does
// the diff bw array offset and arr[n] is that, you are de referencing that array or that address already
}
