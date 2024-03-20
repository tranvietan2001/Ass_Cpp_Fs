#include <iostream>
#include <vector>

using namespace std;

struct SinhVien
{
    string account; // tai khoan
    string name;    // ho ten sinh vien
    string id;      // ma sinh vien
};
/**
 * @brief Giao dien menu hien thi cac chuc nang cua app.
 *
 */
void menu_app()
{
    cout << "=========================================" << endl;
    cout << "|      QUAN LY SINH VIEN TRONG LOP      |" << endl;
    cout << "=========================================" << endl;
    cout << "| 1. Nhap thong tin sinh vien.          |" << endl;
    cout << "| 2. In danh sach thong tin sinh vien.  |" << endl;
    cout << "| 3. Tim kiem theo account.             |" << endl;
    cout << "| 4. Xoa sinh vien theo ma so sinh vien.|" << endl;
    cout << "| 0. Thoat.                             |" << endl;
    cout << "| =======================================" << endl;
    cout << "Nhap phim chuc nang: " << endl;
}

/**
 * @brief Kiem tra thong tin Account nhap vao
 *
 * @param account tham so can kiem tra
 * @return true - khi thoa man tat ca dieu kien
 * @return false - khi có bat cu dieu kien nao khong thoa man
 */
bool checkAccount(string account)
{
    /*
    Điều kiện đúng: account chứa cả chữ cái và chữ số,
                    không chứa ký tự đặc biệt và dấu cách
                    chiều dài đủ 6 ký tự
    */
    bool check_number = false;
    bool check_alphabet = false;
    bool check_length = false;
    bool check_special_characters = true;
    bool check_space = true;
    bool check_all = false;

    for (char c : account)
    {
        if (isalpha(c)) // isalpha: nếu ký tự là chữ cái thì true
        {
            check_alphabet = true;
        }
        else if (isdigit(c)) // isdigit: nếu ký tự là chữ số thì true
        {
            check_number = true;
        }
        else if (isspace(c)) // isspace: nếu ký tự là dấu cách ' ' thì true
        {
            check_space = false;
        }
        else if (!isalnum(c)) //! isalnum: nếu ký tự là ký tự đặc biệt thì true
        {
            check_special_characters = false;
        }
    }

    if (account.length() == 6)
        check_length = true;

    check_all = check_number && check_alphabet && check_space && check_length && check_special_characters;
    return check_all;
}

/**
 * @brief Kiem tra thong tin Ho Ten nhap vao
 *
 * @param name tham so can kiem tra
 * @return true - khi thoa man tat ca dieu kien
 * @return false - khi có bat cu dieu kien nao khong thoa man
 */
bool checkName(string name)
{
    /*
    Điều kiện đúng: name chứa chữ cái, và dấu cách,
                    không chứa ký tự đặc biệt và chữ số
    */
    bool check_number = true;
    bool check_alphabet = false;
    bool check_length = false;
    bool check_special_characters = true;
    bool check_space = false;
    bool check_all = false;

    for (char c : name)
    {
        if (isalpha(c)) // isalpha: nếu ký tự là chữ cái thì true
        {
            check_alphabet = true;
        }
        else if (isdigit(c)) // isdigit: nếu ký tự là chữ số thì true
        {
            check_number = false;
        }
        else if (isspace(c)) // isspace: nếu ký tự là dấu cách ' ' thì true
        {
            check_space = true;
        }
        else if (!isalnum(c)) //! isalnum: nếu ký tự là ký tự đặc biệt thì true
        {
            check_special_characters = false;
        }
    }

    // if (account.length() == 6)
    //     check_length = true;

    check_all = check_number && check_alphabet && check_space && check_special_characters;
    return check_all;
}

/**
 * @brief Kiem tra thong tin Ma SV nhap vao
 *
 * @param id tham so can kiem tra
 * @return true - khi thoa man tat ca dieu kien
 * @return false - khi có bat cu dieu kien nao khong thoa man
 */
bool checkID(string id)
{
    /*
    Điều kiện đúng: id chỉ chứa các ký tự là số,
                    không chứa ký tự đặc biệt, chữ cái và khoảng trắng.
                    chiều dài đủ 6 ký tự
    */
    bool check_number = false;
    bool check_alphabet = true;
    bool check_special_characters = true;
    bool check_space = true;
    bool check_length = false;
    bool check_all = false;

    for (char c : id)
    {
        if (isalpha(c))
        { // isalpha: nếu ký tự là chữ cái thì true
            check_alphabet = false;
        }
        else if (isdigit(c))
        { // isdigit: nếu ký tự là chữ số thì true
            check_number = true;
        }
        else if (isspace(c))
        { // isspace: nếu ký tự là dấu cách ' ' thì true
            check_space = false;
        }
        else if (!isalnum(c))
        { //! isalnum: nếu ký tự là ký tự đặc biệt thì true
            check_special_characters = false;
        }
    }

    if (id.length() == 6)
        check_length = true;

    check_all = check_number && check_alphabet && check_space && check_special_characters && check_length;
    return check_all;
}

