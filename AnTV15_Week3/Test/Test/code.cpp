// // #include <iostream>
// // #include <vector>

// // class Human {
// // private:
// //     int id;
// //     std::string fullName;
// //     int age;
// //     int birthYear;
// //     std::string occupation;

// // public:
// //     Human(int id, std::string fullName, int age, int birthYear, std::string occupation)
// //         : id(id), fullName(fullName), age(age), birthYear(birthYear), occupation(occupation) {}

// //     void displayInfo() const {
// //         std::cout << "ID: " << id << std::endl;
// //         std::cout << "Full Name: " << fullName << std::endl;
// //         std::cout << "Age: " << age << std::endl;
// //         std::cout << "Birth Year: " << birthYear << std::endl;
// //         std::cout << "Occupation: " << occupation << std::endl;
// //     }
// // };

// // class Town {
// // private:
// //     std::vector<Human> residents;
// //     int houseNumber;

// // public:
// //     Town(int houseNumber) : houseNumber(houseNumber) {}

// //     void addResident(const Human& resident) {
// //         residents.push_back(resident);
// //     }

// //     void displayResidents() const {
// //         std::cout << "House Number: " << houseNumber << std::endl;
// //         for (const Human& resident : residents) {
// //             resident.displayInfo();
// //             std::cout << std::endl;
// //         }
// //     }
// // };

// // void inputHouseholdInfo(Town& town) {
// //     int numResidents, houseNumber;
// //     std::cout << "Enter number of residents: ";
// //     std::cin >> numResidents;
// //     std::cout << "Enter house number: ";
// //     std::cin >> houseNumber;

// //     Town newHousehold(houseNumber);

// //     for (int i = 0; i < numResidents; i++) {
// //         int id, age, birthYear;
// //         std::string fullName, occupation;

// //         std::cout << "Enter information for resident " << i + 1 << std::endl;

// //         std::cout << "ID: ";
// //         std::cin >> id;
// //         std::cin.ignore();

// //         std::cout << "Full Name: ";
// //         std::getline(std::cin, fullName);

// //         std::cout << "Age: ";
// //         std::cin >> age;

// //         std::cout << "Birth Year: ";
// //         std::cin >> birthYear;
// //         std::cin.ignore();

// //         std::cout << "Occupation: ";
// //         std::getline(std::cin, occupation);

// //         Human newResident(id, fullName, age, birthYear, occupation);
// //         newHousehold.addResident(newResident);
// //     }

// //     town = newHousehold;
// // }

// // void displayTownInfo(const Town& town) {
// //     town.displayResidents();
// // }

// // int main() {
// //     Town myTown(1);
// //     inputHouseholdInfo(myTown);
// //     displayTownInfo(myTown);

// //     return 0;
// // }



// // #include <iostream>
// // #include <vector>

// // class Person {
// // private:
// //     std::string m_name;
// //     int m_age;
// //     std::string m_job;

// // public:
// //     Person(const std::string& name, int age, const std::string& job)
// //         : m_name(name), m_age(age), m_job(job) {}

// //     void displayInfo() const {
// //         std::cout << "Ho va ten: " << m_name << std::endl;
// //         std::cout << "Tuoi: " << m_age << std::endl;
// //         std::cout << "Nghe nghiep: " << m_job << std::endl;
// //     }
// // };

// // class Household {
// // private:
// //     std::vector<Person> m_members;

// // public:
// //     void addMember(const Person& person) {
// //         m_members.push_back(person);
// //     }

// //     void displayInfo() const {
// //         for (const Person& person : m_members) {
// //             person.displayInfo();
// //             std::cout << std::endl;
// //         }
// //     }
// // };

// // int main() {
// //     int n;
// //     std::cout << "Nhap so ho dan: ";
// //     std::cin >> n;

// //     std::vector<Household> households;
// //     for (int i = 0; i < n; i++) {
// //         int m;
// //         std::cout << "Nhap so thanh vien cua ho dan " << i + 1 << ": ";
// //         std::cin >> m;

// //         Household household;
// //         for (int j = 0; j < m; j++) {
// //             std::string name, job;
// //             int age;

