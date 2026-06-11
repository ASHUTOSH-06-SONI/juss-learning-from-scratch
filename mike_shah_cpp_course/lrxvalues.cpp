// this code has all issues to explain lvalue, rvalue and xvalues.
#include<string>
#include<iostream>
int get67(){
    return 67;
}
void setvaltosomeval(int& change_dis_var){
    change_dis_var = 69;
}
int main(){
    // get67()=69; // the error: expression must be a modifiable lvalueC/C++(137)
    int x = 10;
   //  10 = x; // again the same issue
   // the fix to this is to use l value referencing
   // int&ref = x; will work
    const int& ref = 11;
    // conversely, int& ref = 10; will also throw an error, coz you can't bind "non const" lvalue ref to an r value 
    // but if it's a constant lvalue reference, then no issues
    int i; std::cin>>i;   // now this stuff will change but only i goes in as input 
    setvaltosomeval(i);
    // again, if i setvaltosomeval(10);
    // setvaltosomeval(10); candidate function not viable: expects an lvalue for 1st argument
    std::cout<<ref<<" "<<i<<std::endl; 
    int&& rvalref = 10;
    std::cout<<rvalref<<std::endl;
    std::string s1 = "skill";
    std::string s2 = "issue";
    std::string&& s3 = s1+s2;
    std::cout<<s3<<std::endl;
    return 0;
}