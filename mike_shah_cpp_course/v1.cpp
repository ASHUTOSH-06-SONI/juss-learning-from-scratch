#include<iostream>
#include <iomanip>

using namespace std;
int main(){
    const float x = 1660.43404f; // statically typed variable
    cout<<x<<'\n';
    // x = 59.3562; // This will cause a compile error since x is const
    cout<< sizeof(x)<<" "<<"Bytes"<<'\n';
    cout << fixed << setprecision(5) << x << '\n';
    return 0;
}

/* float is 32 bit so sizeof x = 4 but double ka size is 64bit 
so sizeof x = 8. By default, the value of x is printed with 6 decimal places.
To print it with 5 decimal places, 
we can use the fixed and setprecision manipulators 
from the iomanip library. 
The fixed manipulator ensures that the number is printed in fixed-point notation,
and setprecision(5) sets the number of decimal places to 5.
float x = 1660.43404f; here the point of putting f is when 
we want float precision explicitely mainly to prevent 
double to float conversion
In short: ...f means “float literal”; without f means 
“double literal then convert to float”.
*/