#include <iostream>

using namespace std;

//定义一个新的基础类型
class MyInteger{
    friend ostream& operator<<(ostream& os,const MyInteger& myint);  //友元函数或者getter
    public:
    MyInteger(){
        m_Number=0;
    }
    MyInteger& operator++(){
        m_Number++;
        return *this;
    }
    MyInteger operator++(int){
       MyInteger temp;
       temp.m_Number=m_Number;
       m_Number++;
        return temp;
    }
    private:
    int m_Number;

};
// 重载左运算符
ostream& operator<<(ostream& os,const MyInteger& myint){
    os<<myint.m_Number;
    return os;
}
// 前置的++运算 

//后置的++运算符
// MyInteger operatoer+(){

// }

int main() {
    MyInteger myint;
    cout<<myint++<<endl;
    cout<<++myint<<endl;
    return 0;
}