#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HUMAN{
    private:
        string m_name;
        string m_id_number;
        int m_age;
        int m_year_birth;
        string m_job;
    public:
        HUMAN(string name, string id_number, int age, int year_birth, string job): m_name(name), m_id_number(id_number), m_age(age), m_year_birth(year_birth), m_job(job){}
        
        void displayInforHuman() const{
            cout << "- Ho va ten: " << m_name << endl;
            cout << "- So CMND/CCCD: " << m_id_number << endl;
            cout << "- Tuoi: " << m_age << endl;
            cout << "- Nam sinh: " << m_year_birth << endl;
            cout << "- Nghe nghiep: " << m_job << endl;
        }
};

class TOWN {
    private:
        string m_number_house;
        vector<HUMAN> list_infor_human;

    public:
        TOWN(const string& num_house): m_number_house(num_house) {}


        void addInforHuman(const HUMAN& inforHuman){
            list_infor_human.push_back(inforHuman);
        }

        void displayInforTown() const{
            cout << "== Dia chi Nha: " << m_number_house << endl;
            cout << "-----------------------------" << endl;
            cout << "Thanh vien trong ho" << endl;
            for(const HUMAN& human : list_infor_human){
                human.displayInforHuman();
                cout << "-----------------------------" << endl;
            } 
        }

        void findNumberHouse(const string number_house_find){
            if(number_house_find == m_number_house){
                cout << "---> Thong tin tim kiem duoc" << endl;
                for(const HUMAN& human : list_infor_human){
                    human.displayInforHuman();
                    cout << "-----------------------------" << endl;
                } 
            }
            else cout << "--> Khong tim thay thong tin" << endl ;

        }

        void findName(const string name_find){

        }
};

// void inputInforFamily(){
//     TOWN town;
//     vector<HUMAN> list_infor;

//     cout << "Ho Ten: ";
//     getline(cin, town.addInforHuman);

//     town.addInforHuman()
// }

// void outputInforFamily(){

// }

void menu(){
    cout << "=========QUAN LY DAN CU=========" << endl;
    cout << "|| 1. Nhap thong tin.         ||" << endl;
    cout << "|| 2. Tim kiem thong tin.     ||  " << endl;
    cout << "|| 3. Hien thi thong tin.     ||" << endl;
    cout << "|| 0. Thoat khoi chuong trinh.||" << endl;
    cout << "=================================" << endl;
    cout << "-> Lua cho chuc nang: ";

}
int main(int argc, char const *argv[]){
    vector<TOWN> list_town;
    char choose;
    do{
        menu();
        cin >> choose;
        cout << "BAN LUA CHON CHUC NANG " << choose << endl;

        switch (choose)
        {
        case '1':
            cout << "===> NHAP THONG TIN CAC HO DAN" << endl;
            int n;
            cout << "----------------------------------"<< endl; 
            cout << "-> Nhap so ho dan: ";
            cin >> n;

            // vector<TOWN> list_town;
            cin.ignore();
            for (int i = 0; i < n; i++) {
                string number_house;
                cout << "  -> Nhap so nha/dia chi cua ho dan " << i + 1 << ": ";     
                getline(cin, number_house);

                int m;
                cout << "  -> Nhap so thanh vien cua  ho dan " << i + 1 << ": ";
                cin >> m;

                TOWN town(number_house);
                cin.ignore();
                for (int j = 0; j < m; j++) {
                    string name;
                    string id_number;
                    int age;
                    int year_birth;
                    string job;

                    cout << "==> Nhap thong tin thanh vien " << j + 1 << ":\n";
                    cout << " ==> Ho va ten: " ;
                    // cin.ignore();
                    getline(cin, name);
                    cout << " ==> So CMND/CCCD: ";
                    cin >> id_number; 
                    cout << " ==> Tuoi: ";
                    cin >> age ;
                    cout << " ==> Nam sinh: ";
                    cin >> year_birth;
                    cout << " ==> Nghe nghiep: " ;
                    cin.ignore();
                    getline(cin, job);
                    cout << "----------------------------------"<< endl;
                    HUMAN human(name, id_number, age, year_birth, job);
                    town.addInforHuman(human);
                }

                list_town.push_back(town);
            }

            break;

        case '2':
            cout << "===> TIM KIEM THONG TIN" << endl;
            char c_find;
            do{ 
                cout << "  ==> Tim kiem thong tin ve ho dan" << endl;
                cout << "   --> 1. Tim kiem theo ho va ten. " << endl;
                cout << "   --> 2. Tim kiem theo so nha." << endl;
                cout << "   --> 0. Thoat khoi chuc nang!." << endl;
                cout << "------------------------------------" << endl;
                cout << "--> Lua chon chuc nang tim kiem: ";
                cin >> c_find;
                
                string str= "";

                switch (c_find){
                case '1':
                    cout <<"===>TIM KIEM THEO HO VA TEN" << endl;
                    break;
                case '2':
                    cout <<"===>TIM KIEM THEO SO NHA" << endl;
                    
                    cout<< "Nhap so nha muon tin kiem: " ;
                    cin.ignore();
                    getline(cin, str);
                    cout <<  "So nha can tim kiem: " << str << endl;

                    for (int i = 0; i < list_town.size(); i++) {
                        
                        cout << "------------------------------" << endl;
                        cout << "== Ho dan " << i + 1 << ":\n";
                        list_town[i].findNumberHouse(str);
                        cout << endl;
                    }

                    break;
                case '0':
                    cout << "THOAT KHOI CHUC NANG TIM KIEM" << endl;
                    break;
                
                default:
                    cout << "===> ERROR: LUA CHON KHONG HOP LE! VUI LONG KIEM TRA VA LUA CHON LAI!" << endl;
                    break;
                }

            }while(c_find !='0');

            break;
        case '3':
            cout << "===> HIEN THI THONG TIN CAC HO DAN" << endl;
            
            cout << "==============================" << endl;
            cout << "THONG TIN CAC HO DAN DA NHAP\n";
            // for (int i = 0; i < n; i++) {
            for (int i = 0; i < list_town.size(); i++) {
                cout << "------------------------------" << endl;
                cout << "== Ho dan " << i + 1 << ":\n";
                list_town[i].displayInforTown();
                cout << endl;
            }

            break;
        case '0':
            cout << "===> THOAT KHOI CHUONG TRINH" << endl;
            /* code */
            break;
        default:
            cout << "===> ERROR: LUA CHON KHONG HOP LE! VUI LONG KIEM TRA VA LUA CHON LAI!" << endl;
            break;
        }

    }while (choose != '0');

    return 0;
}
