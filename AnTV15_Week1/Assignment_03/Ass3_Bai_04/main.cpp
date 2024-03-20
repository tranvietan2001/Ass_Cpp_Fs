#include <iostream>
#include <cmath>  // để sd hàm sqrt()

using namespace std;

/**
 * @brief Hàm giai phuong trinh bac 2 AX^2 + BX + C = 0
 * 
 * @param a Tham số bậc 2 của phuong trinh
 * @param b Tham số bậc 1 của phương trình
 * @param c Tham số bậc 0 của phương trình
 */
void giai_phuong_trinh(double* a, double* b, double* c){
    // cout << "sss"<< endl;
    double x1, x2, x;

    if(*a == 0 && *b !=0){
        x1 = x2 = (-*c) / *b;
        cout << "==> PT co nghiem x = "<< x1 << endl;
    }
    else if (*a == 0 && *b ==0 && *c != 0){
        cout << "==> PT Vo Nghiem" << endl;
    }
    // else if (*a != 0 && *b ==0 && *c != 0)
    else {
        double delta = *b * *b - 4 * *a * *c;

        if (delta > 0) {
            x1 = (-*b + sqrt(delta)) / (2 * *a);
            x2 = (-*b - sqrt(delta)) / (2 * *a);
            cout << "==> 2 nghiem: Phuong trinh co 2 nghiem la: x1 = " << x1 << ", x2 = " << x2 << endl;
        } else if (delta == 0) {
            x = -*b / (2 * *a);
            cout << "==> 1 nghiem: Phuong trinh co 1 nghiemm la:  x = " << x << endl;
        } else {
            cout << "==> 0 nghiem: Phuong trinh vo nghiem." << endl;
        }
    }

}
int main() {
    double a, b, c;

    while (true) {
        cout << "*** CHUONG TRINH GIAI PT BAC 2: AX^2 + BX + C = 0 ***" << endl;
        cout << "=====================================================" << endl;
        cout << "Nhap A: ";

        // Kiểm tra các số a,b,c có nhập đúng kểu dữ liệu không, không phải kiểu số thực sẽ báo lỗi và dừng chương trình
        
        if(!(cin >> a)){
            cout << "==> ERROR: Nhap sai kieu du lieu." << endl;
            break;
        }

        cout << "Nhap B: ";
        if(!(cin >> b)){
            cout << "==> ERROR: Nhap sai kieu du lieu." << endl;
            break;
        }

        cout << "Nhap C: ";
        if(!(cin >> c)){
            cout << "==> ERROR: Nhap sai kieu du lieu." << endl;
            break;
        }

        // theo đề bài thì khi a = b = c = 0 thì kết thúc chương trình.
        if (a == 0 && b == 0 && c == 0) {
            cout << "==> KET THUC CHUONG TRINH !!!" << endl;
            break;
        }
        else giai_phuong_trinh(&a, &b, &c);
    }

    return 0;
}