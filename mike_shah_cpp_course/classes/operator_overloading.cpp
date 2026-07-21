#include<iostream>
class Vectoraah{
    public:
        float x,y,z;  
        /* the way it works is ki order hoti hai ek 
        ab if my order is x,y,z then the initialization of variables is also going to be that way
        so if i initialize like y(3),z(2),x(1) the output's gonna be 3,2,1
        Now talking about order, lets say i do y(x),z,x- the order of initialization was x,y,z
        but now we're using x's value to initialize y
        so it becomes 1,2,1
        the reason as to why we emphasize on the order is going to be clear in this example now
        y(z),z,x- here the vals are- 3,some random number, 2
        and the reason is clear here, x initialized, y initialized based on z which isn't initialized yet, and then z initialized
        so x,y,z order results in the output as such- lets say the order was float x,z,y, then it'd be perfectly fine
        RULE OF THUMB- THE ORDER IN WHICH YOU LAY OUT THE THINGS IN MEMORY, THE SAME ORDER MUST BE RETAINED WHILE INITIALIZING
        MEMBER INITIALIZER LIST 
        */
        Vectoraah():y(x), z(2.0f), x(3.0f){
            // there's another way to initialize
           /* 
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
            */
        }
    Vectoraah operator+(const Vectoraah& rhs)const{
        Vectoraah result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        result.z = z + rhs.z;
        return result;
    }
    Vectoraah operator++(){
        x+=1;
        y+=1;
        z+=1;
        return *this;
    }
    // if we make op ==, then the member function looks like this 
    bool operator==(const Vectoraah& rhs)const { // this  -> lmao and  rhs  -> lolxd
        // the reason for this is because there's already an implicit argument called "this" 
        return x == rhs.x && y == rhs.y && z == rhs.z;
        // the problem with this is precision while dealing with floating point 
        // lets say xyz of lmao are 0.99999f and xyz of lolxd are 1.0f, it'll juss say xyz of lmao == xyz of lolxd
    }
};
/* 
if we make a non member function, it looks like this- here, operator==(lmao, lolxd);
bool operator==(const Vectoraah& lhs, const Vectoraah& rhs){
        if(lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z){
            return true;
        }return false;
    }
*/
std::ostream& operator<<(std::ostream& os, const Vectoraah& obj){
    os<<obj.x<<","<<obj.y<<","<<obj.z<<std::endl;
    return os;
}
int main(){
    Vectoraah lmao;
        lmao.x = 0.999999999f;
        lmao.y = 0.999999999f;
        lmao.z = 0.99999999f;

    Vectoraah lolxd;
        lolxd.x = 1.f;
        lolxd.y = 1.f;
        lolxd.z = 1.f;
    Vectoraah result;
    // lmao = lmao+lolxd;
    std::cout<<lmao.x<<","<<lmao.y<<","<<lmao.z<<std::endl;
    // what if i didn't want to create Vectoraah result, so i'll juss replace result with lmao and see
    // same answer
    // op ++ 
    std::cout<<"------------"<<std::endl;
    /*
    ++lmao; 
    ++lmao;  
    ++lmao;  
    ++lmao; 
    std::cout<<lmao.x<<","<<lmao.y<<","<<lmao.z<<std::endl;
    std::cout<<lmao<<std::endl;
    */
    std::cout<<(lmao==lolxd)<<std::endl;
    return 0;
}
