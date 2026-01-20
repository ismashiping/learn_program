#include"manager.h"

Manager::Manager(int id,string name,int Iid)
    {
        this->m_Id=id;
        this->m_Name=name;
        this->m_DeptId=Iid;
    }
void Manager::showInfo(){
    cout<<"职工编号: "<<this->m_Id;
    cout<<"\t职工姓名: "<<this->m_Name;
    cout<<"\t岗位: "<<this->getDeptName();
    cout<<"\t 岗位职责: 指挥下属做任务"<<endl;
}
string Manager::getDeptName(){
    return string("经理");
}