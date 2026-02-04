#include <iostream>

using namespace std;
#include <string>
//字符串初始化
void test01()
{
    string s1;
    const char *str = "hello world";
    string s2 = (str);
    cout << "s2 = " << s2 << endl;
    string s3(s2);
    cout << "s3 = " << s3 << endl;
    string s4(10, 'c');
    cout << s4 << endl;
}
//字符串赋值
void test02(){
    string str1;
    str1 ="hello world";
    cout<<str1<<endl;
    string str2=str1;
    cout<<str2<<endl;
    string str3;
    str3='a';
    cout<<str3<<endl;

    string str4;
    str4.assign("hello world");
    cout<<str4<<endl;
    string str5;
    str5.assign("hello world",5);
    cout<<str5<<endl;
    string str6;
    str6.assign(5,'c');
    cout<<str6<<endl;

    string str7;
    str7.assign(str5);
    cout<<str7<<endl;
}

//字符串拼接
void test03(){
    string str1="我";
    str1+="爱玩游戏";
    cout<<str1<<endl;
    str1+=':';
    cout<<str1<<endl;
    string str2 ="LOL";
    str1+=str2;
    cout<<str1<<endl;
    string str3 ="I";
    str3.append(" love");
    cout<<str3<<endl;
    str3.append("LOL advd",4);
    cout<<str3<<endl;
    string str4 = "DNF";
    str3.append(str4);
    cout<<str3<<endl;
    str3.append(str4,2,1);
    cout<<str3<<endl;
}

//查找 和 替换

//1.查找
//find refind 



int main()
{
    test01();
    test02();
    test03();
    return 0;
}