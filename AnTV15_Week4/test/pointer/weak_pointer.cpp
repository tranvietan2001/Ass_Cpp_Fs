// #include <iostream>
// #include <memory>

// using namespace std;

// int main(){
//     shared_ptr<int> p1(new int(100));
//     // shared_ptr<int> p = p1;
//     // weak_ptr<int> p1(new int(1));

//     weak_ptr<int> p2 = p1; // weak pointer p2 trỏ đến cùng object với p1
//     weak_ptr<int> p3 = p2; // weak pointer p2 trỏ đến cùng object với p1

//     cout << p1 << endl;
//     p3.expired();
//     // // cout << p2.lock() << endl;
//     // p2.reset();
//     cout << p1.use_count() << endl;
//     cout << p3.lock() << endl;
    
//     return 0;
// }