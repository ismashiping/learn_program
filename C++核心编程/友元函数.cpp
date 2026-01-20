#include <iostream>

using namespace std;
//建筑物类
class Building{
    friend class GoodGay;
    friend void goodGay(Building *building);
    public: 
        Building(){
            m_BedRoom="卧室";
            m_SittingRoom="客厅";
        }
        string m_SittingRoom;
    private:
        string m_BedRoom;

};

class GoodGay{
    public:
        void visit();
    Building * building;
};
void GoodGay::visit()
{
    cout<<"正在访问"<<building->m_SittingRoom<<endl;
    cout<<"正在访问"<<building->m_BedRoom<<endl;
};
// 全局函数
void goodGay(Building *building){
    cout <<"好基友全局函数 正在访问..."<<building->m_SittingRoom<<endl;
    cout <<"好基友全局函数 正在访问..."<<building->m_BedRoom<<endl;
};
int main() {
    Building building;
    goodGay(&building);
    return 0;
}