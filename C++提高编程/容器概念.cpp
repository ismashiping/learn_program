#include <iostream>
#include <MyArray.hpp>
using namespace std;
#include <string>
#include <vector>

void myPrint(int val)
{
    cout << val << endl;
}
void test1()
{
    MyArray<int> arr(90);
    MyArray<int> arr2(arr);
    MyArray<int> arr3(arr);
    arr3 = arr;
};
// vector 容器内放置内置数据类型
void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    // 通过迭代器访问
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();
    while (itBegin != itEnd)
    {
        /* code */
        cout << *itBegin << endl;
        itBegin++;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    for_each(v.begin(), v.end(), myPrint);
};

class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
};
void test04()
{
    vector<Person> v;
    Person p1("wnag", 10);
    Person p2("bb", 10);
    Person p3("cg", 10);
    Person p4("nag", 10);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).m_Name << (*it).m_Age << endl;
    }
}
void test05()
{
    vector<Person *> v;
    Person p1("wnag", 10);
    Person p2("bb", 10);
    Person p3("cg", 10);
    Person p4("nag", 10);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it)->m_Name << (*it)->m_Age << endl;
    }
}
void test06()
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << endl;
        }
        cout << endl;
    }
}
int main()
{
    test02();
    test04();
    test05();
    test06();
    return 0;
}