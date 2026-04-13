#include <iostream>

#include <cstdlib> // for std::size_t
#include <cstring> // for std::memcpy 

class DynamicArray {
public:
    DynamicArray():_size(0), _capacity(3), _data((int*)malloc(_capacity * sizeof(int))){};
    DynamicArray(std::size_t size, std::size_t capacity,int * data);
    ~DynamicArray();
    int& operator[](std::size_t index);
    std::size_t getSize() const;
    void add(int value) ;
private:
    std::size_t _size;
    std::size_t _capacity;
    int * _data;
    void resize(std::size_t new_size);
};
void test();