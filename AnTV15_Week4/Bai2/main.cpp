#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>
#include <mutex> // sử dụng mutex để đảm bảo việc đồng bộ khi chạy các thread dùng chung 1 hàm, đảm bảo tại 1 thời điểm chỉ có 1 thread đc thực hiện
#include <vector>
#include <algorithm>

using namespace std;
mutex mtx;

vector<size_t> list_prime;

bool checkPrime(size_t number){
    int count = 0;
    if(number < 2) return false;
    for(size_t i = 2; i <= sqrt(number); i++){
        if((number % i) == 0)
            count++;
    }
    if(count == 0) return true;
    else return false;
}

void numberPrime(size_t a, size_t b){
    for (size_t i = a; i <= b; i++){
        if(checkPrime(i)){
            // tự động đóng mà mở khóa mutex khi ra khỏi phạm vi 
            // tương đương với lock + unlock, dùng tự động để tránh việc quên unlock
            lock_guard<mutex> lock(mtx); 
            cout << i << "  ";
            list_prime.push_back(i);
        }
    }
    cout << endl;
}

void divPart(size_t a, size_t b, int n){
    size_t range_ab = b -a + 1;             // số phàn tử trong khoảng [a,b]
    size_t one_part_range = range_ab / n;   // ước lượng số phần tử của 1 thread
    size_t part_residual = range_ab % n;    // số phần tử dư nếu chia không hết của [a,b] cho n thread
    size_t start_ = a, end_ = one_part_range;

    for (int i  = 0; i < n; i++){ 
        if( i < part_residual) end_++;
        cout << "thread " << i << ": " << start_ << "-" << end_ <<  endl;
        start_ = end_ + 1;
        end_ = end_ + one_part_range;
        if (end_ > b) end_ = b;
    }
}


int main(){
    size_t a, b;
    int n;
    cout << "Nhap khoang [a,b] can tim kiem so nguyen to" << endl;
    cout << "   -> a = ";
    cin >> a;
    cout << "   -> b = ";
    cin>> b;

    if (a >= b ) {
        cout << "==> So b phai lon hon so a (b > a)! Kiem tra va chay lai chuong trinh!!!"<< endl;
        return 0;
    }
    else {
        cout << "Tim so nguyen to trong khoang [a,b] su dung n luong (threads)" << endl;
        cout << "   -> n = "; 
        cin >> n;
        if(n <= 0){
            cout << "==> So luong phai lon hon 0 (n > 0)! Kiem tra va chay lai chuong trinh!!!" << endl;
            return 0;
        }
        else{

            thread arr_thread[n]; // khởi tạo mảng chứa n thread;
            auto start_time = chrono::steady_clock::now(); // lưu thời gian bất đầu chạy các luồng

            cout << "==> Phan chia phan tu cho cac luong thuc thi" << endl;
            divPart(a,b,n);
            cout << "----------------------------" << endl;

            size_t range_ab = b -a + 1;             // số phàn tử trong khoảng [a,b]
            size_t one_part_range = range_ab / n;   // ước111 lượng số phần tử của 1 thread
            size_t part_residual = range_ab % n;    // số phần tử dư nếu chia không hết của [a,b] cho n thread
            size_t number_start_part = a, number_end_part  = one_part_range;

            for (int i  = 0; i < n; i++){ 
                if( i < part_residual) 
                    number_end_part++;
                arr_thread[i] = thread(numberPrime, number_start_part, number_end_part); // sử dụng đối tượng functor để có thể truyền đối số vào hàm khi tạo thread
                number_start_part = number_end_part + 1;
                number_end_part = number_end_part + one_part_range;
                if (number_end_part > b) 
                    number_end_part = b;
            }

            for(int i = 0; i < n; i++){
                arr_thread[i].join();
            }

            auto end_time = chrono::steady_clock::now(); // lưu thời gian kết thúc chạy các luồng

            chrono::duration<double> elapsed_time = end_time - start_time;
            cout << "==> Tho gian thuc thi:  " << elapsed_time.count() << " s" << endl;
        }       
 
    }
    // in ra danh sách các số nguyên tố có trong khoảng [a,b] được sắp xếp theo thứ tự tăng dần.
    cout << "--------------------------" << endl;
    sort(list_prime.begin(), list_prime.end());
    cout << "- Co tat ca " << list_prime.size() << " so nguyen to trong khoang [" << a << "," << b << "]" << endl;
    cout << "- Danh sach cac so nguyen to trong khoang [" << a << "," << b << "]: " << endl;
    for(const size_t& value : list_prime){
        cout << value << " ";
    }

    return 0;
}