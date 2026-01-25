#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class Manager :public Worker{
    public:
    Manager(int id,string name,int Iid);
    //显示个人信息
    virtual void showInfo();
    virtual string getDeptName();
};