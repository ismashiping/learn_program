// #include "SimpleSharePtr.h"
// #include <iostream>

// SimpleSharePtr::SimpleSharePtr() : m_ptr(nullptr), m_controlBlock(nullptr)
// {
// }
// // 有参构造
// SimpleSharePtr::SimpleSharePtr(T *ptr)
// {
//     if(ptr==nullptr){
//         m_ptr = nullptr;
//         m_controlBlock = nullptr;
//     }else{
//         m_ptr = ptr;
//         m_controlBlock = new ControlBlock();
//         m_controlBlock->ref_count = 1;
//     }
// }
// // 拷贝构造
// SimpleSharePtr::SimpleSharePtr(const SimpleSharePtr &ptr){
//     if(ptr.m_ptr==nullptr){
//         m_ptr = nullptr;
//         m_controlBlock = nullptr;
//     }else{
//         m_ptr = ptr.m_ptr;
//         m_controlBlock = ptr.m_controlBlock;
//         m_controlBlock->ref_count++;
//     }
// }
// // 移动构造
// SimpleSharePtr::SimpleSharePtr(SimpleSharePtr &&ptr){
//     if(ptr.m_ptr==nullptr){
//         m_ptr = nullptr;
//         m_controlBlock = nullptr;
//     }else{
//         release();
//         m_ptr = ptr.m_ptr;
//         m_controlBlock = ptr.m_controlBlock;
//         ptr.m_ptr = nullptr;
//         ptr.m_controlBlock = nullptr;
//     }
// }
// // 拷贝赋值
// SimpleSharePtr& SimpleSharePtr::operator=(const SimpleSharePtr &ptr){
//     if(this==&ptr){
//         return *this;
//     }
//     release();
//     if(ptr.m_ptr==nullptr){
//         m_ptr = nullptr;
//         m_controlBlock = nullptr;
//     }else{
//         m_ptr = ptr.m_ptr;
//         m_controlBlock = ptr.m_controlBlock;
//         m_controlBlock->ref_count++;
//     }
//     return *this;
// }
// // 移动赋值
// SimpleSharePtr SimpleSharePtr::&operator=(SimpleSharePtr &&ptr){
//      if(this==&ptr){
//         return *this;
//     }
//     release();
//     if(ptr.m_ptr==nullptr){
//         m_ptr = nullptr;
//         m_controlBlock = nullptr;
//     }else{
//         m_ptr=ptr.m_ptr;
//         m_controlBlock = ptr.m_controlBlock;
//         ptr.m_ptr = nullptr;
//         ptr.m_controlBlock = nullptr;
//         // ptr.m_controlBlock = nullptr;
//     }
//     return *this;
// }
// T SimpleSharePtr::&operator*() const{
//     return *m_ptr;
// }
// // 箭头操作符
// T SimpleSharePtr::*operator->() const{
//     return m_ptr;
// }
// // 获取裸指针
// T SimpleSharePtr::*get() const{
//     return m_ptr;
// }
// // 获取引用计数
// int SimpleSharePtr::use_count() const{
//     return m_controlBlock ? m_controlBlock->ref_count : 0;
// }
// // 重置
// void SimpleSharePtr::reset(T *ptr = nullptr){
//     release();
//     if(ptr!=nullptr){
//         m_ptr = ptr;
//         m_controlBlock = new ControlBlock();
//         m_controlBlock->ref_count = 1;
//     }   
// }




// void SimpleSharePtr::release(){
//     if(m_controlBlock!=nullptr){
//         m_controlBlock->ref_count--;
//         if(m_controlBlock->ref_count==0){
//             delete m_ptr;
//             delete m_controlBlock;
//         }
//     }
// }
// SimpleSharePtr::~SimpleSharePtr(){
//     release();
// }









#include "SimpleSharePtr.h"

// 无参构造
template <typename T>
SimpleSharePtr<T>::SimpleSharePtr() : m_ptr(nullptr), m_controlBlock(nullptr) {}

// 有参构造
template <typename T>
SimpleSharePtr<T>::SimpleSharePtr(T* ptr) {
    if (ptr == nullptr) {
        m_ptr = nullptr;
        m_controlBlock = nullptr;
    } else {
        m_ptr = ptr;
        m_controlBlock = new ControlBlock();
        m_controlBlock->ref_count = 1;
    }
}

// 拷贝构造
template <typename T>
SimpleSharePtr<T>::SimpleSharePtr(const SimpleSharePtr& ptr) {
    m_ptr = ptr.m_ptr;
    m_controlBlock = ptr.m_controlBlock;
    if (m_controlBlock) {
        m_controlBlock->ref_count++;
    }
}

// 移动构造
template <typename T>
SimpleSharePtr<T>::SimpleSharePtr(SimpleSharePtr&& ptr) {
    m_ptr = ptr.m_ptr;
    m_controlBlock = ptr.m_controlBlock;

    ptr.m_ptr = nullptr;
    ptr.m_controlBlock = nullptr;
}

// 拷贝赋值
template <typename T>
SimpleSharePtr<T> SimpleSharePtr<T>::operator=(const SimpleSharePtr& ptr) {
    if (this == &ptr) return *this;

    release();

    m_ptr = ptr.m_ptr;
    m_controlBlock = ptr.m_controlBlock;

    if (m_controlBlock) {
        m_controlBlock->ref_count++;
    }

    return *this;
}

// 移动赋值
template <typename T>
SimpleSharePtr<T>& SimpleSharePtr<T>::operator=(SimpleSharePtr&& ptr) {
    if (this == &ptr) return *this;

    release();

    m_ptr = ptr.m_ptr;
    m_controlBlock = ptr.m_controlBlock;

    ptr.m_ptr = nullptr;
    ptr.m_controlBlock = nullptr;

    return *this;
}

// 解引用
template <typename T>
T& SimpleSharePtr<T>::operator*() const {
    return *m_ptr;
}

// 箭头操作符
template <typename T>
T* SimpleSharePtr<T>::operator->() const {
    return m_ptr;
}

// 获取裸指针
template <typename T>
T* SimpleSharePtr<T>::get() const {
    return m_ptr;
}

// 引用计数
template <typename T>
int SimpleSharePtr<T>::use_count() const {
    return m_controlBlock ? m_controlBlock->ref_count : 0;
}

// 重置
template <typename T>
void SimpleSharePtr<T>::reset(T* ptr) {
    release();
    if (ptr) {
        m_ptr = ptr;
        m_controlBlock = new ControlBlock();
        m_controlBlock->ref_count = 1;
    } else {
        m_ptr = nullptr;
        m_controlBlock = nullptr;
    }
}

// 释放
template <typename T>
void SimpleSharePtr<T>::release() {
    if (m_controlBlock) {
        m_controlBlock->ref_count--;
        if (m_controlBlock->ref_count == 0) {
            delete m_ptr;
            delete m_controlBlock;
        }
    }
}

// 析构
template <typename T>
SimpleSharePtr<T>::~SimpleSharePtr() {
    release();
}


// #include "SimpleSharePtr.h"
#include <iostream>

void testSimpleSharePtr() {
    SimpleSharePtr<int> p1(new int(10));
    std::cout << "p1: " << *p1 << ", count=" << p1.use_count() << std::endl;

    SimpleSharePtr<int> p2 = p1;
    std::cout << "p2 copy, count=" << p1.use_count() << std::endl;

    SimpleSharePtr<int> p3 = std::move(p2);
    std::cout << "p3 move, count=" << p1.use_count() << std::endl;
}