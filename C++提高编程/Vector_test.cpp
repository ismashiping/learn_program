#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void test01()
{
    std::vector<std::vector<int>> v;

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4;

    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (std::vector<std::vector<int>>::iterator it = v.begin();
         it != v.end(); ++it)
    {
        for (std::vector<int>::iterator vit = it->begin();
             vit != it->end(); ++vit)
        {
            std::cout << *vit << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    test01();
    std::system("pause");
    return 0;
}
