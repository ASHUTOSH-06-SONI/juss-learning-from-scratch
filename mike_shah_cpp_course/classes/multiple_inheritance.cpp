//  THIS CODE HAS ERRORS MADE ON PURPOSE AND HENCE COMMENTED, FOR LEARNING PURPOSES

#include<iostream>
struct noncopyable{
    // delete the copy and copy assignment ctor
    noncopyable()=default;
    noncopyable(const noncopyable& rhs) = delete;
    noncopyable& operator= (const noncopyable& rhs)= delete;
 // now if i make "Cat" class to inherit these properties
 // boom, we can't even construct stuff, well lets juss try and keep the default ctor
};

struct Cat: public noncopyable{
    virtual void meow(){
        std::cout<<"miau"<<std::endl;
    } 
};
/*     noncopyable
          |
         cat
        /  \
persian    Orangecat 
    \       /
     \     / 
    scottish
*/
struct Persian: public Cat{
    virtual void meow() override{
        std::cout<<"persian me miau"<<std::endl;
    }
};
struct Orangecat : public Cat { 
    virtual void meow()override{
        std::cout<<"too much attitude miau"<< std::endl;
    }  
};
// what if i don't implement meow on Scottish
struct Scottish : public Persian, Orangecat{ 
    virtual void meow()override{
        std::cout<<"andrew robertson miau"<< std::endl;
    } 
   // well in my case for somereason, meow function being present or not, either ways the call was ambiguous 
   //  the reason??? basically, scottish is having an identity crisis ki kiska functionality lu 
   // (i've a very casual nsfw joke for this but lets not go there xD)
   // in simple, this is a code for a bad practice in cpp, that is, to prevent multiple inheritences
};
int main(){
    Cat* cat = new Cat;
    // lets juss fafo and see if we can create copies
    Cat cat1;
    /*Cat cat2 = cat1; // yep it shows errors 
    Cat cat2;
    cat2=cat1;// this too */
    Cat* persian = new Persian;
    Cat* orange = new Orangecat;
    Scottish* scottish = new Scottish;
    cat->meow();
    persian->meow();
    orange->meow();
    scottish->meow();
    return 0;
}