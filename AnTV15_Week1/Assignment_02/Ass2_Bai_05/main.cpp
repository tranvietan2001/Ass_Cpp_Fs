#include <iostream>

using namespace std;

// UCLN (GCL) là số chung lớn nhất mà cả 2 số đều chia hết
// Hàm tìm Ước chung lớn nhất (GCD) của hai số
int GCD(int a, int b) {
    int temp;

    // chuyển a thành số lớn, b là số nhỏ
    if(b > a) {   
        temp = b;
        b = a;
        a = temp;
    }     
     
    int i = b;  // i chạy từ b
    while(i >= 1) {
        if(a%i == 0 && b%i == 0)    // nếu a và b cùng chia hết cho i, i là UCLN
            break;                  
        i--;
    }
    return i;   
}

// GLC dùng đệ quy
// int GCD(int a, int b) {
//     if (b == 0) {
//         return a;
//     }
//     return GCD(b, a % b);
// }

//  BCNN (LCM) là số nhỏ nhất mà cả 2 đố đều chia hết
//  Hàm tìm Bội chung nhỏ nhất (LCM) của hai số (BCNN tích 2 số * UCLN)
int LCM(int a, int b) {
    int result = (a * b) / GCD(a, b);
    return result ;
}

int main() {
    int A, B;

    // Nhập hai số A và B từ bàn phím
    std::cout << "Nhap so A: ";
    std::cin >> A;
    std::cout << "Nhap so B: ";
    std::cin >> B;

    // Kiểm tra điều kiện đầu vào
    if (A < 1 || B < 1 || A > 10000 || B > 10000) {
        std::cout << "Nhap khong hop le. Vui long nhap lai!";
        return 0;
    }

    // Tìm và in ra Ước chung lớn nhất và Bội chung nhỏ nhất
    std::cout << "Uoc chung lon nhat cua " << A << " va " << B << " la: " << GCD(A, B) << std::endl;
    std::cout << "Boi chung nho nhat cua " << A << " va " << B << " la: " << LCM(A, B) << std::endl;

    return 0;
}