#include <iostream>
#include <memory>

using namespace std;

int main(){
    shared_ptr<int> p1(new int(100));

    weak_ptr<int> p2(p1); // weak pointer p2 trỏ đến cùng object với p1

    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;
    
    return 0;
}