#include <iostream>

using namespace std;
const int MAX_SIZE = 50;
class STACK{
    private:
        string list_students[MAX_SIZE];
        int size = 0;
    public:
        
        STACK(): size(-1) {}
        // kiem tra mang day
        bool isFull() {
            return (size == MAX_SIZE - 1);
        }
        // kiem tra mang rong
        bool isEmpty() {
            return (size == -1);
        }

        // đây dl vào mảng, thêm vào cuối mảng
        void pushData(const string data){ 
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
                cout << "Stack trong. Khong co du lieu hien ti." << endl;
            }
            else {
                for(int i=0 ; i < size+1; i++){
                    cout << "- Phan tu thu " << i + 1 << " [" << i << "] : " << list_students[i] <<endl;
                }
            }
            
        }

        // truy cập phần tử trong mãng, xem data tại vị trí index
        string peekData(int index){
            index = index - 1;
            if (isEmpty()) {
                cout << "Stack trong. Khong co du lieu hien ti." << endl;
            }
            else if(index > size){
                cout << "Vi tri khong ton tai! Gioi han cua mang la " << size << endl;
            }
            return list_students[index];
        }
};  
int main(int argc, char const *argv[]){
    cout <<  "STACK VOI KIEU DU LIEU STRING" << endl ;
    STACK stack;
    int n;
    string full_name;
    cout << "->Nhap so luong sinh vien vao mang: ";
    cin >> n;

    if (n >= MAX_SIZE){
        cout << "=> So luong sinh vien vuot qua kha nang luu tru cua mang! " << endl;
        return 0;
    }
    else {
        cin.ignore();
        for(int i = 0; i < n; i++){
            cout << "-> Nhap ho va ten sinh vien thu " << i+1 << " : " ;
            
            getline(cin, full_name);
            stack.pushData(full_name);
        }
    }
    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG TIN!" << endl;
    cout << "=> IN THONG TIN SINH VIEN VUA NHAP" << endl;
    stack.popData();
    cout << "------------------------------------" << endl;
    int x;
    cout << "-> Nhap vi tri phan tu trong mang muon xem du lieu:  " ;
    cin >> x;
    cout << "Phan tu " << x << " trong mang du lieu : " << stack.peekData(x) << endl;
    cout << "------------------------------------" << endl;
    return 0;
}
