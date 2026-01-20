#include <iostream>

using namespace std;

//构造函数的调用规则
//1. 创建一个类 ,C++ 编译器会给每个类都添加至少三个函数 默认构造 默认析构 默认拷贝构造 
// 写了有参构造 那么编译器不提供默认构造 ,写了拷贝构造 那么编译器不提供 默认构造 有参构造
class Person {
    public:
    Person(){
        cout<<"Person的默认构造"<<endl;

    }
    Person(int age){
        this->m_age=age;
         cout<<"Person的默认析构"<<endl;
    }
    ~Person(){
        cout<<"Person的默认析构"<<endl;

    }
    Person (const Person & p){
        this->m_age=p.m_age;
         cout<<"Person的默认拷贝函数"<<endl;
    }
    int m_age;
};
void test01(){
     Person p;
    p.m_age=18;
    Person p2(p);
    cout<<"p2的年龄是 "<<p2.m_age<<endl;
}
int main() {
    // Person p;
    // p.m_age=18;
    // Person p2(p);
    // cout<<"p2的年龄是 "<<p2.m_age<<endl;
    test01();
    return 0;
}