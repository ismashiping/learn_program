#include"Derived.h"
#include<iostream>
using std::cout;
using std::endl;

void Derived::display (){
        cout<<"derived override"<<endl;
        // cout<<"privateNum: "<<privateNum<<endl;
        cout<<"protectedNum: "<<protectedNum<<endl;
    }