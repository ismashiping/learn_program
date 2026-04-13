#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
struct Student
{
    int id;
    std::string name;
    float grade;
};
int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> vec2(std::move(vec));
    // cout << "vec:" << vec.at(0) << endl; // 报越界错误
    cout << "vec2:" << vec2.at(0) << endl;
    cout << "Hello World" << endl;

    {
        std::vector<int> numbers = {50, 40, 30, 20, 10};
        std::cout << "before sort:";
        for (auto num : numbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // 使用sort排序
        std::sort(numbers.begin(), numbers.end());
        std::cout << "After sort:";
        for (auto num : numbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    {
        std::vector<int> numbers = {50, 40, 30, 20, 10};
        std::cout << "before sort:";
        for (auto num : numbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // 使用sort排序
        // std::sort(numbers.begin(), numbers.end(),greater<int>());
        std::sort(numbers.begin(), numbers.end(), [](int a, int b)
                  { return a > b; });
        std::cout << "After sort:";
        for (auto num : numbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    {
        std::vector<char> numbers = {'z', 'y', 'x', 'w', 'v'};
        std::cout << "before sort:";
        for (auto num : numbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // 使用sort排序
        // std::sort(numbers.begin(), numbers.end(),greater<int>());
        // std::sort(numbers.begin(), numbers.end(),[](int a,int b){
        //     return a>b;
        // });
        std::reverse(numbers.begin(), numbers.end());
        std::cout << "After sort:";
        for (auto num : numbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    {
        // 默认初始化
        std::vector<int> vec;
        ;
        std::vector<int> vec2(10, 0);
        std::vector<int> vec3 = {1, 2, 3};
        std::vector<int> vec4(vec3);
        std::vector<int> vec5(std::move(vec4));

        for (auto it = vec5.begin(); it != vec5.end(); it++)
        {
            cout << *it << " ";
        }
        for (auto &vec_one : vec5)
        {
            cout << vec_one << " ";
            cout << typeid(vec_one).name() << endl;
        }
        cout << endl;

        cout << "vec2.size():" << vec2.size() << endl;
        cout << "vec4.size():" << vec4.size() << endl;
        cout << "vec4.size():" << vec4.capacity() << endl;
        vec2.push_back(100);
        cout << "vec2.size():" << vec2.capacity() << endl;
        vec2.shrink_to_fit();
        cout << "vec2.capacity():" << vec2.capacity() << endl;
        bool b = vec2.empty();
        cout << "vec2.empty():" << b << endl;
    }
    {
        cout << "向量的基本操作:" << endl;
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);
        vec.push_back(60);
        vec.push_back(70);
        vec.push_back(80);
        vec.push_back(90);
        vec.push_back(100);
        vec.push_back(110);
        vec.push_back(120);
        vec.push_back(130);
        vec.push_back(140);
        vec.push_back(150);
        vec.push_back(160);
        vec.push_back(170);
        vec.push_back(180);
        vec.push_back(190);
        vec.push_back(200);
        vec.push_back(210);
        vec.push_back(220);
        for (auto &vec_one : vec)
        {
            cout << vec_one << " ";
        }
        vec.pop_back();
        cout << endl;
        for (auto &vec_one : vec)
        {
            cout << vec_one << " ";
        }
        cout << endl;
        vec.insert(vec.begin(), 100);
        for (auto &vec_one : vec)
        {
            cout << vec_one << " ";
        }
        cout << endl;
        vec.erase(vec.begin());
        for (auto &vec_one : vec)
        {
            cout << vec_one << " ";
        }
        cout << endl;
        vec.clear();
        for (auto &vec_one : vec)
        {
            cout << vec_one << " ";
        }
        cout << endl;
        cout << "vec.size():" << vec.size() << endl;
        cout << "vec.capacity():" << vec.capacity() << endl;
        {
            std::vector<int> empty_vec;
            vec.swap(empty_vec);
            cout << "empty_vec.capacity():" << empty_vec.capacity() << endl;
        }

        cout << "vec.capacity():" << vec.capacity() << endl;
    }
    /**
     * 访问元素
    operator[]：通过索引访问元素。
    at()：通过索引访问元素，带边界检查。
    front()：访问第一个元素。
    back()：访问最后一个元素。
     */
    std::vector<std::string> fruits = {"apple", "banana", "cherry"};
    std::cout << "first element:" << fruits[0] << std::endl;
    std::cout << "first element:" << fruits.front() << std::endl;
    std::cout << "last element:" << fruits.back() << std::endl;
    // try{
    //     std::cout<<"10068 element:"<<fruits.at(10068)<<std::endl;
    // }catch(exception &e){
    //     cout<<e.what()<<endl;
    // }
    fruits[0] = "orgin";
    fruits.at(1) = "banana_orgin";
    fruits.front() = "front_orgin";
    for (auto &fruit : fruits)
    {
        cout << fruit << endl;
    }

    /**
     *  修改元素

    通过索引或迭代器修改
    使用 assign() 重新赋值
    替换整个向量内容

     */

    {
        std::vector<int> vec = {10, 20, 30, 40, 50};

        // 使用迭代器遍历并修改元素
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            *it += 5;
        }

        // 输出修改后的向量
        std::cout << "After modifying: ";
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl; // 输出: 15 25 35 45 55 }
    }
    {
        std::vector<Student> students;

        // 添加学生
        students.push_back(Student{1001, "Alice", 95.0});
        students.push_back({1002, "Bob", 92.0});
        students.push_back({1003, "Charlie", 85.5});

        // 遍历并输出学生信息
        for (const auto &student : students)
        {
            std::cout << "ID: " << student.id
                      << ", Name: " << student.name
                      << ", Grade: " << student.grade<< std::endl;
        }
    }
    return 0;
}
