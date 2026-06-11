#include<iostream>
#include<functional>

int add(int x,int y){
    return x+y;
}
// typedef int (*someoperation)(int,int);
int main(){
    std::function<int(int,int)> op;
    op = add;
    std::cout<<"adding: "<<op(2,2)<<std::endl;
    // someoperation op;
}