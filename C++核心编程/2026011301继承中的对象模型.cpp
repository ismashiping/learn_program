#include <iostream>

using namespace std;


class Base{
    public:
    int m_A;
    protected:
    int m_B;
    private:
    int m_C;

};
//继承是将所有的成员继承下去了,只不过子类部分成员是访问不到的 
class Son : public Base{
    public:
    int m_D;
};
int main() {
    Son son;
    cout<<sizeof(son)<<endl; // 输出是16;
    return 0;
}