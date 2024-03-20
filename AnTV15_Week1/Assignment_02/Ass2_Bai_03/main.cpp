// toán tử & (AND): 1 & 1 = 1; còn lại là 0
// toán tử | (OR) : 0 | 0 = 0; còn lại là 1
// toán tử ^ (XOR): 0 ^ 1 = 1 ; còn lại 0
// toán tử ~ (NOT); ~1 = 0; ~0 = 1
// tắt 1 -> 0: a & ~b
// bật 0 -> 1: a | b
// với b là 1 << [vị trí bit thay đổi], a là flag 8 bit 
#include <iostream>
using namespace std;


/**
 * @brief Lay gia tri bit
 * 
 * @param flag Chuoi 8 bit truyen vao
 * @param bit_position vi tri trong chuoi 8 bit can lay ra
 * @return Gia tri cua bit tai vi tri bit_position 
 */
bool get_bit(unsigned char flag, int bit_position){
    // [(flag >> i) & 1] và [flag & (1 << i)] cả 2 đều đúng
    bool bit_val = flag & (1 << bit_position);
    return bit_val;
}
/**
 * @brief Thay doi gia tri cua bit
 * 
 * @param flag chuoi 8 bit truyen vao
 * @param bit_position vi tri bit can thay doi gia tri
 * @return chuoi 8 bit sau khi thay doi gia tri tai bit_position
 */
unsigned char set_bit(unsigned char flag, int bit_position) {
    if (flag & (1 << bit_position)) {
        flag = flag & (~(1 << bit_position));
    } else {
        flag |= (1 << bit_position);
    }
    
    return flag;
}

/**
 * @brief Kiem tra che do POWER SAVING
 * 
 * @param flag Chuoi 8 bit truyen vao
 * @return true ca 2 bit 7 và bit 5 deu bang 1 (Climate và backup battery deu ON)
 * @return false 1 trong 2 bit 7 và 5 bang 0 (Climate và backup battery khong cung ON)
 */
bool check_power_saving(unsigned char flag){
    bool check;
    if (get_bit(flag, 7)  && get_bit(flag, 5))
        check = true;
    else check = false;
    return check; 
}

/**
 * @brief in ra toan bo status cua flag 8 bit truyen vao
 * 
 * @param flag chuoi 8 bit truyen vao
 */
void report_bits(unsigned char flag){

    // In ra giá trị các bit trong flag
    std::cout << "Bit 7: " << get_bit(flag, 7) << std::endl;
    std::cout << "Bit 6: " << get_bit(flag, 6) << std::endl;
    std::cout << "Bit 5: " << get_bit(flag, 5) << std::endl;
    std::cout << "Bit 4: " << get_bit(flag, 4) << std::endl;
    std::cout << "Bit 3: " << get_bit(flag, 3) << std::endl;
    std::cout << "Bit 2: " << get_bit(flag, 2) << std::endl;
    std::cout << "Bit 1: " << get_bit(flag, 1) << std::endl;
    std::cout << "Bit 0: " << get_bit(flag, 0) << std::endl;

}

/**
 * @brief Menu hien thi trang thai cua cac thi bi
 * 
 * @param flag chuoi 8 bit truyen vao
 */
void menu_app(unsigned char flag){ 
    // bool bit0 = (flag >> 0) & 1;
    // bool bit1 = (flag >> 1) & 1; 
    // bool bit2 = (flag >> 2) & 1; 
    // bool bit3 = (flag >> 3) & 1; 
    // bool bit4 = (flag >> 4) & 1; 
    // bool bit5 = (flag >> 5) & 1; 
    // bool bit6 = (flag >> 6) & 1; 
    // bool bit7 = (flag >> 7) & 1; 

    bool bit0 = get_bit(flag,0);
    bool bit1 = get_bit(flag,1);
    bool bit2 = get_bit(flag,2);
    bool bit3 = get_bit(flag,3);
    bool bit4 = get_bit(flag,4);
    bool bit5 = get_bit(flag,5);
    bool bit6 = get_bit(flag,6);
    bool bit7 = get_bit(flag,7);
    
    string status1 = "  ON     |";
    string status2 = "  OFF    |";
    string status3 = "  FAST   |";
    string status4 = "  SLOW   |";

    string sttClimate, sttWiFi, sttBackupBattery, sttSound, sttCamera, sttPhone, sttSpeed, sttSysWarning;

    if(bit7)
        sttClimate = status1;
    else sttClimate = status2;

    if(bit6)
        sttWiFi = status1;
    else sttWiFi = status2;

    if(bit5)
        sttBackupBattery = status1;
    else sttBackupBattery = status2;

    if(bit4)
        sttSound = status1;
    else sttSound = status2;

    if(bit3)
        sttCamera = status1;
    else sttCamera = status2;
    
    if(bit2)
        sttPhone = status1;
    else sttPhone = status2;
        
    if(bit1)
        sttSpeed = status4;
    else sttSpeed = status3;

    if(bit0)
        sttSysWarning = status1;
    else sttSysWarning = status2;

    // sttSysWarning = bit0 ? status1 : status2;
    cout<< "           STATUS DEVICES" << endl;
    cout<< "========================================" << endl;
    cout<< "| Index  | Device            | Status  |" << endl;
    cout<< "========================================" << endl;
    cout<< "|    1   | Climate           |" << sttClimate << endl;
    cout<< "|    2   | WiFi              |" << sttWiFi << endl;
    cout<< "|    3   | Backup battery    |" << sttBackupBattery << endl;
    cout<< "|    4   | Sound             |" << sttSound << endl;
    cout<< "|    5   | Camera            |" << sttCamera << endl;
    cout<< "|    6   | Phone connection  |" << sttPhone << endl;
    cout<< "|    7   | Speed             |" << sttSpeed << endl;
    cout<< "|    8   | System warning    |" << sttSysWarning << endl;
    cout<< "========================================" << endl;

}

