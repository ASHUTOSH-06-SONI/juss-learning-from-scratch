/*RAII in simple- own resources through objects, not through manual new or delete.*/
#include <iostream>
class Collection{
    public:
        Collection(){
            data = new int[10]; // object aquires the resource- (heap)
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
   fahh[0]=67; // using the resource
   fahh[1]=67;
   fahh[2]=67;
   fahh[3]=67; 
   std::cout<<fahh[0]<<std::endl;
} // scope ends here and the destructor gets called, apne aap
