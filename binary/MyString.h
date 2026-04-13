#include <iostream>
#include <cstring>


class MyString{
    public:
    //默认构造
    MyString():data(nullptr){};

    //有参构造
    MyString(const char * str);

    MyString(const MyString & mystr);
    friend std::ostream& operator<<(std::ostream& os,const MyString& mystr);
    ~MyString();

    private: 
    char * data;

};

void test01();