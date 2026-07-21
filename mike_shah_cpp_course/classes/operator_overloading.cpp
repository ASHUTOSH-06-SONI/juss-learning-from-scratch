#include<iostream>
class Vectoraah{
    public:
        Vectoraah(){
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    Vectoraah operator+(const Vectoraah& rhs)const{
        Vectoraah result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        result.z = z + rhs.z;
        return result;
    }
    float x,y,z;
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
