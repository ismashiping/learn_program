#include"boss.h"

Boss::Boss(int id,string name,int Iid)
    {
        this->m_Id=id;
        this->m_Name=name;
        this->m_DeptId=Iid;
    }
void Boss::showInfo(){
    cout<<"职工编号: "<<this->m_Id;
    cout<<"\t职工姓名: "<<this->m_Name;
    cout<<"\t岗位: "<<this->getDeptName();
    cout<<"\t 岗位职责: 提供资金支持"<<endl;
}
string Boss::getDeptName(){
    return string("老板");
}