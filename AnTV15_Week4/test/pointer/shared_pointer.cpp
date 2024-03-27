#include <iostream>
#include <memory>

using namespace std;

int main(){
    
    // shared_ptr<int> p1 (new int (100)); // 1 shared pointer p1 trỏ đến vùng nhớ được cấp phát kiểu int 
    // shared_ptr<int> p2 = p1; // copy shared pointer, p2 cùng trỏ đến vùng nhớ p1
    
    // cout << p1 << endl;     // địa chỉ vùng nhớ mà p1 trỏ đến
    // cout << p2 << endl;     // địa chỉ vùng nhớ mà p2 trỏ đến, sẽ giống với p1
    // p1.unique();
    // p1.reset();
    // p1.reset();
    // cout << p2 << endl; 
    // cout << p1.use_count() << endl; 
    // cout << p2.use_count() << endl; 

    // shared_ptr<int> p1(new int(10));

    // weak_ptr<int> p2 = p1;
    weak_ptr<int> p2;
    weak_ptr<int> p1=p2;
    weak_ptr<int> p3=p2;

    // cout << p1 << endl;
    // cout << *p1 << endl;
    // cout << p2.lock() << endl;
    // cout << p1.use_count() << endl;
    // p1.reset();
    cout << p2.use_count() << endl;

    return 0;
}    