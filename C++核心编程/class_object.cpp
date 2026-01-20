#include <iostream>
#include <string>
using namespace std;
const double PI = 3.14;
// 设计一个圆类 , 求圆的半径

class Circle
{
private:
    int r;

public:
    double calcutateZC()
    {
        return 2 * PI * r;
    };
    void setR(int &r)
    {
        this->r = r;
    };
    int getR()
    {
        return r;
    };
};

/**
 * 访问权限有三种:public protected private
 * struct 和 class 的区别
 * 1. struct的默认权限是public
 * 2. class的默认权限是private
 */
struct C2
{
    int a;
};
class Person
{
public:
    void SetName(string name){
        p_name= name;
    }
    string getName(){
        return this->p_name;
    }
    int getAge(){
        return p_age;
    }
    void setAge(int age){
        if(age<0||age>150){
            cout<<"输入需要在0-150之间"<<endl;
        }else{
            p_age=age;
        }
    }
    void set_IdoI(string name){
        p_IdoI = name;
    }
private:
    string p_name;

    int p_age=20;

    string p_IdoI;
};

main()
{
    int r = 10;
    Circle *p = new Circle;
    p->setR(r);
    double perimeter = p->calcutateZC();
    cout << "Value of perimeter :" << perimeter << endl;
    delete p;
    C2 c;
    c.a = 10;
    return 0;
}