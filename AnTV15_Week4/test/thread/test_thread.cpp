// #include <iostream>
// #include <thread>
// #include <mutex>

// using namespace std;
// mutex mtx;
// void f1(int a, int b){
//     for(int i = a; i < b; i++){
//         lock_guard<mutex> lock(mtx); // tự động đóng mà mở khóa mutex khi ra khỏi phạm vi tương đương với lock và unlock, dùng tự động để tránh việc quên unlock
//         cout << i << endl;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     thread t1([] { f1(0, 1000); });  // dùng lamda thread
//     thread t2([] { f1( 1000,2000); });

//     t1.join();
//     t2.join();

//     cout << "=====================";
//     return 0;
// }



// #include <iostream>
// #include <thread>
// #include <vector>
// #include <chrono>
// #include <mutex>

// using namespace std;
// bool isPrime(size_t number) {
//     if (number <= 1)
//         return false;
//     for (size_t i = 2; i * i <= number; i++) {
//         if (number % i == 0)
//             return false;
//     }
//     return true;
// }

// void findPrimes(size_t start, size_t end, std::vector<size_t>& primes, std::mutex& mtx) {
//     for (size_t i = start; i <= end; i++) {
//         if (isPrime(i)) {
//             std::lock_guard<std::mutex> lock(mtx);
//             cout << i << "  ";
//             primes.push_back(i);
//         }
//     }
//     cout << endl;
// }

// int main() {
//     size_t a, b;
//     int n;
//     std::cout << "Enter the values of a, b, and n: ";
//     std::cin >> a >> b >> n;

//     std::vector<size_t> primes;
//     std::vector<std::thread> threads;
//     std::mutex mtx;

//     auto startTime = std::chrono::steady_clock::now();

//     size_t range = (b - a + 1) / n;
//     size_t remaining = (b - a + 1) % n;
//     size_t start = a;

//     for (int i = 0; i < n; i++) {
//         size_t end = start + range - 1;
//         if (remaining > 0) {
//             end++;
//             remaining--;
//         }
//         threads.emplace_back(findPrimes, start, end, std::ref(primes), std::ref(mtx));
//         start = end + 1;
//     }

//     for (auto& thread : threads) {
//         thread.join();
//     }

//     auto endTime = std::chrono::steady_clock::now();

//     std::cout << "Prime numbers found: ";
//     for (auto prime : primes) {
//         std::cout << prime << " ";
//     }
//     std::cout << std::endl;

//     std::chrono::duration<double> elapsedTime = endTime - startTime;
//     std::cout << "Time taken: " << elapsedTime.count() << " seconds" << std::endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::vector<int> resultVector; // Vector để lưu giá trị tăng dần của từng luồng
std::mutex mtx; // Mutex để đảm bảo tính nhất quán khi truy cập vào vector

void threadFunction(int start, int end) {
    std::vector<int> threadValues; // Vector để lưu giá trị tăng dần của luồng hiện tại

    // Tạo giá trị tăng dần từ start đến end
    for (int i = start; i <= end; i++) {
        threadValues.push_back(i);
    }

    // Đảm bảo tính nhất quán khi truy cập vào vector
    std::lock_guard<std::mutex> lock(mtx);

    // Thêm giá trị của luồng hiện tại vào vector chung
    resultVector.insert(resultVector.end(), threadValues.begin(), threadValues.end());
}

int main() {
    std::thread t1(threadFunction, 1, 100);
    std::thread t2(threadFunction, 101, 200);
    std::thread t3(threadFunction, 201, 300);

    t1.join();
    t2.join();
    t3.join();

    // In giá trị tăng dần của từng luồng theo thứ tự
    for (const auto& value : resultVector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
 
    return 0;
}