#include <iostream>

using namespace std;
//成员变量 和 成员函数 分开存储
//只有非静态成员变量才属于 对象!!!

class Person {

};
class Person2 {
    int a;

    static int m_B;

    void func(){
        
    }
};

void test01(){
    Person p;
    //空对象会给每个空对象也分配一个字节空间 ,
    //是为了区分空对象所以占内存的位置 即 每个空对象也要一个独一无二的内存地址;
    cout<<"size of p = "<<sizeof(p)<<endl;
    // int 占四个字节
    Person2 p2;
    cout<<"size of p2 = "<<sizeof(p2)<<endl;
    
}
int main() {
    test01();
    return 0;
}