void nhapThongTinSV(vector<SinhVien> &list)
{
    cout << "***************************Luu Y***************************" << endl;
    cout << "*Account: gom 6 ky tu,phai co ca chu cai va chu so,       *" << endl;
    cout << "*         khong chua dau cach va ky tu dac biet.          *" << endl;
    cout << "*Ho Ten : chi bao gom chu cai va dau cach,                *" << endl;
    cout << "*         khong chua chu so va ky tu dac biet             *" << endl;
    cout << "*Ma SV  : gom 6 ky tu,chi chua chu so,                    *" << endl;
    cout << "*         khong chua chu cai, dau cach va ky tu dat biet. *" << endl;
    cout << "***********************************************************" << endl;
    cout << endl;


    SinhVien sv;
    string account_check, id_check, name_check;
    bool check_status = false;

    cout << "Nhap Account: ";
    cin.ignore();
    getline(cin, account_check);

    cout << "Nhap Ho Ten: ";
    // cin.ignore();
    getline(cin, name_check);

    cout << "Nhap MaSV: ";
    // cin.ignore();
    getline(cin, id_check);

    
    if (checkAccount(account_check)  && checkName(name_check) && checkID(id_check))
    {
        for (SinhVien &sv : list)
        {
            if (sv.account == account_check || sv.id == id_check)
            {
                check_status = true;
            }
        }

        if (check_status == true)
        {
            cout << "==> Account hoac Ma Sinh Vien da co, vui long kiem tra va nhap lai !" << endl;
        }
        else
        {
            sv.account = account_check;
            sv.name = name_check;
            sv.id = id_check;
            
            list.push_back(sv);
            cout << "==> Nhap Thanh Cong !!!" << endl;

            cout << "====Thong tin sinh vien vua nhap====" <<endl ;
            cout << "\tAccount: " << sv.account << endl ;
            cout << "\tHo Ten : " << sv.name << endl ;
            cout << "\tMaSV   : " << sv.id << endl ;
            cout << "====================================" <<endl ;

        }
    }
    else
        cout << "===> Thong tin nhap chua dung dinh dang, vui long kiem tra va nhap lai!" << endl;

    // cerr << "nhapThongTinSV called !" << endl;
}

void inThongTinSV(vector<SinhVien> &list)
{
    SinhVien sv;
    int i = 0;
    cout << "STT"
         << "\tACCOUNT"
         << "\tNAME"
         << "\tID" << endl;
    for (SinhVien &sv : list)
    {
        i++;
        cout << i;
        cout << "\t" << sv.account;
        cout << "\t" << sv.name;
        cout << "\t" << sv.id << endl;
    }
    cout << "Danh sach co " << list.size() << " sinh vien" << endl;
}

void timKiemAccount(vector<SinhVien> &list)
{
    SinhVien sv, sv_find;
    string name_find;
    vector<SinhVien> list_sv_find;
    cout << "Nhap Account muon tim kiem:" << endl;
    cin >> name_find;

    for (SinhVien &sv : list)
    {
        if (sv.account == name_find)
        {
            sv_find.account = sv.account;
            sv_find.name = sv.name;
            sv_find.id = sv.id;
            list_sv_find.push_back(sv_find);
        }
    }
    if (list_sv_find.size() > 0)
    {
        cout << "Tim thay Account" << endl;
        inThongTinSV(list_sv_find);
    }
    else
        cout << "Khong tim thay Account" << endl;
}

void xoaSVID(vector<SinhVien> &list)
{
    SinhVien sv;
    string id_delete;
    int dem = 0, tam = 0;

    cout << "Nhap MaSV muon xoa:" << endl;
    cin >> id_delete;
    for (SinhVien &sv : list)
    {
        dem++;
        if (sv.id == id_delete)
        {
            tam++;
            cout << "Da tim thay id can xoa !\n Ban co chac muon xoa SV nay khong ?" << endl;
            cout << "Nhan y/n de xac nhan: " << endl;
            char c;
            cin >> c;
            if (c == 'y' || c == 'Y')
            {
                list.erase(list.begin() + dem - 1);
                cout << "===> Xoa thanh cong!" << endl;
                cout << "====Danh Sach Sinh Vien Con Lai====" << endl;
                inThongTinSV(list);
            }
            else
                cout << "===> Huy yeu cau xoa" << endl;
        }
    }
    if (tam == 0)
    {
        cout << "===> Khong tim thay ID sinh vien muon xoa!" << endl;
    }

}
int main(int argc, char const *argv[])
{
    vector<SinhVien> listSV;
    char chooese;

    do
    {           
        menu_app();
        cin >> chooese;
        cout << "Ban lua chon chuc nang \t" << chooese << endl;
        switch (chooese)
        {
        case '1':
            cout << "===> NHAP THONG TINH SINH VIEN" << endl;
            nhapThongTinSV(listSV);
            break;
        case '2':
            cout << "===> IN THONG TIN SINH VIEN DA NHAP" << endl;
            inThongTinSV(listSV);

            break;
        case '3':
            cout << "===> TIM KIEM SINH VIEN THEO ACCOUNT" << endl;
            timKiemAccount(listSV);

            break;
        case '4':
            cout << "===> XOA SINH VIEN THEO MA SO SNH VIEN" << endl;
            xoaSVID(listSV);
            break;
        case '5':
            cout << "===> IN DANH SACH SINH VIEN CON LAI" << endl;
            break;
        case '0':
            cout << "===> THOAT KHOI CHUONG TRINH" << endl;
            break;
        default:
            cout << "===> ERROR: Lua chon khong hop le! Vui long nhap lai !!!." << endl;
            break;
        }

    } while (chooese != '0');

    return 0;
}
