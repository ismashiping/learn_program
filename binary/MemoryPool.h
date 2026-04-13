#include <iostream>
#include<cstdlib>
#include<stack>
class MemoryPool{
    private:
        size_t objSize;
        size_t poolSize;
        char *pool; //用于指向一大块内存 
        std::stack<char *> freeList; //用于存储区块
    public:
        MemoryPool(size_t objsize,size_t poolsize);
        ~MemoryPool();
        char *alloc();
        void disalloc(char *p);
     

};

class PoolStudent {
    public:
        int id;
        std::string name;
        PoolStudent(int id, std::string name) {
            this->id = id;
            this->name = name;
        }
        // ~PoolStudent() {
        //     std::cout << "析构函数调用" << std::endl;
        // }
};
int test2();