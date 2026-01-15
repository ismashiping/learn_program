#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream fst;
    fst.open("text.py",ios::out);
    fst<<"姓名:张三"<<endl;
    fst<<"姓名:张三"<<endl;
    fst.close();
    ifstream ifst;
    ifst.open("text.py",ios::in);
    if(!ifst.is_open()){
        cout<<"文件打开失败"<<endl;
        return 0;
    }
    //第一种方法
    // char buf[1024]={0};
    // while(ifst>>buf){
    //     cout<<buf<<endl;
    // }
    //第二种方法
    // char buf [1024]= {0};
    // while (ifst.getline(buf,sizeof(buf)))
    // {
    //     cout<<buf<<endl;
    // }
    // string buf;
    // while(getline(ifst,buf)){
    //     cout<<buf<<endl;
    // };
    char c;
    while ((c=ifst.get()!=EOF)){
        cout<<c;
    }
    ifst.close();
    return 0;
}