#include <iostream>

using namespace std;
const int MAX_SIZE = 50;
template <typename T>
class STACK{
    private:
        T list_students[MAX_SIZE];
        int size = 0;
    public:
        
        STACK() : size(-1) {}
        // kiem tra mang day
        bool isFull()  {
            return (size == MAX_SIZE - 1);
        }
        // kiem tra mang rong
        bool isEmpty() {
            return (size == -1);
        }
 
        // đây dl vào mảng, thêm vào cuối mảng
        void pushData(const T data){ 
            if (isFull()) {
                cout << "Stack day! Khong the push them du lieu." << endl;
                return;
            }
            else    
                list_students[++size] = data;            
        }

        // Xuat thong tin toan bo mang
        void popData(){
            cout << "Tong so phan tu trong mang: " << size + 1 << endl;
            if (isEmpty()) {
                cout << "Stack trong. Khong co du lieu hien thi." << endl;
            }
            else {
                for(int i=0 ; i < size+1; i++){
                    cout << "- Phan tu thu " << i+1<< " : [" << i << "] " << list_students[i] <<endl;
                }
            }
            
        }

        // truy cập phần tử trong mãng, xem data tại vị trí index
        T peekData(int index){
            index = index-1;
            if (isEmpty()) {
                cout << "Stack trong. Khong co du lieu hien ti." << endl;
                
            }
            else if(index > size){
                cout << "Vi tri khong ton tai! Gioi han cua mang la " << size << endl;
            }
            return list_students[index];
        }
};

int main(){
    cout <<  "STACK VOI KIEU DU LIEU INT" << endl ;
    STACK<int> stack;
    // string full_name;
    int number;

    int n;
    cout << "->Nhap so luong bien kieu INT vao mang: ";
    cin >> n;

    if (n >= MAX_SIZE){
        cout << "=> So luong bien kieu INT vuot qua kha nang luu tru cua mang! " << endl;
        return 0;
    }
    else {
        // cin.ignore();
        for(int i = 0; i < n; i++){
            cout << "-> Nhap so thu " << i+1 << " : " ;
            cin >> number;
            stack.pushData(number);
            // getline(cin, full_name);
            // stack.pushData(full_name);
        }
    }
    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG TIN!" << endl;
    cout << "=> IN THONG BIEN SO KIEU INT VUA NHAP" << endl;
    stack.popData();
    cout << "------------------------------------" << endl;
    int x;
    cout << "-> Nhap vi tri phan tu trong mang muon xem du lieu:  " ;
    cin >> x;
    cout << "Phan tu " << x << " trong mang du lieu : " << stack.peekData(x) << endl;
    cout << "------------------------------------" << endl;
    
    /*******************************************/

    cout <<  "STACK VOI KIEU DU LIEU FLOAT" << endl ;
    STACK<float> stack_f;
    // string full_name;
    float number_f;

    int n_f;
    cout << "->Nhap so luong bien kieu FLOAT vao mang: ";
    cin >> n_f;

    if (n_f >= MAX_SIZE){
        cout << "=> So luong bien kieu FLOAT vuot qua kha nang luu tru cua mang! " << endl;
        return 0;
    }
    else {
        // cin.ignore();
        for(int i = 0; i < n_f; i++){
            cout << "-> Nhap so thu " << i+1 << " : " ;
            cin >> number_f;
            stack_f.pushData(number_f);
            // getline(cin, full_name);
            // stack.pushData(full_name);
        }
    }
    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG FLOAT!" << endl;
    cout << "=> IN THONG BIEN SO KIEU FLOAT VUA NHAP" << endl;
    stack_f.popData();
    cout << "------------------------------------" << endl;
    int x_f;
    cout << "-> Nhap vi tri phan tu trong mang muon xem du lieu:  " ;
    cin >> x_f;
    cout << "Phan tu " << x_f << " trong mang du lieu : " << stack_f.peekData(x_f) << endl;
    cout << "------------------------------------" << endl;

    return 0;
}
