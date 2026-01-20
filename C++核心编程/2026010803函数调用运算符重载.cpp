#include <iostream>
#include <string>
using namespace std;
//函数调用重载 ()仿函数 ()重载
class Myprint
{
private:
    /* data */
public:

    // ~Myprint();
    void operator()(string test){
        cout<<test<<endl;
    }
};

// 匿名函数对象
void test01(){
    Myprint myprint;
    myprint("hello world");
}
int main() {
    
    return 0;
}