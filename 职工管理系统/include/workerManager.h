#pragma once //防止头文件重复
#include <iostream>
#include"worker.h"
using namespace std;
#include <fstream>
#define FILENAME "empFIle.txt"
class WorkerManager{
    public:
        WorkerManager();
        ~WorkerManager();
        void Show_Menu();
        void exitSystem();

        //记录职工人数
        int m_EmpNum;
        //数组指针
        Worker ** m_EmpArray;
        //添加职工功能
        void Add_Emp();
        void save();
        //检测文件是否为空
        bool m_FileIsEmpty;
        int get_EmpNum();
        void init_Emp();
        void Show_Emp();
        void Del_Emp();
        int IsExist(int id);
};
