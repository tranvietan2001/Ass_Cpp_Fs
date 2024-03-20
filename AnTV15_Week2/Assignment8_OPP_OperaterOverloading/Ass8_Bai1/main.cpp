#include <iostream>
using namespace std;

class String{
    private:
        size_t length;
        char *c;
    public:

    String() : c(nullptr), length(0) {}

    // Constructor từ một chuỗi ký tự
    String(const char* s) {
        length = strLenght(s);
        c = new char[length + 1];
        strCopy(c, s);
    }

    // copy constructor
    String(const String& other) {
        length = other.length;
        c = new char[length + 1];
        strCopy(c, other.c);
    }

    ~String() {
        delete[] c;
    }

    // input/ nhap chuoi
    void strIn(){
        char character = '\0';
        size_t size = 0, size_temp = 10;
        
        c = new char[size_temp];

        while((character != '\n') && (cin.get(character))){
            if (size == size_temp - 1){
                size_t new_size = size * 2;
                char* new_str_temp = new char[new_size];
                copy(c, c + size, new_str_temp);
                delete[] c;
                // c = nullptr;
                c = new_str_temp;
                size_temp = new_size;
            }
            c[size] = character;
            size++;
        }
        length = size-1;
        c[size] = '\0';
    }

    // output/ xuat chuoi
    void strOut(){
        cout << c;
    }

    // xoa toa bo chuoi
    void strClear(){
        if (c != nullptr){
            delete[] c;
            c= nullptr;
            length = 0;
        }
    }
    
    //Ghep 2 chuoi : cú pháp : newString  = strConcat(s1,s2) = noi s2 vao s1
    String strConcat(String s1, String s2){
        size_t len1 = s1.getLength() ;
        size_t len2 = s2.getLength() ;
        size_t len_new = len1 + len2 + 1;
        char* new_s = new char[len_new];
        size_t temp = 0;

        for(size_t i = 0; i < len1; i++){
            new_s[temp] = s1[i];
            // new_s[temp] = s1.getCharAt(i);
            temp++;
        }
        for(size_t j = 0; j < len2; j++){
            new_s[temp] = s2[j];
            temp++;
        }

        new_s[temp] = '\0';
        String result(new_s);
        delete[] new_s;
        new_s = nullptr;

        return result;
    }
    
    // dao chuoi : cú phap: newString = s1.strRev()
    String strRev(){
        size_t len = strLenght(c);
        char* rev = new char[len+1];

        for (int i = 0; i < len; i++) {
            rev[i] = c[len - i - 1];
        }
        rev[len] = '\0';
        return rev;
    }

    // size_t là kiểu dữ lệu trong thư viện chuẩn, là các giá trị không âm, kích thước 8byte (tùy thuộc vào kiến trúc và trình biên dịch)
    // size_t ~ unsigned long long int
    /**
     * @brief tính độ dài của chuỗi
     * 
     * @param str chuỗi truyền vào kiểu char
     * @return chiều dài của chuỗi có kểu char
     */
    size_t strLenght(const char* str) {
        size_t length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }
    
    /**
     * @brief Get the Length object
     * 
     * @return size_t Length object
     */
    size_t getLength() const {
        return length;
    }

    /**
     * @brief hàm sao chép dữ liệu của chuỗi
     * 
     * @param destination biến muốn sao chép nội dung vào (chuỗi đích)
     * @param source  biến chứa dữ liệu cần sao chép (chuỗi nguồn)
     * @return Trả về địa chỉ bắt đầu của chuỗi đíchs 
     */
    char* strCopy(char* destination, const char* source) {
        char* start = destination; // Lưu địa chỉ bắt đầu của chuỗi đích

        while (*source != '\0') {
            *destination = *source; // Sao chép ký tự từ nguồn tới đích
            destination++;
            source++;
        }

        *destination = '\0'; // Kết thúc chuỗi đích bằng ký tự null

        return start; // Trả về địa chỉ bắt đầu của chuỗi đích
    }

