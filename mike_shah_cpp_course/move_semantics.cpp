/* DISCLAIMER- 
THIS CODE HAS SEGFAULTS ON PURPOSE 
TO ELABOARTE THE DESTRUCTION OF POINTERS WHICH DO NOT HAVE ANY OWNERS HENCE THE SEG FAULT
*/
#include<iostream>
#include<string>
#include<memory>
#include<vector>
void print(int *ptr){
    std::cout<< *ptr<<std::endl;
}
std::unique_ptr<int> create(){
    auto ptr2 = std::make_unique<int>(42);  // here ptr2 owns 42
    return ptr2;
}
int main(){
    // std::move 
    std::string s1 = "skill";
    std::string s2= "issue"; 
    // so basically even if i don't leave this empty, issue gets overwritten by skill
    std::cout<<"first string :"<<s1<<std::endl;
    std::cout<<"second string: "<<s2<<std::endl; 
    s2 = std::move(s1);
    // insert akshay kumar swapping stuff meme lol
    std::cout<<"first string :"<<s1<<std::endl;   
    std::cout<<"second string: "<<s2<<std::endl;
    
    // shared pointers- std::make_shared
    auto pa = std::make_shared<int>(67);
    auto pb = pa;
    std::cout<<"Address of pointer a: "<<pa<<" "<<"Address of pointer b: "<<pb<<std::endl;
    std::cout<<"values of a,b: "<<*pa<<" "<<*pb<<std::endl;
    pa.reset();
    pb.reset();
    std::cout<<"After resetting pa the ownership goes to pb: "<<*pa<<" "<<pa<<std::endl;  // since this points to nullptr- it shows segfault
    std::cout<<"After resetting pb the object itself gets destroyed: "<<*pb<<" "<<pb<<std::endl;  
    // since this points to nullptr too (coz the object is destroyed) - it shows segfault too


    // std::unique_ptr- top tier shit, isko use kiya toh no worries about freeing up the memory
    // integer is strictly owned by ptr, so the moment ptr dies, memory gets de allocated
    // when will this die? well it has to be scoped that's it. 
    auto val = create();    // in this instance the owner of ptr2 is not create(), it's val, ownership is transferred
    std::cout<<"Address: "<<val<<" "<<"integer owned by val: "<<*val<<std::endl;
    auto val2 = std::move(val);
    if(val == nullptr){
        std::cout<<"val is empty"<<std::endl;
    }
    std::cout<<*val2<<std::endl;
    std::cout<<val2<<std::endl;
    std::cout<<"Address: "<<val<<" "<<"integer owned by val: "<<*val<<std::endl;
    // now this stuff should give seg fault coz for unique pointers empty literally means ptr == nullptr hence the seg fault
    // non owning pointer- here print doesn't own x
    // x is owned by main, print just borrows x ka access 
    // also known as reference pointer
    int x = 5; 
    print(&x);
}
