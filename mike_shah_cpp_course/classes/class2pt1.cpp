#include<iostream>
class Array{
    public:
        Array(){
            data = new int[10];
            for(int i =0; i<10; i++){
                data[i]=i*i;
            }
        }
        ~Array(){
            delete[] data;
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
    ash_array.set_Data(1,21);
    ash_array.set_Data(2,5);
    ash_array.print_arr();
    Array ash_array2 = ash_array;  
    /*
    the trace trap shows up because, i deleted ash_array and i copied its contents to ash_array2
    a.data and b.data would contain the same pointer in the heap memory
    when they both die, the destructor runs twice, so this results in memory being double free'd 
    */
   ash_array2.print_arr(); 
    return 0;
}