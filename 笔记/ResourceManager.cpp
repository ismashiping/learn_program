#include "ResourceManager.h"
#include <iostream>
ResourceManager::ResourceManager(int *resource): m_resource(resource)
{   
}
int ResourceManager::getValue() const{
    return *m_resource;
}
void ResourceManager::setValue(int newValue){
    int*  ptr =m_resource.get();
    *ptr = newValue;
}

// ================= 测试函数 =================
void testUniquePtr() {
    ResourceManager rm(new int(10));

    std::cout << "初始值: " << rm.getValue() << std::endl;

    rm.setValue(99);
    std::cout << "修改后: " << rm.getValue() << std::endl;

    // ❌ 编译错误示例（取消注释会报错）
    // ResourceManager rm2 = rm;

    std::cout << "拷贝被正确禁止（取消注释会编译失败）" << std::endl;
}