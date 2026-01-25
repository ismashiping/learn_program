#include <iostream>

using namespace std;
template <class NameType, class AgeType= int>
class Person
{
public:
    Person(NameType name, AgeType age )
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void printPerson()
    {
        cout << "name: " << this->m_Name << "age: " << this->m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};

void test01()
{
    Person<string, int> p("孙悟空", 1000);
    p.printPerson();
}

void test02()
{
    Person<string> p("猪八戒", 1000);
    p.printPerson();
}
int main()
{
    test02();
    return 0;
}