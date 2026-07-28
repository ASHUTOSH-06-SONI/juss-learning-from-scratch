/*
Even if something unexpected happens
after acquiring the resource,
the object still cleans up when it dies.
That's how RAII Ensures safety, coz no memory leaks
*/
#include <iostream>
class Collection{
    public:
        Collection(){
            data = new int[10]; 
            try{
                throw 20;
            }catch(int e){
                // throw sm error 
            }
        }
        ~Collection(){
            // thing gets called either ways
            std::cout<<"see, it gets called"<<std::endl;
            delete[] data;
        }
        int& operator[](std::size_t idx){
            return data[idx];
        }
        const int& operator[](std::size_t idx) const{ return data[idx]; }
    private:
        int* data;
};
int main() {
   Collection fahh;
   fahh[0]=67; // using the resource
   fahh[1]=67;
   fahh[2]=67;
   fahh[3]=67; 
   std::cout<<fahh[0]<<std::endl;
} // scope ends here and the destructor gets called, apne aap
