#include <iostream>
#include <vector>

using namespace std;

const float price2 = 20; // 20 đô giá hạng bình dân (2)
const float price1 = 30; // 30 đô giá hạng vip (1)

class HUMAN{
    private:
        string m_full_name;
        int m_birth_year;
        string m_id;

    public:
    HUMAN(){}
    //dùng & trong constructor giúp tránh sao chép dữ liệu không cần thiết;
    // truyền tham chiếu ko tạo ra bản sao dữ liệu mà chỉ truyền địa chỉ của biến đó =>gảm tg và bộ nhớ cần thiết
    HUMAN(string& full_name, int birth_year, string& id): m_full_name(full_name), m_birth_year(birth_year), m_id(id){}

    string getFullName() const{
        return m_full_name;
    }
    int getBirthYear(){
        return m_birth_year;
    }
    string getID(){
        return m_id;
    }
    // void setFullName(string full_name){
    //     m_full_name = full_name;
    // }
    // void setBirthYear(int birth_year){
    //     m_birth_year = birth_year;
    // }
    // void setID(string id){
    //     m_id = id;
    // }

    void inputInfor(){
        cout << "-> Nhap ho va ten : " ;
        cin.ignore();
        getline(cin, m_full_name);
        cout << "-> Nhap nam sinh: ";
        cin >> m_birth_year;
        cout << "-> Nhap so CNND/CCCD: ";
        cin.ignore();
        getline(cin, m_id);
    }
    virtual void outputInfor() = 0;
};

class HOTEL : public HUMAN{
    private:
        int m_date;
        int m_type_room; // 2: binh danh va 1 :thuong gia vip
        float m_price_room;

        
    public:
        HOTEL(){}
        HOTEL(int date, int type_room): m_date(date),  m_type_room(type_room){}

        int getDate(){ return m_date; }
        int getTypeRoom(){ return m_type_room; }
        float getPriceRoom(){ return m_price_room;}
        
        void inputInforHotel(){
            inputInfor();
            cout << "-> Nhap so ngay o tro: " ;
            cin >> m_date;
            cout << "-> Nhap loai phong: ";
            cin >> m_type_room;
            // cout << "-> Gia phong"
            cout << "==========================" << endl;
        }
        void outputInfor() override{
            cout << "================================" << endl;
            cout << "- Ho va ten: " << getFullName() << endl;
            cout << "- Nam sinh: " << getBirthYear() << endl;
            cout << "- So CNND/CCCD: " << getID() << endl;
            cout << "- So ngay o tro: " << m_date << endl;
            cout << "- Loai phong: " << m_type_room << endl;
            cout << "================================" << endl;
        }

        // float priceRoom(int )

};

void searchInfor(vector<HOTEL> &list, string name_search){
    vector<HOTEL> list_search;
    for(HOTEL& h : list){
        if(name_search == h.getFullName()){
            list_search.push_back(h);
        }
    }
    if(list_search.size() > 0){
        cout << "-> Tim thay thong tin khach tro" << endl;
        for(int j = 0; j < list_search.size(); j++){
            cout << "->Thong tin khach tro thu " << j + 1 << endl;
            list_search[j].outputInfor();
        }
    }
    else cout << "-> Khong tim thay thong tin khach tro" << endl;
    
}

void payHoltel(vector<HOTEL> &list, string name_search) {
    vector<HOTEL> list_search;
    for(HOTEL& h : list){
        if(name_search == h.getFullName()){
            list_search.push_back(h);
        }
    }
    if(list_search.size() > 0){
        cout << "-> Tim thay thong tin khach tro" << endl;
        for(int j = 0; j < list_search.size(); j++){
            float pay = 0;
            if(list_search[j].getTypeRoom() == 1){
                pay = price1 * list_search[j].getDate();
            }
            else if(list_search[j].getTypeRoom() == 2){
                pay = price2 * list_search[j].getDate();
            }
            else {
                pay = 0;
                cout << "====> Loai phong khong chinh xac! Kiem tra dieu chinh lai!" << endl;
            }
            cout << "-> So tien phai thanh toa cua khach tro thu " << j + 1 << endl;
            cout << "***Phong loai 1: don gia 30$ 1 ngay***" << endl;
            cout << "***Phong loai 2: don gia 20$ 1 ngay***" << endl;
            cout << "==========================" << endl;
            cout << "==> So ngay o : " << list_search[j].getDate() << endl;
            cout << "==> Loai Phong: " << list_search[j].getTypeRoom() << endl;
            cout << "==> Tong thanh toan: " << pay << "$" << endl;
            cout << "==========================" << endl;
        }
    }
    else cout << "-> Khong tim thay thong tin khach tro" << endl;

}

void menu(){
    cout << "==========QUAN LY KHACH SAN==========" << endl;
    cout << "| 1. Nhap thong tin khach tro.      |" << endl;
    cout << "| 2. Hien thi thong tin khach tro.  |" << endl;
    cout << "| 3. Tim kiem thong tin khach tro.  |" << endl;
    cout << "| 4. Thanh toan tra phong.          |" << endl;
    cout << "| 0. Thoat khoi chuong trinh.       |" << endl;
    cout << "=====================================" << endl;
    cout << "-> Lua chon chuc nang so: ";
}

int main(int argc, char const *argv[]){
    HOTEL hotel;
    vector<HOTEL> list_hotel;
    char choose;

    do{
        string name_search;
        menu();
        cin >> choose;

        switch (choose){
        case '1':
            int n;
            cout << "==> NHAP THONG TIN KHACH TRO" << endl;
            cout << "-> Nhap so luong khach tro: ";
            cin >> n;

            cout << "==> Nhap thong tin cho " << n << " khach tro" << endl;
            cout << "--------------------------------------------" << endl;
            for(int i = 0; i < n; i++){
                cout << "=> Khach tro thu " << i+1 << endl;
                hotel.inputInforHotel();
                list_hotel.push_back(hotel);
                // h.outputInfor();
                }
            break;
        case '2':
            cout << "==> HIEN THI THONG TIN KHACH TRO" << endl;
            cout << "-> Thong tin cua " << list_hotel.size() << " khach tro." << endl;
            for(int j = 0; j < list_hotel.size(); j++){
                cout << "->Thong tin khach tro thu " << j + 1 << endl;
                list_hotel[j].outputInfor();
            }
            break;
        case '3':
            name_search = "";
            cout << "==> TIM KIEM THONG TIN KHACH TRO THEO HO VA TEN" << endl;
            cout << "--> Nhap ho va ten muon tim kiem: " ;
            cin.ignore();
            getline(cin, name_search);
            searchInfor(list_hotel, name_search);
            break;
        case '4':
            name_search = "";
            cout << "==> THANH TOAN TRA PHONG" << endl;
            cout << "--> Nhap ho va ten khach tro muon thanh toan: " ;
            cin.ignore();
            getline(cin, name_search);
            payHoltel(list_hotel, name_search);

            break;
        case '0':
            cout << "==> THOAT KHOI CHUONG TRINH" << endl;
            break;
        
        default:
            cout << "===> ERROR: LUA CHON KHONG HOP LE! VUI LONG KIEM TRA VA LUA CHON LAI!" << endl;
            break;
        }

    }while(choose != '0');

    
    // cin.ignore();
    
    
    
    return 0;
}
