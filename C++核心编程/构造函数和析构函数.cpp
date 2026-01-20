#include <iostream>
#include <string>
using namespace std;
//括号法 无参 (默认构造)  有参 拷贝构造
// 无参 (默认构造) 不要加括号 因为加上括号后 编译器会认为这是函数的声明

//显示法 匿名对象 Person(10) 不要利用拷贝构造函数初始化一个匿名对象 Person (p3)== Person p3

//隐式转换法  Person p4 =10  == Person p4 = Person(10)
class Person{
    public:
    Person(){
        cout<<"调用构造函数"<<endl;

    }
    Person(int age){
        this->age=age;
        cout<<"调用有参构造函数"<<endl;
    }
    Person(const Person & p){
        this->age=p.age;
        cout<<"调用拷贝构造函数"<<endl;
    }
    ~Person(){
        cout<<"调用析构函数"<<endl;

    }
    int age;
};

void test01(){
    Person p1(20);
    Person p2(p1);
}

void dowork(Person p){

}
Person dowork2(){
    Person p1;
    cout<<(int*)&p1<<endl;
    return Person (p1);
}
void test02(){
    // Person p;
    Person p2= dowork2();
    cout<<(int*)&p2<<endl;
    
}
int main() {
    Person p;
    test02();
    return 0;
}