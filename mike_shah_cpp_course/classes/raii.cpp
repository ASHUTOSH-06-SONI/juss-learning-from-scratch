#include <iostream>
class Collection{
    public:
        Collection(){
            data = new int[10];
        }
        ~Collection(){
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
    /*
    int* p = new int(5); // Heap memory created
    delete p;  // Memory returned to allocator
    std::cout << *p << std::endl;   //Reading memory that no longer belongs to you lol
    */
   Collection fahh;
   fahh[0]=67;
   fahh[1]=67;
   fahh[2]=67;
   fahh[3]=67; 
   std::cout<<fahh[0]<<std::endl;
}
