#include <iostream>

using namespace std;
const double PI =3.14;
//设计一个圆类 , 求圆的半径

class Circle{
    private:
        int r;
    public:
    double calcutateZC(){
        return 2*PI* r;
    };
    void setR(int & r){
        this->r=r;
    };
    int getR(){
        return r;
    };
};
int main() {
    int r =10;
    Circle * p = new Circle;
    p->setR(r);
    double perimeter=p->calcutateZC();
    cout<<"Value of perimeter :"<<perimeter<<endl;
    delete p;
    return 0;
}