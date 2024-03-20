#include <iostream>

using namespace std;

//tham số truyền vào là con trở
/**
 * @brief hàm tính tổng 2 số
 * 
 * @param a tham số thứ nhất, tham số truyền vào dưới dạng con trỏ
 * @param b tham số thứ hai, tham số truyền vào dưới dạng con trỏ
 * @return tổng hai số
 */
int add(int* a, int* b) {
    int result = *a + *b;
    return result;
}
/**
 * @brief Hàm tính hiệu 2 số
 * 
 * @param a tham số thứ nhất, tham số truyền vào dưới dạng con trỏ
 * @param b tham số thứ hai, tham số truyền vào dưới dạng con trỏ
 * @return hiệu hai số 
 */
int sub(int* a, int* b) {
    int result = *a - *b;
    return result;
}
/**
 * @brief hàm tính tích hai số
 * 
 * @param a tham số thứ nhất, tham số truyền vào dưới dạng con trỏ
 * @param b tham số thứ hai, tham số truyền vào dưới dạng con trỏ
 * @return tích hai số 
 */
int mul(int* a, int* b) {
    int result = *a * *b;
    return result;
}

/**
 * @brief hàm tính thương hai số
 * 
 * @param a tham số thứ nhất, tham số truyền vào dưới dạng con trỏ
 * @param b tham số thứ hai, tham số truyền vào dưới dạng con trỏ
 * @return thương 2 số (kq chính sát đến chữ số thập phân thứ 7) 
 */
double div(int* a, int* b) {
    if (*b != 0) {
        double result = static_cast<double>(*a) / *b;
        return result;
    } else {
        std::cout << "ERROR: Khong the chia cho 0 " << std::endl;
        return 0;
    }
}

/**
 * @brief hàm chia lấy phần dư cua 2 so
 * 
 * @param a tham số thứ nhất, tham số truyền vào dưới dạng con trỏ
 * @param b tham số thứ hai, tham số truyền vào dưới dạng con trỏ
 * @return phần só dư của phép chia hai số 
 */
int mod(int* a, int* b) {
    if (*b != 0) {
        int result = *a % *b;
        return result;
    } else {
        std::cout << "ERROR: Khong the chia cho 0 " << std::endl;
        return 0;
    }
}

int main(int argc, char const *argv[]){

    int a, b;

    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu hai : ";
    cin >> b;
    
    // đối số truyền vào cho các hàm là tham chiếu
    cout << "==> ADD(A,B) = " << add(&a, &b) << endl;
    cout << "==> SUB(A,B) = " << sub(&a, &b) << endl;
    cout << "==> MUL(A,B) = " << mul(&a, &b) << endl;
    cout << "==> DIV(A,B) = " << div(&a, &b) << endl;
    cout << "==> MOD(A,B) = " << mod(&a, &b) << endl;

    return 0;
}