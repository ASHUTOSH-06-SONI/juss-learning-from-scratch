// deep copy
#include<iostream>
class Array{
    public:
        Array(){
            std::cout<<"Constructor"<<std::endl;
            data = new int[10];
            for(int i =0; i<10; i++){
                data[i]=i*i;
            }
        }
        ~Array(){
            delete[] data;
        }
        // copy constructor
        Array(const Array& rhs){
            std::cout<<"Copy Constructor"<<std::endl;
            delete[] data;
            data = new int[10]; // reallocate the memory
            for(int i =0; i<10; i++){
                data[i]=rhs.data[i];
            }
        }
        // copy assignment operator
        // object is already constructed, we just make a copy later
        Array& operator = (const Array& rhs){
            std::cout<<"copy assignment operator"<<std::endl;
            if(&rhs == this){
                return *this;
            }
            delete[] data;  // object already owns some memory, so first free it.
            data = new int[10]; // allocate fresh memory for this object.
            for(int i = 0; i<10; i++){
                data[i]= rhs.data[i];  // deep copy every element.
            }return *this;
        }
        void set_Data(int idx, int val){
            data[idx] = val;
        }
        void print_arr(){
                for(int i =0; i<= 10; i++){
                std::cout<<data[i]<<std::endl;
            }
        }
    private:
        int* data;
};

int main(){
    Array ash_array;
    ash_array.set_Data(0,67676767);
    ash_array.set_Data(1,5);
    ash_array.set_Data(2,6); 
    ash_array.print_arr();
    // Array ash_array2 = ash_array;  
    Array ash_array3;
    ash_array3 = ash_array; // copy assignment operator
    //ash_array2.print_arr(); 
    return 0;
}