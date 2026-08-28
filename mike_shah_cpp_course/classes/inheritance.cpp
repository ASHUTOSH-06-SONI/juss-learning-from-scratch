#include<iostream>
class cat{
    public:
        cat(){
        }
    void meow(){
        std::cout<<"miau"<<std::endl;
    }
    void walk(){
        x+=1;
        y+=1;
    }
    float x,y;
};

        /*
             cat
              |
              v
             persian
              |
              v
             Berry
            Berry apni maa pe gayi hai, toh that's inheritng persian's properties
            persian cat is a cat, so that is inheriting a basic cat's properties
        */
class Persian: public cat{
    public:
        void purr(){
            std::cout<<"Purrr...."<<std::endl;
        }
};
class Berry : public Persian { 
    // persian ka bilota 
public:
    void sleep(){
        std::cout<<"Zzz..."<< std::endl;
    }
    void eat(){
        std::cout<<"nom nom nom nom"<<std::endl;
        // his greed sickens me -_-
    }
};
int main(){
    Persian cat1;
    cat1.meow();
    cat1.walk();
    cat1.purr();
    Berry cat1_ka_bilota;
    cat1_ka_bilota.eat();
    cat1_ka_bilota.sleep();
    cat1_ka_bilota.meow();
    cat1_ka_bilota.purr();
    return 0;
}