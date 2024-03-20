// Viết chương trình in ra các số Fibonacci (100 số đầu tiên): 1 1 2 3 5 8 13 21 34...
#include <iostream>
using namespace std;

int main() {
    int n = 100; // Số lượng số Fibonacci cần in ra
    int number_first = 1, number_second = 1; // Hai số đầu tiên trong dãy Fibonacci

    cout << "Cac so Fibonacci (" << n << " so dau tien) la:\n";

    cout << number_first << " " << number_second << " "; // In ra hai số đầu tiên

    for (int i = 3; i <= n; i++) {
        //unsigned long long cho phạm vi kết quả từ 0-2^64-1, kết quả vượt quá pham vi sẽ bị overload => kết quả ko chính xác
        unsigned long long number = number_first + number_second; // Tính số Fibonacci tiếp theo = tổng 2 số liền trước
        
        cout << number << " ";

        // Di chuyển các số để tính số Fibonacci tiếp theo
        number_first = number_second;
        number_second = number;
    }

    cout << endl;

    return 0;
}