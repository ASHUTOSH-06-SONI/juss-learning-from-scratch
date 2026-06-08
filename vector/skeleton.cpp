// juss the memory layout of vector
#include<iostream>
#include<new>
template <typename T>
class khudkavector{
    private:
        T* data;
        size_t size_;
        size_t capacity_;;
    public:
        khudkavector() : data(nullptr), size_(0), capacity_(0){
            std::cout<<"Vector constructed"<<'\n';
        }
        ~khudkavector(){
            for(size_t i=0; i< size_;i++){
                data[i].~T(); // destroying constructed elements
            }
            operator delete(data); // also free raw memory
            std::cout<<"Vector destroyed"<<'\n';
        }
        size_t size() const{
            return size_;
        }
        size_t capacity() const{
            return capacity_;
        }
        T& operator[](size_t index){
            return data[index];
        }
        const T& operator[](size_t index) const{
            return data[index];
        }

        void push_back(const T& value){
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        new (data + size_) T(value);  // placement new
        size_++;
        }
        void reserve(size_t new_cap){
            T* new_data = static_cast<T*>(operator new(sizeof(T) * new_cap));
            for(size_t i =0; i<size_; i++){
                new(new_data+i ) T(std::move(data[i]));
                data[i].~T(); 
            }
            operator delete(data);
            data = new_data;
            capacity_ = new_cap;
        }
        void pop_back(){
            if(size_==0) return;
            size_--;
            data[size_].~T();  // this is what basically destroys the last ka element
        }
};

int main() {
    khudkavector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    std::cout<<"Indexing and seeing stuff happen lol "<<v[1]<<"\n";
    std::cout<<"Size: "<<v.size()<<'\n';
    std::cout<<"Capacity: "<<v.capacity()<<'\n';
    v.pop_back();
    std::cout<<"Updated Size: "<<v.size()<<'\n';
}