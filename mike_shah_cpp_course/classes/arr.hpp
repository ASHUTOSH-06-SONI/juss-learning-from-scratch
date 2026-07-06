#include<vector>
class Array{
    public:
        Array();
        ~Array();
        Array(const Array& rhs);
        Array& operator=(const Array& rhs);
        void Printdata();
        void Set_Data(int index, int value);
    private:
        std::vector<int> data;
};