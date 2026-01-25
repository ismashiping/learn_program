#include <iostream>

using namespace std;
template <class T>
void mySwap(T &a, T &b){
    T temp =a;
    a =b;
    b = temp;
}
template <class T>
void mySort (T arr[] , int len){
    for (int i = 0;i<len ;i++)
    {
        int max = i; 
        for(int j =i+1;j<len;j++){
            if(arr[max]<arr[j]){
                max = j;
            }
        }
        if (max !=i){
            mySwap(arr[i],arr[max]);
        }
    }
    
}

template <class T>
void printArray(T arr[],int len){
    for(int i = 0;i<len;i++){
        cout<<arr[i];
    }
    cout<<endl;
}
//选择排序 从大到小
int main() {
    char charArray[] = "badcfe";
    int intArray[]={1,4,5,3,2,7};
    mySort(charArray,6);
    printArray(charArray,6);
    mySort(intArray,6);
    printArray(intArray,6);
    return 0;
}