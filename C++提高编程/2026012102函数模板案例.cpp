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
template<typename T>
void mySwap(T &a,T&b){
    T temp = a;
    a= b;
    b=temp;
}

int main() {
    double a= 1.1;
    double b =2.1; 
    mySwap<double>(a,b);
    cout<<a<<b<<endl;
    return 0;
}