#include <iostream>
#include <vector>

using namespace std;

// class Receipt;


/**
 * @brief Quản lý thông tin khách hành
 */
class Customer{
    private:
        string m_name;
        string m_addredd;
        string m_code;

    public:
        // Customer(string name, string address, string code): m_name(name), m_addredd(address), m_code(code){}

        /**
         * @brief Nhập thông tin khách hàng
         */
        void enterInforCustomer(){
            cout << "->Nhap ho ten chu ho: ";
            getline(cin, m_name);
            cout << "->Nhap dia chi: ";
            getline(cin, m_addredd);
            cout << "->Nhap ma cong to dien: ";
            getline(cin, m_code);
        }

        /**
         * @brief Hiển thị thông tin khách hàng
         */
        void displayInforCustomer(){
            cout << "  - Ho Ten Chu Ho  :" << m_name << endl;
            cout << "  - Dia Chi        :" << m_addredd << endl;
            cout << "  - Ma Cong To Dien:" << m_code << endl;
        }    

        friend class Receipt; // class Receipt duoc kha bao laf fried Customer
        
};

/**
 * @brief Quản lý sử dụng và thông tin hóa đơn tiền sử dụng điện của khách hàng
 */
class Receipt : public Customer {
    private:
        int m_last_index = 0;
        int m_new_index = 0;
        int m_pay = 0;
    public:
        /**
         * @brief Nhập thông tin về chỉ số điện sử dụng
         * 
         */
        void enterIndexElectric(){
            cout << "->Nhap Chi So Dien Cu: " ;
            cin >> m_last_index;
            cout << "->Nhap Chi So Dien Moi: ";
            cin >> m_new_index;              
        }

        /**
         * @brief hiển thị thông tin chỉ số điện sử dụng
         */
        void displayIndexElectric(){
            cout << "  - Chi So Dien Cu: " << m_last_index << endl;
            cout << "  - Chi So Dien Moi: " << m_new_index << endl;
            if(m_new_index < m_last_index){
                cout << "  - Chi So Dien Dung: ERROR" << endl;
                cout << "  ===>Loi Nhap! Chi so dien moi phai lon hon hoac bang chi so dien cu!"<<endl;
                return;
            }
            else cout << "  - Chi So Dien Dung: " << (m_new_index - m_last_index) << endl;
        }

        /**
         * @brief Tính tiền điện sử dụng
         * 
         * @param lastIndex Chỉ số điện sử dụng cũ
         * @param newIndex  Chỉ số điện sử dụng mới
         * @return int Số tiền điện phải đã sử dụng
         */
        int countReceipt(int lastIndex, int newIndex){
            int index = m_new_index - m_last_index;
            if (index < 0)
                m_pay = 0;
            else if( index >= 0 && index < 50){
                m_pay = index * 1250;
            }
            else if (index >= 50 && index < 100){
                m_pay = ((index - 50) * 1500) + (50 * 1250);
            }
            else m_pay = ((index - 100) * 2000) + (50 * 1500) + (50 * 1250);

            return m_pay;
        }

        /**
         * @brief nhập thông tin hóa đơn, bao gồm thông tin khách hàng và chỉ số điện sử dụng
         */
        void enterInforReceipt(){
            enterInforCustomer();
            enterIndexElectric();
        }

        /**
         * @brief Hiển thị thông tn hóa đơn sử dụng điện của khách hàng
         */
        void dispayReceipt(){
            cout << "=== THONG TIN BIEN LAI ===" << endl;
            displayInforCustomer();
            displayIndexElectric();
            cout << "  ===> Tien Dien Phai Nop: " << countReceipt(m_last_index, m_new_index) <<endl;
        }
};

int main(int argc, char const *argv[]){
    Receipt receipt;        
    vector<Receipt> m_list_receipt;

    int n;  

    cout << "===CHUONGN TRINH QUAN LY TIEN DIEN===" << endl;
    cout << "Nhap so chu ho su dung dien: ";
    if(!(cin >> n)){
        cout << "==> ERROR: Nhap sai kieu du lieu." << endl;

    }
    else{
        // cin.ignore();
        for (int i = 0;i < n; i++){
            cout << "Nhap thong tin Khach Hanh Thu " << i+1 << endl;
            cin.ignore();
            receipt.enterInforReceipt();
            m_list_receipt.push_back(receipt);
        }
        
    }
    cout << "=========================" << endl;

    cout << "Thong tin " << n << " Chu ho" << endl;
    int j = 0;
    for(Receipt& rec : m_list_receipt){
        cout << "=========================================" << endl;
        cout << "*** Chu Ho Thu " << ++j << " ***" <<endl;
        rec.dispayReceipt();
        cout << "=========================================" << endl;
    }

    
    return 0;
}
