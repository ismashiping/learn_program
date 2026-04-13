#include "MemoryPool.h"

MemoryPool::MemoryPool(size_t objsize, size_t poolsize) : objSize(objsize), poolSize(poolsize), pool((char *)malloc(objSize * poolSize))
{
    if (pool == nullptr)
    {
        throw std::bad_alloc();
    }
    for (size_t i = 0; i < poolSize; i++)
    {
        freeList.push(pool + i * objSize);
    }
}

MemoryPool::~MemoryPool()
{
    free(pool);
}

char *MemoryPool::alloc()
{
    if (!freeList.empty())
    {
        char *p = freeList.top();
        freeList.pop();
        return p;
    }
    throw std::bad_alloc();
}

void MemoryPool::disalloc(char *p)
{
    freeList.push(p);
}


int test2(){

    try{
            MemoryPool mp(sizeof(PoolStudent),2);
    char * stu1 =mp.alloc();
    char * stu2 =mp.alloc();
    char * stu3 =mp.alloc();
    PoolStudent * s1 = new (stu1) PoolStudent(1,"zhangsan");
    PoolStudent * s2 = new (stu2) PoolStudent(2,"zhangsan");
    PoolStudent * s3 = new (stu3) PoolStudent(2,"zhangsan");
    s1->~PoolStudent();
    s2->~PoolStudent();
    mp.disalloc(stu1);
    mp.disalloc(stu2);
    }catch(std::bad_alloc){
        std::cout<<"内存分配失败"<<std::endl;
        return 1;
    }
}