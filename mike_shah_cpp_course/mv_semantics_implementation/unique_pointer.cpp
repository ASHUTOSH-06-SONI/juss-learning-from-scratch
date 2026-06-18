#include <iostream>
#include <utility> 

template <typename T>
class unique_ptr {
public:
// feature 1- cleaning up owned memory safely 
    explicit unique_ptr(T* ptr = nullptr) noexcept : ptr_(ptr) {}
    ~unique_ptr() noexcept {
        reset(); 
    }

    // feature 2- disable the copying part to mainting a unique ownership
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // feature 3- not exactly copying but moving, mainly to transfer ownership
    unique_ptr(unique_ptr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr; // Leave old object empty
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            reset(other.ptr_);   
            other.ptr_ = nullptr; 
        }
        return *this;
    }

    // feat 4- observers and accessors
    T* get() const noexcept { return ptr_; }
    
    T& operator*() const noexcept { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }
    
    explicit operator bool() const noexcept { return ptr_ != nullptr; }

    //  feat 5- modifiers
    T* release() noexcept {
        T* temp = ptr_;
        ptr_ = nullptr; // no need to delete stuff 
        return temp;
    }
// reset existing resources and store the new ptr
    void reset(T* ptr = nullptr) noexcept {
        delete ptr_; 
        ptr_ = ptr;  
    }

private:
    T* ptr_ = nullptr; 
};
