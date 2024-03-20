// Viết một chương trình đơn giản ví dụ sử dụng scoped enum. Comment giải thích đầy đủ ý nghĩa

#include <iostream>

using namespace std;

//enum là một kiểu dữ liệu trong C++, cho phép định nghĩa một tập các giá trị có thể có cho một biến


//Unscoped Enumeration (Liet ke khong co pham vi): là loại enum mặt định
/**
 * @brief dinh nghia 1 enum Color: Kiểu dữ liệu là enum Color với các giá trị của kiểu này là Red, Green, Blue.
 * 
 */
enum Color {
    // Color,   // trong cùng space enum có cùng tên thf sẽ gây ra lỗi biên dịch
    Red,        //ngầm hiểu 0 = Red
    Green,      //ngầm hiểu 1 = Green
    Blue        //ngầm hiểu 2 = Blue
                // giá trị ngầm hiểu tăng dần khi thêm các giá trị khác...
                // ngầm định là do Color không  được định nghĩa kiểu dữ liệu cụ thể
};

// định nghĩa enum có kiểu dữ liệu int
enum Color_int : int {
    Red_,        
    Green_,      
    Blue_        
};

// enum sử dụng namespace
namespace Color_namespace
{   
    enum Color_namespace{
        Red, 
        Green,
        Blue,
        Black
    };
    
} // namespace Color_namespace

// Định nghĩa 1 enum class là Pet
enum class Pet{
    Dog,
    Cat,
    Fox,
    Snake,
    Chicken
};

int main() {
    
    Color myColor = Red;
    // Color myColor = static_cast<Color>(2); // nếu sử dụng các giá trị ngầm định thì phải ép kiểu cho nó từ int sang Color (2 thành Red)
    if (myColor == Red) {
        cout << "<1> Red la Mau Do." << endl;
    }


    Color_int myColorInt {2}; // khởi tạo biến myColorInt có kiểu enum Color_int là int
    if (myColorInt == Blue_) {
        cout << "<2> Blue_ la Mau Xanh Duong." << endl;
    }

    // khỏi tạo kiểu dữ liệu enum trong namespace 
    Color_namespace::Color_namespace mColorNameSpace { Color_namespace::Black};
        if (mColorNameSpace == 3) {
        cout << "<3> Black la Mau Den." << endl;
    }


    // Input / Output

    // Color mColor_inp { Blue };
    // cin >> mColor_inp; // biên dịch lỗi, muốn input được phải static_cast đầu vào
    // cout << mColor_inp << endl;

    cout << "Nhap Color (0=Red, 1=Green, 2=Blue): ";

    int input{};
    cin >> input; // input an integer
    string output;
    Color mColor_inp{ static_cast<Color>(input) }; // static_cast int thành Color
    if(mColor_inp == Red) output = "Red";
    else if(mColor_inp == Green) output = "Green";
    else if(mColor_inp == Blue) output = "Blue";
    else output = "Khong xac dinh, nam ngoai pham vi dinh nghia";
    cout << "<4> Enum Color input la: " << output << endl;


    //enum Class: khỏi tạp biến và gán gá trj từ class sử dụng toán tử phạm vi ::
    Pet mPet {Pet::Cat};
    // cout << mPet<< endl;

    // kiểm tra biến khỏi tạo bằng gì trong class khởi tạo và in ra
    if(mPet == Pet::Dog)
        cout<< "<5> enum class: Dog" << endl;
    else if(mPet == Pet::Cat)
        cout<< "<5> enum class: Cat" << endl;
    else if(mPet == Pet::Fox)
        cout<< "<5> enum class: Fox" << endl;
    else if(mPet == Pet::Snake)
        cout<< "<5> enum class: Snake" << endl;
    else if(mPet == Pet::Chicken)
        cout<< "<5> enum class: Chicken" << endl;
    
    
    return 0;
}