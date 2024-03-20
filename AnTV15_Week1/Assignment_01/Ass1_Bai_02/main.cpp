#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Nhap size cap phat cho array: ";
    cin >> size;

    // Cấp phát động mảng int với kích thước size được nhập từ bàng phím
    int* arr = new int[size];

    //in địa chỉ bất đầu của mảng được cấp pháp.
    cout<< "Dia chi bat dau cua mang duoc cap phat: " <<arr << endl;

    // Sử dụng mảng, tạm gán giá trị cho phần tử trong mảng theo biến i tăng dần
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    // //in địa chỉ bất đầu của mảng được cấp pháp.
    // cout<< "Dia chi bat dau cua mang duoc cap phat: " <<arr << endl;

    delete[] arr;

    if (arr == nullptr) {
        cout<< "Dia chi bat dau cua mang duoc cap phat khi da delete: " <<arr << endl;
        cout << "\tVung nho da duoc giai phong." << endl;
    } else {
        cout<< "Dia chi bat dau cua mang duoc cap phat khi chua delete: " <<arr << endl;
        cout << "\tVung nho chua duoc giai phong." << endl;
    }

    arr = nullptr; // Gán con trỏ mảng bằng nullptr

    // Kiểm tra trạng thái của vùng nhớ đã cấp phát khi delete và 
    if (arr == nullptr) {
        cout<< "Dia chi bat dau cua mang duoc cap phat khi da delete: " <<arr << endl;
        cout << "\tVung nho da duoc giai phong." << endl;
    } else {
        cout<< "Dia chi bat dau cua mang duoc cap phat khi chua delete: " <<arr << endl;
        cout << "\tVung nho chua duoc giai phong." << endl;
    }

    return 0;
}