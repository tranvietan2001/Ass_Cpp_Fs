#include <iostream>

using namespace std;

const int MAX_SIZE = 50;

class QUEUE{
    private:
        string list_students[MAX_SIZE];
        int size = 0;

    public:

        QUEUE(): size(-1){}

        // kiem tra mang day
        bool isFull() {
            return (size == MAX_SIZE - 1);
        }
        // kiem tra mang rong
        bool isEmpty() {
            return (size == -1);
        }

        //them data vao mang
        void Enqueue(const string data){
            if (isFull()) {
                cout << "Stack day! Khong the push them du lieu." << endl;
                return;
            }
            else    
                list_students[++size] = data; 
        }

        void Dequeue(int index){
            if(index > size) {
                cout << "==> So luong phan tu loai bo lon hon kich thuoc hien tai của mang!" << endl;
            }
            else {
                for(int i = 0; i < index; i++){
                    for (int j = index; j < size - 1; j++) {
                        list_students[j] = list_students[j + 1];
                    }
                    size--;
                }
            }
        }

        string peekData(int index){
            if (isEmpty()) {
                cout << "Stack trong. Khong co du lieu hien ti." << endl;
                return "";
            }
            else if(index > size){
                cout << "Vi tri khong ton tai! Gioi han cua mang la " << size << endl;
            }
            return list_students[index];
        }

        void outputData(){
            cout << "Tong so phan tu trong mang: " << size + 1 << endl;
            if (isEmpty()) {
                cout << "Stack trong. Khong co du lieu hien ti." << endl;
            }
            else {
                for(int i=0 ; i < size+1; i++){
                    cout << "- Phan tu thu " << i+1<< " : [" << i << "] " << list_students[i] <<endl;
                }
            }
            cout << "------------------------------------" << endl;
    }

    
};
int main(int argc, char const *argv[]){
    QUEUE q;
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
        for (int i = 0; i < n; i++){
            cout << "-> Nhap ho va ten sinh vien thu " << i+1 << " : " ;
            getline(cin, full_name);
            q.Enqueue(full_name);
        }
    }

    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG TIN!" << endl;
    cout << "=> IN THONG TIN SINH VIEN VUA NHAP" << endl;
    q.outputData();
    cout << "------------------------------------" << endl;
    
    int j;
    cout << "-> Nhap so luong sinh vien muon xoa o cuoi mang ra khoi bo du lieu: " ;
    cin >> j;
    q.Dequeue(j);

    cout << "------------------------------------" << endl;
    cout << "=> THONG TIN SINH VIEN CON LAI TRONG MANG" << endl;
    q.outputData();

    cout << "------------------------------------" << endl;

    cout << "-> Nhap so luong sinh vien muon them vao mang: ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n ; i++){
        cout << "-> Nhap ho va ten sinh vien thu " << i+1 << " : " ;
        getline(cin, full_name);
        q.Enqueue(full_name);
    }

    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG TIN!" << endl;
    cout << "=> IN THONG TIN SINH VIEN VUA NHAP" << endl;
    q.outputData();

    return 0;
}
