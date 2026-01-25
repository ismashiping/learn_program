#include <iostream>

using namespace std;

void swapInt(int &a, int&b){
    int temp = a;
    a= b;
    b=temp;
}

void swapDouble(double &a, double&b){
    double temp = a;
    a= b;
    b=temp;
}
template<class T>
void mySwap(T &a,T&b){
    T temp = a;
    a= b;
    b=temp;
}
//自动类型推导要求数据类型一致 没有<double>
//模板必须确定T的数据类型 即使在函数定义的时候没有用到
int main() {
    double a= 1.1;
    double b =2.1; 
    mySwap<double>(a,b);
    cout<<a<<b<<endl;
    return 0;
}