#include <iostream>
#include "lib_math.h"

using namespace std;

int main(){
    float a = 16, b = 21;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "Chuong trinh tinh cong, tru, nhan, chia 2 so a va b" << endl;
    cout << "-> Tong a va b: " << add(a,b) << endl;
    cout << "-> Hieu a va b: " << sub(a,b) << endl;
    cout << "-> Tich a va b: " << mul(a,b) << endl;
    cout << "-> Thuong a va b: " << div(a,b) << endl;
    return 0;
}
