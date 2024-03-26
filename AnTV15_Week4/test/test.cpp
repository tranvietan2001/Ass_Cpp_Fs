#include <iostream>
#include <vector>

int main() {
    int a, b, n;
    std::cout << "Nhập giá trị a: ";
    std::cin >> a;
    std::cout << "Nhập giá trị b: ";
    std::cin >> b;
    std::cout << "Nhập số lượng phần n: ";
    std::cin >> n;

    size_t range_ab = b - a + 1;
    size_t part_range = range_ab / n;
    size_t remaining_elements = range_ab % n;

    size_t start_ = a, end_ = start_ + part_range - 1;

    for (int i = 0; i < n; i++) {
        if (i < remaining_elements) {
            end_++;
        }
        std::cout << "Phần " << i + 1 << ": " << start_ << " - " << end_ << std::endl;
        start_ = end_ + 1;
        end_ = start_ + part_range - 1;
    }

    return 0;
}