// #include <iostream>
// #include <memory>

// using namespace std;

// int main(){
    
//     shared_ptr<int> p1 (new int (100)); // 1 shared pointer p1 trỏ đến vùng nhớ được cấp phát kiểu int 
//     shared_ptr<int> p2 = p1; // copy shared pointer, p2 cùng trỏ đến vùng nhớ p1
    
//     cout << p1 << endl;     // địa chỉ vùng nhớ mà p1 trỏ đến
//     cout << p2 << endl;     // địa chỉ vùng nhớ mà p2 trỏ đến, sẽ giống với p1
    
//     // cout << p1.use_count() << endl; 
//     return 0;
// }