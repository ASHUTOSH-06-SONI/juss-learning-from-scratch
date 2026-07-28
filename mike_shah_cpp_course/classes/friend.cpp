#include<iostream>
class Userdefinedtype{
    public:
        Userdefinedtype(): m_pvtmemvar(0){}
    private:
        int m_pvtmemvar;
    friend void Printpvtvars(Userdefinedtype u );

};
void Printpvtvars(Userdefinedtype u){
    std::cout<<"m_pvtmemvar : "<<u.m_pvtmemvar<<std::endl;

}

/*
when use this?
sometimes an operation logically belongs outside the class,
but still needs access to the internals.
*/
int main(){
    Userdefinedtype inst;
    Printpvtvars(inst);
    return 0;
}