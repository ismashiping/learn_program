#include <iostream>
#include <fstream>
using namespace std;
//二进制文件  写文件

class Person{
    public:
    char m_Name[64];
    int m_Age;
};

int main() {
    ofstream ofs("person.txt",ios::out|ios::binary);
    Person p = {"张三",18};
    ofs.write((const char *)&p ,sizeof(Person));
    ofs.close();

    ifstream ifs("person.txt",ios::in|ios::binary);
    while (!ifs.is_open())
    {
        /* code */
        cout<<"路径有问题"<<endl;
    }
    Person p2;
    ifs.read((char *)&p2,sizeof(Person));
    cout<<"姓名: "<<p2.m_Name<<"年龄: "<<p2.m_Age<<endl;
    ifs.close();
    return 0;
}