// //             std::cout << "Nhap thong tin thanh vien " << j + 1 << ":\n";
// //             std::cout << "Ho va ten: ";
// //             std::cin.ignore();
// //             std::getline(std::cin, name);
// //             std::cout << "Tuoi: ";
// //             std::cin >> age;
// //             std::cout << "Nghe nghiep: ";
// //             std::cin.ignore();
// //             std::getline(std::cin, job);

// //             Person person(name, age, job);
// //             household.addMember(person);
// //         }

// //         households.push_back(household);
// //     }

// //     std::cout << "\nThong tin cac ho dan:\n";
// //     for (int i = 0; i < n; i++) {
// //         std::cout << "Ho dan " << i + 1 << ":\n";
// //         households[i].displayInfo();
// //         std::cout << std::endl;
// //     }

// //     return 0;
// // }



// #include <iostream>
// #include <vector>

// class Person {
// private:
//     std::string m_name;
//     int m_age;
//     std::string m_job;

// public:
//     Person(  std::string& name, int age, const std::string& job)
//         : m_name(name), m_age(age), m_job(job) {}

//     void displayInfo() const {
//         std::cout << "Ho va ten: " << m_name << std::endl;
//         std::cout << "Tuoi: " << m_age << std::endl;
//         std::cout << "Nghe nghiep: " << m_job << std::endl;
//     }
// };

// class Household {
// private:
//     std::string m_address;
//     std::vector<Person> m_members;

// public:
//     Household(const std::string& address)
//         : m_address(address) {}

//     void addMember(const Person& person) {
//         m_members.push_back(person);
//     }

//     void displayInfo() const {
//         std::cout << "Dia chi nha: " << m_address << std::endl;
//         std::cout << "Thanh vien trong ho:\n";
//         for (const Person& person : m_members) {
//             person.displayInfo();
//             std::cout << std::endl;
//         }
//     }
// };

// int main() {
//     int n;
//     std::cout << "Nhap so ho dan: ";
//     std::cin >> n;

//     std::vector<Household> households;
//     for (int i = 0; i < n; i++) {
//         std::string address;
//         std::cout << "Nhap dia chi nha cua ho dan " << i + 1 << ": ";
//         std::cin.ignore();
//         std::getline(std::cin, address);

//         int m;
//         std::cout << "Nhap so thanh vien cua ho dan " << i + 1 << ": ";
//         std::cin >> m;

//         Household household(address);
//         for (int j = 0; j < m; j++) {
//             std::string name, job;
//             int age;

//             std::cout << "Nhap thong tin thanh vien " << j + 1 << ":\n";
//             std::cout << "Ho va ten: ";
//             std::cin.ignore();
//             std::getline(std::cin, name);
//             std::cout << "Tuoi: ";
//             std::cin >> age;
//             std::cout << "Nghe nghiep: ";
//             std::cin.ignore();
//             std::getline(std::cin, job);

//             Person person(name, age, job);
//             household.addMember(person);
//         }

//         households.push_back(household);
//     }

//     std::cout << "\nThong tin cac ho dan:\n";
//     for (int i = 0; i < n; i++) {
//         std::cout << "Ho dan " << i + 1 << ":\n";
//         households[i].displayInfo();
//         std::cout << std::endl;
//     }

//     return 0;
// }

// #include <iostream>

// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int size = 4;
//     int val = 89;
//     int arr[4] = {13,2,3,4};
//     int new_size = size+1;

//     int new_arr[new_size];

//     // copy arr và new arr
//     for(int i = 0; i < size; i ++){
//         new_arr[i] = arr[i];
//     } 

//     new_arr[new_size-1] = val;

//     for(int i = 0;  i < new_size; i++){
//         cout << new_arr[i] << endl;
//     }
    
//     return 0;
// }


#include <iostream>

void dequeue(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    // Dịch chuyển các phần tử phía sau index lên một vị trí
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Giảm kích thước mảng đi một đơn vị
    size--;

    std::cout << "Element at index " << index << " removed successfully!" << std::endl;
}

int main() {
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5;

    int index = 4;
    dequeue(arr, size, index);

    // In ra mảng sau khi xóa phần tử
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}