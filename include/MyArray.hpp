#pragma once
#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
template <class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        cout<<"myarray的有参构造"<<endl;
        this->m_Capacity =capacity;
        this->m_Size=0;
        this->pAddress = new T[this->m_Capacity];
    }
    MyArray(const MyArray& arr){
        cout<<"myarray的拷贝构造"<<endl;
        this->m_Capacity =arr.m_Capacity;
        this->m_Size=arr.m_Size;
        this->pAddress= new T[arr.m_Capacity];
        for (int i=0;i<this->m_Size;i++){
            this->pAddress[i]=arr.pAddress[i];
        }
    }
    MyArray& operator=(const MyArray& arr){
        cout<<"myarray的opreator"<<endl;
        if(this->pAddress!=nullptr){
            delete [] this->pAddress;
            this->pAddress =NULL;
            this->m_Capacity = 0;
            this->m_Size=0;
        }
        this->m_Capacity =arr.m_Capacity;
        this->m_Size=arr.m_Size;
        this->pAddress= new T[arr.m_Capacity];
         for (int i=0;i<this->m_Size;i++){
            this->pAddress[i]=arr.pAddress[i];
        }
        return *this;
    }
    //尾插法
    void append(const T& val){
        if(this->m_Capacity ==this->m_Size){
            return;
        }
        this->pAddress[this->m_Size] =val;
        this->m_Size++;
    }
    void del(){
        if(this->m_Size==0){
            return;
        }
        this->m_Size--;
    }
    T& operator[](int index){
        return this->pAddress[index];
        
    };
    ~MyArray(){
        cout<<"myarray的析构"<<endl;
        if(this->pAddress!=nullptr){
            delete [] this->pAddress;
            this->pAddress =NULL;
        }
    };

private:
    T *pAddress; // 指针指向堆区开辟的真实数组;
    int m_Capacity;
    int m_Size;
};