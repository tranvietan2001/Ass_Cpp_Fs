#include <iostream>
#include <    thread>
using namespace std;
void fun1(){
    for(int i = 0; i < 10; i++){
        cout << i << endl;
    }
}

void fun2(){
    for(int i = 10; i < 20; i++){
        cout << i << endl;
    }
}

int main(int argc, char const *argv[])
{
    thread f1(fun1);

    thread f2(fun2);
    f1.join();
    f2.join();
        


    return 0;
}