    // định nghĩa toán tử =, phép gán
    String& operator = (const String& other) {
        //  kiểm tra xem đối tượng được gán (other) có trùng với chính đối tượng hiện tại (this) hay không
        if (this == &other) 
            return *this;
        
        //  kiểm tra xem đối tượng hiện tại đã được khởi tạo (c khác nullptr) hay chưa. 
        //  Nếu đã được khởi tạo, sẽ xóa bộ nhớ đã cấp phát trước đó để tránh rò rỉ bộ nhớ
        if (c) 
            delete[] c;
        
        length = other.length;
        c = new char[length + 1];
        strCopy(c, other.c);

        return *this;
    }


    char& operator[](int index) {
        static char error = '\0';
        if (index >= 0 && index < length) 
            return c[index];
        return error ;
    }

    String operator + (const String& other) {
        size_t len1 = getLength();
        size_t len2 = other.getLength();
        size_t len = len1 + len2;

        char* new_c = new char[len1 + len2 + 1];

        for(size_t i = 0; i < len1; i++){
            new_c[i] = c[i];
        }

        for(size_t j = 0; j < len2; j++){
            new_c[len1 + j] = other.c[j];
        }

        new_c[len] = '\0';

        String new_string(new_c);
        delete[] new_c;
        new_c = nullptr;
        return new_string;
    }

    bool isEqual(const String& other) const {
    if (getLength() != other.getLength()) {
        return false;
    }

    for (size_t i = 0; i < getLength(); i++) {
        if (c[i] != other.c[i]) {
            return false;
        }
    }

    return true;
}

    
};

int main(int argc, char const *argv[]){
    String s1, s2;
    
    cout << "Nhap chuoi s1: " ;
    s1.strIn();
    cout << "Nhap chuoi s2: ";
    s2.strIn();
    cout << "===============================" << endl;
    cout << " ==> Xuat chuoi s1 su dung ham strOut(): " << endl;
    s1.strOut();
    cout<< " - Chieu dai chuoi s1:  " << s1.getLength() <<endl;
    cout << " ==> s2:";
    s2.strOut();
    cout<< " - Chieu dai chuoi s2 su dung hàm strOut(): " << s2.getLength() <<endl;

    cout << "===============================" << endl;
    String s3 = s3.strConcat(s1,s2);
    cout << "- Ghep 2 chuoi su dung ham strConcat(s1,s2): ";
    s3.strOut();
    cout<< "\n - Chieu dai chuoi :  " << s3.getLength() <<endl;
    cout << "\n- Ghep 2 chuoi su dung toan tu + : ";
    s3 = s1 + s2;
    s3.strOut();
    cout<< "\n - Chieu dai chuoi :  " << s3.getLength() <<endl;  

    cout << "===============================" << endl;
    cout<< " - Dao chuoi vua ghep bang ham strRev(): ";
    String s4 = s3.strRev();
    s4.strOut();
    cout << "\n===============================" << endl;

    cout<< " - So sanh 2 chuoi s1,s2 su dung ham isEqual()" << endl;
    bool result1 = s1.isEqual(s2);
    if(result1){
        cout << "--> 2 chuoi s1 va s2 giong nhau ve noi dung" << endl;
    }else cout << "--> 2 chuoi s1 va s2 khong giong nhau ve noi dung" << endl;

    cout << "===============================" << endl;
    cout << " - Xoa chuoi s1 su dung ham strClear(): " << endl;
    s1.strClear();
    if (s1.getLength() == 0){
        cout << "--> Da xoa noi dung chuoi s1!" << endl;
    }
    else cout << " -> s1 chua duoc xoa!" << endl;
    cout<< " -> Chieu dai chuoi s1:  " << s1.getLength() <<endl;
    cout << "===============================" << endl;
    // cout << result1;

    return 0;
}




