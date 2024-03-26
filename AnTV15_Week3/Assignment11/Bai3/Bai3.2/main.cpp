#include <iostream>

using namespace std;

const int MAX_SIZE = 50;
template <typename T>
class QUEUE{
    private:
        T list_students[MAX_SIZE];
        int size = 0;

    public:

        QUEUE(): size(-1){}
        bool isFull() {
            return (size == MAX_SIZE - 1);
        }
        // kiem tra mang rong
        bool isEmpty() {
            return (size == -1);
        }

        //them data vao mang
        void Enqueue(const T data){
            if (isFull()) {
                cout << "Stack day! Khong the push them du lieu." << endl;
                return;
            }
            else
                list_students[++size] = data; 
        }

        void Dequeue(int index){
            if(index > size) {
                cout << "==> So luong phan tu loai bo lon hon kich thuoc hien tai cua mang!" << endl;
            }
            else {
                int new_size = size - index + 1;

                // cout << new_size << endl;
                T *list_temp = new T[new_size];

                for (int i = 0; i < new_size; i++) {
                    list_temp[i] = list_students[index + i];

                    // cout << list_temp[i] << "\t";
                }
                // cout << endl;
                for (int j = 0; j < new_size; j++) {
                    list_students[j] = list_temp[j];
                    // cout << list_students[j] << "\t";
                }
                // cout << endl;
                size = new_size - 1;
                delete[] list_temp;
            }
        }

        T peekData(int index){
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
                for(int i=0 ; i < (size+1); i++){
                    cout << "- Phan tu thu " << i+1<< " : [" << i << "] " << list_students[i] <<endl;
                }
            }
            cout << "------------------------------------" << endl;
    }

    
};
int main(int argc, char const *argv[]){
    cout << "QUEUE kieu INT - quan ly mang so nguyen kieu int"<< endl;
    QUEUE<int> q;
    int n;
    string full_name;
    int number;
    cout << "->Nhap so luong so kieu int vao mang: ";
    cin >> n;

    if (n >= MAX_SIZE){
        cout << "=> So luong so nguyen kieu int vuot qua kha nang luu tru cua mang! " << endl;
        return 0;
    }
    else {
        cin.ignore();
        for (int i = 0; i < n; i++){
            cout << "-> Nhap so nguyen kieu thu " << i+1 << " : " ;
            // getline(cin, number);
            cin >>number;
            q.Enqueue(number);
        }
    }

    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG TIN!" << endl;
    cout << "=> IN THONG TIN CAC SO NGUYEN KIEU INT VUA NHAP" << endl;
    q.outputData();
    cout << "------------------------------------" << endl;
    
    int j;
    cout << "-> Nhap so luong so nguyen kieu int muon lay ra khoi QUEUE " ;
    cin >> j;
    q.Dequeue(j);

    cout << "------------------------------------" << endl;
    cout << "=> THONG TIN CAC SO NGUYEN KIEU INT CON LAI TRONG MANG" << endl;
    q.outputData();

    cout << "------------------------------------" << endl;

    cout << "-> Nhap so luong so nguyen kieu int muon them vao mang: ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n ; i++){
        cout << "-> Nhap ho va ten sinh vien thu " << i+1 << " : " ;
        // getline(cin, number);
        cin >> number;
        q.Enqueue(number);
    }

    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG TIN!" << endl;
    cout << "=> IN THONG TIN TAT CA SO NGUYEN KIEU INT CO TRONG MANG" << endl;
    q.outputData();


    /******************************************************************/

    cout << "QUEUE kieu FLOAT - quan ly mang so nguyen thuc float"<< endl;
    QUEUE<float> q_f;
    // int n;
    float number_f;
    cout << "->Nhap so luong so kieu float vao mang: ";
    cin >> n;

    if (n >= MAX_SIZE){
        cout << "=> So luong so thuc kieu float vuot qua kha nang luu tru cua mang! " << endl;
        return 0;
    }
    else {
        cin.ignore();
        for (int i = 0; i < n; i++){
            cout << "-> Nhap so thuc kieu float thu " << i+1 << " : " ;
            // getline(cin, number);
            cin >>number_f;
            q_f.Enqueue(number_f);
        }
    }

    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG TIN!" << endl;
    cout << "=> IN THONG TIN CAC SO NGUYEN KIEU FLOAT VUA NHAP" << endl;
    q_f.outputData();
    cout << "------------------------------------" << endl;
    
    // int j;
    cout << "-> Nhap so luong so nguyen kieu float muon lay ra khoi QUEUE " ;
    cin >> j;
    q_f.Dequeue(j);

    cout << "------------------------------------" << endl;
    cout << "=> THONG TIN CAC SO THUC KIEU FLOAT CON LAI TRONG MANG" << endl;
    q_f.outputData();

    cout << "------------------------------------" << endl;

    cout << "-> Nhap so luong so thuc kieu float muon them vao mang: ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n ; i++){
        cout << "-> Nhap so thuc kieu float thu " << i+1 << " : " ;
        // getline(cin, number);
        cin >> number_f;
        q_f.Enqueue(number_f);
    }

    cout << "------------------------------------" << endl;
    cout << "==> NHAP XONG THONG TIN!" << endl;
    cout << "=> IN THONG TIN TAT CA SO THUC KIEU FLOAT CO TRONG MANG" << endl;
    q_f.outputData();

    return 0;
}
