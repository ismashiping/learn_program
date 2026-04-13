#pragma once
// #includecstdlib>
#include <iostream>
#include <cstddef>
template <typename T>
class Dequeue
{
private:
    size_t size;
    size_t capacity;
    T *buffer;
    size_t front;
    size_t back;
    void resize(size_t new_capacity)
    {
        T *new_buffer = new T[new_capacity];
        for (size_t i = 0; i < size; i++)
        {
            new_buffer[i] = buffer[(front + i) % capacity];
        }
        delete[] buffer;
        buffer = new_buffer;
        capacity = new_capacity;
    }

public:
    Dequeue(size_t capacity = 10) : capacity(capacity), size(0), front(0), back(0)
    {
        buffer = new T[capacity];
    }
    ~Dequeue()
    {
        delete[] buffer;
    }
    void push_back(T value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        buffer[back] = value;
        back = (back + 1) % capacity;
        size++;
    }
    void push_front(T value)
    {
        if (size == capacity)
        {
            /* code */
            resize(capacity * 2);
        }
        front = (front - 1 + capacity) % capacity;
        buffer[front] = value;
        size++;
    }
    T pop_back()
    {
        T value = buffer[(back - 1 + capacity) % capacity];
        back = (back - 1 + capacity) % capacity;
        size--;
        return value;
    }
    T pop_front()
    {
        T value = buffer[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }
    size_t getSize()
    {
        return size;
    }
    size_t getCapacity()
    {
        return capacity;
    }
    bool empty()
    {
        return size == 0;
    }
    T &front_test()
    {
        return buffer[front];
    }
    T &back_test()
    {
        return buffer[(back - 1 + capacity) % capacity];
    }
    class Iterator
    {
    private:
        Dequeue<T> *dequeue;
        size_t pos;

    public:
        using self_type = Iterator;
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        Iterator(Dequeue<T> *dequeue, size_t pos) : dequeue(dequeue), pos(pos) {};

        reference operator*() const
        {
            size_t index = (pos + dequeue->front) % dequeue->capacity;
            return dequeue->buffer[index];
        }

        pointer operator->() const
        {
            size_t index = (pos + dequeue->front) % dequeue->capacity;
            return &(dequeue->buffer[index]);
        }
        // 前置递增
        Iterator &operator++()
        {
            ++pos;
            return *this;
        }

        // 后置递增
        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++pos;
            return temp;
        }

        // 前置递减
        Iterator &operator--()
        {
            --pos;
            return *this;
        }

        // 后置递减
        Iterator operator--(int)
        {
            Iterator temp = *this;
            --pos;
            return temp;
        }

        // 比较操作
        bool operator==(const Iterator &other) const
        {
            return (dequeue == other.dequeue) && (pos == other.pos);
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }
    };
    Iterator begin_test()
    {
        return Iterator(this, 0);
    }

    // 获取 end 迭代器
    Iterator end_test()
    {
        return Iterator(this, size);
    }
};
