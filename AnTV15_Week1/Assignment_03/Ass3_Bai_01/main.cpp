#include <iostream>

using namespace std;
// Hàm đề bài cho, không hoán đổi được khi call thực hiện
// vì tham số truyền vào kiểu truyền giá trị, khi gọi hàm và 
// truyền đối số vào thì hàm sẽ copy giá trị của đối số vào biến cục bộ của hàm và thực thi.
// khi kết thúc gọi hàm giá trị của đố số không bị thay đổi nên vẫn còn nguyên giá trị ban đầu 
void swap(int evenNumber, int oddNumber) {
    int temp = evenNumber;
    evenNumber = oddNumber;
    oddNumber = temp;
}

// Hàm sửa đổi, tham số truyền vào hàm truyền kiểu tham chiếu thay vì truyền giá trị
// Khi sử dụng tham chiếu, giá trị của tham chiếu thay đổi sẽ làm giá trị của đối số truyền vào khi gọi hàm cũng thay đổi theo.

void swap_(int& evenNumber, int& oddNumber) {
    int temp = evenNumber; 
    evenNumber = oddNumber; 
    oddNumber = temp; 
}

int main() {
    int evenNumber = 2;
    int oddNumber  = 3;

    cout << "evenNumber:" << evenNumber << "\toddNumber:" << oddNumber << endl;

    // swap(evenNumber, oddNumber);
    swap_(evenNumber, oddNumber);

    cout << "evenNumber:" << evenNumber << "\toddNumber:" << oddNumber << endl;
    return 0;
}
