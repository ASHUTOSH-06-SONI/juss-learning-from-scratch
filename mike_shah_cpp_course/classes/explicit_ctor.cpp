#include<iostream>
#include<string>
class userdeftype{
    public:
        userdeftype(int);
    private:
        int m_variable;
         
};
userdeftype::userdeftype(int i){
    m_variable = i;
    std::cout<<"m_variable = "<<m_variable<<std::endl;
}
int main(){
    userdeftype u1(67.00f);  // juss truncates and get off the decimal point
    userdeftype u2 = 67.6767f; // now this thing throws errors
    // or, we juss make it explicit in the class, so the error kicks in for u1(67.00f);
    userdeftype u3{500};
    return 0;
}