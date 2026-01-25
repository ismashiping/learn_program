#include <iostream>
#include"workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main() {
    WorkerManager wm;
    // Worker *wk = new Employee(1,"张三",1);
    // wk->showInfo();
    // delete wk;


    // Worker *wk2 = new Manager(2,"李四",1);
    // wk->showInfo();
    // delete wk2;
    // Worker *wk3 = new Boss(3,"王五",1);
    // wk->showInfo();
    // delete wk3;



    int choice=0;
    while (choice>-1)
    {
            /* code */
        wm.Show_Menu();
        cout<<"请输入您的选择: "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0: 
            /* 退出 */
            wm.exitSystem();
            break;
        case 1:
            /* 新增 */
            // cout<<"请选择要添加的员工类型: "<<endl;
            wm.Add_Emp();
            break;
        case 2:
            /* 显示 */
            wm.Show_Emp();
            break;
        case 3:
            /* 删除 */
            // {int x=wm.IsExist(6);
            // cout<<x<<endl;}
            wm.Del_Emp();
            break;
        case 4:
            /* 修改 */
            break;
        case 5:
            /* 查找 */
            break;
        case 6:
            /* 排序 */
            break;
        case 7:
            /* 清空 */
            break;
        
        default:
            break;
        }
    }
    
    
    wm.Show_Menu();

    return 0;
}
