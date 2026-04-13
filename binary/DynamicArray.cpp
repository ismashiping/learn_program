#include "DynamicArray.h"

DynamicArray::DynamicArray(std::size_t size, std::size_t capacity, int *data)
    : _size(size), _capacity(capacity), _data((int *)malloc(capacity * sizeof(int)))
{
    if (data == nullptr)
    {
        throw std::bad_alloc();
    }
}

DynamicArray::~DynamicArray()
{
    free(_data);
}

void DynamicArray::resize(std::size_t new_size)
{
    int *temp = (int *)realloc(_data, new_size * sizeof(int));
    if (temp == nullptr)
    {
        throw std::bad_alloc();
    }
    _data = temp;
    _capacity = new_size;
}

int &DynamicArray::operator[](std::size_t index)
{
    // TODO: 在此处插入 return 语句
    if (index >= _size)
    {
        throw std::out_of_range("Index out of range");
    }
    return _data[index];
}

std::size_t DynamicArray::getSize() const
{
    return _size;
}
void DynamicArray::add(int value)
{
    if (_size == _capacity)
    {
        resize(_capacity * 2);
    }
    _data[_size++] = value;
}

void test()
{
    DynamicArray arr;
    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(3);
    arr.add(3);
    arr.add(3);
    arr.add(3);
    std::cout << "Array size: " << arr.getSize() << std::endl;
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        std::cout << arr[i] << " ";
    }
}

void test02(){
    int *p =(int *)malloc(sizeof(int)); //malloc 放回的是 void * 所以需要强转
    *p = 10;
    std::cout<<*p<<std::endl;
    free(p);

}