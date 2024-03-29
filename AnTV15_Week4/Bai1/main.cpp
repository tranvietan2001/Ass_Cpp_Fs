#include <iostream>
#include "pointer.h"

using namespace std;


int main(){
    SharePointer<int> p1(new int(10)); 
    SharePointer<int> p19(new int(10));
    SharePointer<int> p4=p1;
    SharePointer<int> p5 =p1;
    SharePointer<int> p6;
    p6 = p1;
// 
    WeakPointer<int> p2(new int(1));

    // WeakPointer<int> p2(new int(140));

    // cout << p1 << endl;
    // cout << *p1 << endl;
    // cout << p2.lock() << endl;
    cout << p1.use_count() << endl;

    cout << p19.use_count() << endl;


    // SharePointer<int> p2 = p1;
    // {
    // SharePointer<int> p3 = p1;
    // cout << p1.use_count()<< endl; 
    // }
    // cout << p1.use_count()<< endl; 

//     p1.reset();

//     cout << p1.use_count()<< endl; 
// p1.reset();
// cout<< p3;
// p1.reset();
// p1.reset();

    return 0;
}