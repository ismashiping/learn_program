#pragma once
#include <iostream>
#include <cstddef>
template <typename T>
class List;
// 节点
template <typename T>
struct Node
{
    /* data */
    T data;
    Node<T> *next;
    Node<T> *prev; // 他为什么不加<T>?

    Node(const T &value = T()) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Iterator
{
public:
    using self_type = Iterator<T>;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    // 无参构造
    Iterator(Node<T> *ptr = nullptr) : node_ptr(ptr) {};

    reference operator*() const
    {
        return node_ptr->data;
    }
    pointer operator->() const
    {
        return &(node_ptr->data);
    }
    self_type &operator++()
    {
        node_ptr = node_ptr->next;
        return *this; // this 本质上是一个指针 指向自身
    }
    self_type operator++(int)
    {
        self_type temp = *this;
        ++*this;
        return temp;
    }
    self_type operator--()
    {
        if (node_ptr != nullptr)
        {
            node_ptr = node_ptr->prev;
        }
        return *this;
    }

    self_type operator--(int)
    {
        self_type temp = *this;
        --*this;
        return temp;
    }

    bool operator==(const self_type &other) const
    {
        return node_ptr == other.node_ptr;
    }

    bool operator!=(const self_type &other) const
    {
        return node_ptr != other.node_ptr;
    }

private:
    Node<T> *node_ptr;
    friend class List<T>;
};

template <typename T>
class List
{
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T &>;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    List()
    {
        head = new Node<T>();
        tail = new Node<T>();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    ~List()
    {
        clear();
        delete head;
        delete tail;
    }
    void clear()
    {
        Node<T> *cur = head->next;
        while (cur != tail)
        {
            Node<T> *next = cur->next;
            delete cur;
            cur = next;
        }
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    List(const List<T> &other) = delete;
    List<T> &operator=(const List<T> &other) = delete;
    iterator begin()
    {
        return iterator(head->next);
    }
    iterator end()
    {
        return iterator(tail);
    }

    iterator insert(iterator pos, const T &value)
    {
        Node<T> *cur = pos.node_ptr;
        Node<T> *newNode = new Node<T>(value);

        Node<T> *node_pre = cur->prev;

        newNode->prev = node_pre;
        newNode->next = cur;
        node_pre->next = newNode;
        cur->prev = newNode;
        size++;

        return iterator(newNode);
    }
    iterator erase(iterator pos)
    {
        Node<T> *cur = pos.node_ptr;
        if (cur == head || cur == tail)
        {
            return iterator(cur);
        }
        Node<T> *node_pre = cur->prev;
        Node<T> *node_next = cur->next;
        node_pre->next = node_next;
        node_next->prev = node_pre;
        int num =node_pre->data;
        int num2 =node_next->data;
        int num3 =cur->data;
        delete cur;
        size--;
        return iterator(node_next);
    }

    T &front()
    {
        return head->next->data;
    }
    T &back()
    {
        return tail->prev->data;
    }
    bool empty()
    {
        return size == 0;
    }
    void push_front(const T &value)
    {
        insert(begin(), value);
    }
    void push_back(const T &value)
    {
        insert(end(), value);
    }
    void pop_front()
    {
        if (!empty())
        {
            erase(begin());
        }
    }

    // 在尾部删除元素
    void pop_back()
    {
        if (!empty())
        {
            iterator temp = end();
            --temp;
            erase(temp);
        }
    }

    void print() const
    {
        Node<T> *current = head->next;
        while (current != tail)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node<T> *head;
    Node<T> *tail;
    size_type size;
};