#include <iostream>
#include <vector>

int main() {
    // Tạo một vector lồng nhau
    // Khởi tạo các vector con trong vector lớn
    std::vector<std::vector<int>> nestedVector;
    for (int i = 0; i < 5; i++) {
        std::vector<int> innerVector;
        nestedVector.push_back(innerVector);
    }

    // Thêm các phần tử vào từng vector con
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            nestedVector[i].push_back(j);
        }
    }
    // nestedVector.push_back({1, 2, 3});
    // nestedVector.push_back({4, 5, 6,7,8,9,9,9,9});
    // nestedVector.push_back({7, 8, 9});

    // Truy xuất và in các phần tử trong vector lồng nhau
    for (const auto& innerVector : nestedVector) {
        for (const auto& element : innerVector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}