#include <iostream>

using namespace std;
class Base{
    public:
    void func(){
        cout<<"父亲"<<endl;
    };
     void func(int a){
        cout<<"父亲"<<endl;
    };
    Base(){
        m_A=100;
    }
    int m_A;
};
class Son: public Base{
    public:
    int m_A;

    Son(){
        m_A=200;
    }
    void func(){
        cout<<"儿子"<<endl;
    };
};
int main() {
    Son s;
    int a=100;
    cout<<s.m_A<< s.Base::m_A<<endl;
    s.func();
    s.Base::func(a);
    return 0;
}