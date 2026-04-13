#pragma once
#include <string>
class Student
{
private:
    int id;
    std::string name;
    float grade;

public:
    Student(int id, std::string name, float grade);
    void print(Student stu);
    int getId() const
    {
        return id;
    }
};
void menu();