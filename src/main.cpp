#include<iostream>
#include <unordered_map>
using namespace std;
int main(){
    std::unordered_map<std::string,int> map;
    std::unordered_map<std::string,int> umap = {{"a",1},{"b",2},{"c",3}};
    std::unordered_map<std::string, int > umpa_from_map(umap);
    std::unordered_map<std::string, int > umpa_from_map2(umap.begin(),umap.end());
    auto x  = umap["a"];
    std::cout<<x<<std::endl;
    auto y  = umap["x"]; //不存在的key 会插入  
    std::cout<<x<<std::endl;
    auto x1 = umap.count("y");
    std::cout<<x1<<std::endl;
     string s;
    //从输入流写入s
    cin >> s;
    //将s写入输出流
    cout << s << endl;
    //循环读取，直到遇到换行符或者非法输入
    string world;
    // while (cin >> world)
    //     cout << world << endl;
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// ia2是一个整数型指针，指向ia第一个元素
    auto ia2(ia);
    //读取一整行
    // string linestr;
    // while (getline(cin, linestr))
    // {
    //     cout << linestr << endl;
    // }

    // //每次读入一整行，遇到空行跳过
    // while (getline(cin, linestr))
    // {
    //     if (!linestr.empty())
    //     {
    //         cout << linestr << endl;
    //         //打印字符串长度
    //         cout << linestr.size() << endl;
    //         // size()返回string::size_type类型的数据
    //         string::size_type size = linestr.size();
    //     }
    // }

    // // 比较
    // string str1 = "Hello";
    // string str2 = "Hello W";
    // string str3 = "Za";
    // //依次比较每个字符，字符大的字符串就大
    // auto b2 = str3 > str1;
    // cout << b2 << endl;
    // //前面字符相同，长度长的字符串大
    // auto b = str2 > str1;
    // cout << b << endl;
    return 0;
}