/**
 * @brief Menu lua chon cac che do dieu khien
 * 
 */
void menu_control(){
    cout<< "----------------------------------------------"<< endl;
    cout<< "=======MENU DIEU KHIEN THIET BI=======" << endl;
    cout<< "1. Thay doi trang thai Climate" << endl;
    cout<< "2. Thay doi trang thai WiFi" << endl;
    cout<< "3. Thay doi trang thai Backup battery" << endl;
    cout<< "4. Thay doi trang thai Sound" << endl;
    cout<< "5. Thay doi trang thai Camera" << endl;
    cout<< "6. Thay doi trang thai Phone connection" << endl;
    cout<< "7. Thay doi trang thai Speed" << endl;
    cout<< "8. Thay doi trang thai System warning" << endl;
    cout<< "9. Bat tat ca thiet bi" << endl;
    cout<< "10. Tat tat ca thiet bi" << endl;
    cout<< "11. Kiem tra che do Power Saving" << endl;
    cout<< "12. Xem trang thai cua tat ca cac bit" << endl;
    cout<< "0. Thoat!" << endl;
    cout<< "----------------------------------------------"<< endl;
}

int main() { 
    unsigned char flag = 0; // Khởi tạo flag với giá trị ban đầu là 0 (0b00000000)
    
    int choose;

    do{
        menu_control();
        
        cout<< "Lua chon thay doi trang thai cua thiet bi: ";
        cin >> choose;
        switch (choose){
        case 1:
            cout<< "==> 1. Thay doi trang thai Climate" << endl;
            flag = set_bit(flag, 7);
            menu_app(flag);
            break;

        case 2:
            cout<< "==> 2. Thay doi trang thai WiFi" << endl;
            flag = set_bit(flag, 6);
            menu_app(flag);
            break;

        case 3:
            cout<< "==> 3. Thay doi trang thai Backup battery" << endl;
            flag = set_bit(flag, 5);
            menu_app(flag);
            break;

        case 4:
            cout<< "==> 4. Thay doi trang thai Sound" << endl;
            flag = set_bit(flag, 4);
            menu_app(flag);
            break;

        case 5:
            cout<< "==> 5. Thay doi trang thai Camera" << endl;
            flag = set_bit(flag, 3);
            menu_app(flag);
            break;

        case 6:
            cout<< "==> 6. Thay doi trang thai Phone connection" << endl;
            flag = set_bit(flag, 2);
            menu_app(flag);
            break;

        case 7:
            cout<< "==> 7. Thay doi trang thai Speed" << endl;
            flag = set_bit(flag, 1);
            menu_app(flag);
            break;

        case 8:
            cout<< "==> 8. Thay doi trang thai System warning" << endl;
            flag = set_bit(flag, 0);
            menu_app(flag);
            break;

        case 9:
            // bật tất cả thiết bị không làm thay đổi trạng thái của SPEED
            cout<< "==> 9. Bat tat ca thiet bi" << endl;
            if(get_bit(flag, 1))
                flag = 0b11111111;
            else flag = 0b11111101;
            menu_app(flag);
            break;

        case 10:
            // tắt tất cả thiết bị không làm thay đổi trạng thái của SPEED
            cout<< "==> 10. Tat tat ca thiet bi" << endl;
            if(get_bit(flag, 1))
                flag = (1 << 2); //00000010
            else flag = 0;
            menu_app(flag);
            break;

        case 11:
            cout<< "==> 11. Kiem tra che do Power Saving" << endl;
            cout<< "========================================" << endl;
            if(check_power_saving(flag))
                cout << "==> POWER SAVING DUOC BAT !" << endl;
            else
                cout << "==> POWER SAVING DA TAT !" << endl;
            break;

        case 12:
            cout<< "==> 12. Xem trang thai cua tat ca cac bit" << endl;
            report_bits(flag);
            break;
            
        case 0:
            cout<< "==> 0. Thoat!" << endl;
            break;

        default:
            cout<< "==> ERROR: Lua chon khong hop le! Vui long nhap lai !!! " << endl;
            break;
        }

    } while ( choose != 0);    
    return 0;
}