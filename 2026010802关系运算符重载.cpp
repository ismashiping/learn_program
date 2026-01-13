#include <iostream>
#include<string>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(string name,int age):m_Name(name),m_Age(age){};
    ~Person();
    string m_Name;
    int m_Age;
    //      布尔类型   

    bool operator==(const Person &p){
        if(this->m_Age= p.m_Age){
            return true;
        }
        return false;
    }
};



Person::~Person()
{
}

int main() {
    Person p1("Tom",18);
    Person p2("Tim",17);
    if(p1==p2){
        cout<<"两人年纪相等"<<endl;
    }
    return 0;
}