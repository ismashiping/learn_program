#include <iostream>

using namespace std;

//常函数
//常对象
//this 指针的本质 指针常量 指针常量的指向是不可以修改的
//在成员函数后加的const ,修饰的是this指向 ,让指针指向的值也不能修改
class Person{
    public:
     void showPerson() const{
        // m_A = 100;  //等同于 this->m_A = 100;
        m_B=100;
     }
     void func(){};
     int m_A;
     mutable int m_B;
};
int main() {
    const Person p;
    p.m_B=100;
    p.showPerson();
    p.func(); //常函数只能调用常函数,不能调用普通函数
    return 0;
}
