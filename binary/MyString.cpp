#include "MyString.h"
using std::cin;
using std::cout;
using std::endl;
MyString::MyString(const char *str)
{
    if(str==nullptr){
        data=nullptr;
        return;
    }else{
        data =new char[strlen(str)+1];
        strcpy(data,str);
        data [strlen(str)]='\0';
    }
}

std::ostream & operator<<(std::ostream & os, const MyString & mystr)
{
// TODO: 在此处插入 return 语句
    os<<mystr.data;
    return os;
}

void test01(){
    MyString s1("hello world");
    cout<<s1<<endl;
}

MyString::~MyString(){
    if(data!=nullptr){
        delete [] data;
        data=nullptr;
    }
}

MyString::MyString(const MyString & mystr){
    if(mystr.data == nullptr){
        data =nullptr;
        return;
    }else{
        data =new char[strlen(mystr.data)+1];
        strcpy(data,mystr.data);
        data [strlen(mystr.data)]='\0';
    }
}