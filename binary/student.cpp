#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student.h"
using std::cout;
using std::endl;
using std::cin;
// 创建一个程序，管理学生的信息，包括添加、删除、显示和查找学生。每个学生包含ID、姓名和成绩。

void menu()
{
    int choice;
    std::vector<Student> stus;
    do{
    cout << "1.添加学生信息" << endl;
    cout << "2.删除学生信息" << endl;
    cout << "3.显示学生信息" << endl;
    cout << "4.查找学生信息" << endl;
    cout << "0.退出系统" << endl;
    cout << "请输入你的选择" << endl;
    
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "请输入学生的id:" << endl;
        int id;
        cin >> id;
        cout << "请输入学生的姓名" << endl;
        std::string name;
        cin >> name;
        cout << "请输入学生的成绩" << endl;
        float grade;
        cin >> grade;
        Student stu(id, name, grade);
        stus.push_back(stu);
        cout << "恭喜你,添加成功" << endl;
    }
    break;
    case 2:
    {
        cout << "请输入您要删除的id" << endl;
        int id;
        cin >> id;
        // for(auto stu:stus){
        //     if(stu.id==id){
        //         stus.erase(stu);
        //     }
        // }
        for (auto it = stus.begin(); it != stus.end(); it++)
        {
            if (it->getId() == id)
            {
                stus.erase(it);
                cout << "删除成功" << endl;
                break;
            }
        }
        cout << "删除失败" << endl;
    }
    break;
    case 3:
    {
        for (auto stu : stus)
        {
            stu.print(stu);
        }
    }
    break;
    case 4:
        {
            cout << "请输入您要查找的id" << endl;
            int id;
            cin >> id;
            for (auto stu : stus)
            {
                if (stu.getId() == id)
                {
                    stu.print(stu);
                    break;
                }
            }
        }
        break;
    case 0:
        break;
    }}while(choice!=0);
}

void Student::print(Student stu)
{
    cout << "id:" << stu.id << endl;
    cout << "name:" << stu.name << endl;
    cout << "grade:" << stu.grade << endl;
}
Student::Student(int id, std::string name, float grade)
{
    this->id = id;
    this->name = name;
    this->grade = grade;
}