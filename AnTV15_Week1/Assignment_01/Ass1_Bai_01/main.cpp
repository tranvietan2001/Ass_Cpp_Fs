#include <iostream>
using namespace std;

int main() {
    //tạo con trỏ p kiểu int, cấp phát động (new), 
    int* p = new int;
    
    //gán giá trị cho vùng nhớ  = 10
    *p = 10;

    cout<< "Dia chi vung nho cua con tro p: " << p << endl;
    cout<< "Gia tri tai vung nho ma con tro p tro toi: " << *p <<endl;

    int* q;
    q = p;

    cout << "Gia tri cua vung nho ma con tro q tro toi truoc khi delete p: " << *q << endl;

    delete p;
    p = NULL;

    cout << "Gia tri cua vung nho ma con tro q tro toi sau khi delete p: " << *q << endl;

    if (p == NULL) {
        cout << "p dang tro vao NULL" << endl;
    } else {
        cout << "p khong tro vao NULL" << endl;
    }

    return 0;
}