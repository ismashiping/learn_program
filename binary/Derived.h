#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Base
{
public:
    Base(): privateNum(0), protectedNum(0){
        // cout<<"基类无参构造函数"<<endl;
    }
    Base(int privateNum, int protectedNum) : privateNum(privateNum), protectedNum(protectedNum) {
        // cout<<"基类有参构造函数"<<endl;
    }
    ~Base(){
    }
    void baseFunc() {
        std::cout<<"baseFunc"<<std::endl;
        std::cout<<"privateNum: "<<privateNum<<std::endl;
        std::cout<<"protectedNum: "<<protectedNum<<std::endl;
    }
    virtual void display(){
        std::cout << "Base display" << std::endl;
    };
private:
    int privateNum;

protected:
    int protectedNum;
};
class Derived : public Base
{
    public:
    Derived():Base(){
        // cout<<"子类无参构造函数"<<endl;
    }
    Derived(int num1,int num2):Base(num1,num2){
        //   cout<<"子类有参构造函数"<<endl;
    }
    ~Derived(){
    }
    void display() override; 
    void derivedFunc() {
        std::cout<<"derivedFunc"<<std::endl;
        // std::cout<<"privateNum: "<<privateNum<<std::endl;
        std::cout<<"protectedNum: "<<protectedNum<<std::endl;
    }

    void callBaseDisplay(){
        Base::display();
    }
};