#include <iostream>

using namespace std;

class Person
{
public:
    static int m_A;
    static void func(){
        cout<<Person::m_B<<endl;
    }
private:
    static int m_B;
};
//静态变量也是有访问权限的
int Person::m_B=300;
int Person::m_A=100;
void test01(){
    Person p;
    cout<<p.m_A<<endl;
    Person p2;
    p2.m_A=200;
    cout<<p2.m_A<<endl;
    cout<<Person::m_A<<endl;
    Person::func();
}
int main()
{
    test01();
    return 0;
}