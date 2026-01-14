#include <iostream>

using namespace std;
/**
 * 父类引用指向子类调用
 */

 /**
  * 1.多态的基本语法 在子类中重写父类的虚函数
  * 动态多态需要满足的条件:
  * 1. 继承父类
  * 2. 重写父类中的虚函数 重写 函数名以及参数相同叫做重写
  *
  */
/**
 * 父类中虚函数指针  指向vftable 这个表中记录了一个虚函数的地址 eg:&Animal::speak
 * 子类进行继承 子类重写父类中的虚函数 子类中的虚函数表会替换成子类的虚函数地址
 */
class Animal
{

public:
    virtual void speak(){
        cout<<"动物在说话"<<endl;
    };
};


class Cat : public Animal
{
public:
    void speak(){
        cout<<"猫在说话"<<endl;
    }
};
class Dog: public Animal{
    public:
    void speak(){
    cout<<"狗在说话"<<endl;
}
};
void toSpeak(Animal &animal){
    animal.speak();
};
void test01(){
    Dog dog;
    toSpeak(dog);
}
int main() {
    test01();
    return 0;
}