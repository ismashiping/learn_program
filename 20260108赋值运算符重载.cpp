#include <iostream>

using namespace std;
// 赋值运算符的重载

class Person
{
private:
    /* data */
public:
    Person(int age);
    
    int * m_Age;
    ~Person();
    Person& operator=(Person &p){
        if(m_Age !=NULL){
            delete m_Age;
            m_Age =NULL;
        };
        m_Age= new int(*p.m_Age);
        return *this;
    }
};

Person::Person(int age)
{
        m_Age = new int(age);
    };
Person::~Person()
{
    if(m_Age!=NULL){
        delete m_Age;
        m_Age=NULL;
        // return 0;
    }
    cout<<"对象销毁"<<endl;
}

int main() {
    Person p1(18);
    Person p2(20);
    p2=p1;  //这里是浅拷贝.
    cout<<"p1的年龄: "<<*p1.m_Age<<endl;
    cout<<"p2的年龄: "<<*p2.m_Age<<endl;
    return 0;
}