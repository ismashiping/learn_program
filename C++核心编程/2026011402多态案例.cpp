#include <iostream>

using namespace std;
class Calculator{
    public:
    int getResult(string oper){
        if(oper == "+"){
            return m_Num1+m_Num2;
        }else if (oper =="-")
        {
            return m_Num1-m_Num2;
        }else if (oper =="*")
        {
            return m_Num1*m_Num2;
        }else if(oper =="/")
        {
            return m_Num1/m_Num2;
        }return 0;
    };
    int m_Num1;
    int m_Num2;
};

class AbstractCalculator{
    public:
    int m_A;
    int m_B;
    virtual int getResult()=0;
    virtual ~AbstractCalculator() {};
};
class AddCalculator:public AbstractCalculator{
    public:
    int getResult(){
        return m_A+m_B;
    }
};


class SubCalculator:public AbstractCalculator{
    public:
    int getResult(){
        return m_A-m_B;
    }
};
int main() {
    Calculator cal ;
    cal.m_Num1=10;
    cal.m_Num2=20;
    cout<<cal.getResult("+")<<endl;
    cout<<cal.getResult("-")<<endl;
    cout<<cal.getResult("*")<<endl;
    cout<<cal.getResult("/")<<endl;

    AbstractCalculator * p=new AddCalculator;
    p->m_A=100;
    p->m_B=200;
    cout<<p->getResult()<<endl;
    delete p;
    AbstractCalculator *p2=new SubCalculator;
    p2->m_A=100;
    p2->m_B=200;
    cout<<p2->getResult()<<endl;
    delete p2;
    return 0;
}