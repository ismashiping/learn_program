


struct ControlBlock{
    int ref_count;
    ControlBlock(){};
};
template <typename T>
class SimpleSharePtr{
    private:
        T * m_ptr ;
        ControlBlock * m_controlBlock;
    public:
        //无参构造
        SimpleSharePtr();
        //有参构造
        SimpleSharePtr(T * ptr);
        //拷贝构造
        SimpleSharePtr(const SimpleSharePtr & ptr);
        //移动构造
        SimpleSharePtr(SimpleSharePtr && ptr);
        //拷贝赋值
        SimpleSharePtr & operator=(const SimpleSharePtr & ptr);
        //移动赋值
        SimpleSharePtr & operator=(SimpleSharePtr && ptr);
        T& operator*() const;
        // 箭头操作符
        T* operator->() const;
        //获取裸指针
        T* get() const;
        //获取引用计数
        int use_count() const;
        //重置
        void reset(T* ptr = nullptr);
        void release();

        //析构
        ~SimpleSharePtr();

};

void testSimpleSharePtr();