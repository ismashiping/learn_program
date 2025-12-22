#include<iostream>

using namespace std;
// 函数重载的注意事项
//1.引用作为重载的条件
void fun(int &a){
    cout<<"func(int &a)调用"<<endl;
}

void fun(const int &a){
    //这里的const防止在使用过程中函数里对变量进行更改
    cout<<"func(const int &a)调用"<<endl;
}
int main(){
    int a =10;
    fun(a);
    fun(10);
    system("pause");
}