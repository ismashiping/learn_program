#pragma once
#include<iostream>
using namespace std;
#include <string>

class Worker{
    public:
    //显示个人信息
    virtual void showInfo()= 0;
    virtual string getDeptName()=0;
    int m_Id;
    string m_Name;
    int m_DeptId;
};