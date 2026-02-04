#include <iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main() {
    int ia [1000000]={27,199,12,54,6,42};
    vector<int,allocator<int>> vi(ia,ia+6);
    cout<<count_if(vi.begin(),vi.end(),not1(bind2nd(less<int>(),40)));
    return 0;
}