// Viết một chương trình sử dụng namespace, và có sử dụng namespace lồng nhau

#include<iostream>
using namespace std;


namespace home{
    int a = 10;
    void address(){
        cout << "\tAddress: Quang Nam" << endl;
    }
    void color(){
        cout << "\tColor: Gray" << endl;
    }
}


namespace person {
    int old(int i){
        return i;
    }

    namespace person_VietNam{
        void skin_color(){  
            cout << "\tViet Nam da vang" << endl;
        }

        namespace nation{
            int number_nation = 54;
            void Cham_nation(){
                cout<< "\tTieng noi: Cham, Tieng Viet" <<endl;
                cout<< "\tChu viet: Champa, Quoc ngu" <<endl;
            }
            void Kinh_nation(){
                cout<< "\tTieng noi: Tieng Viet" <<endl;
                cout<< "\tChu viet: Quoc ngu" <<endl;
            }

        }
    }

    namespace person_USA{
        void skin_color(){
            cout << "\tUSA da trang" << endl;
        }
    }
}

using namespace person::person_USA;

int main(int argc, char const *argv[])
{
    
    cout << "Gia tri bien a trong namspace home: " << home::a <<endl;
    cout << "Call ham address() trong namspace home" << endl;
    home::address() ;
    cout << "Call ham color() trong namspace home: " <<endl;
    home::color();

    cout<< "------------------------------------------------------"<< endl;

    cout << "Call ham old() trong namspace person voi doi so truyen vao la 15 : " << person::old(15) <<endl;
    cout << "Call ham skin_color() trong namspace person_VietNam long trong namespace person : " <<endl;
    person::person_VietNam::skin_color();

    cout<< "------------------------------------------------------"<< endl;
    
    cout << "Call ham Cham_nation() trong namspace nation long trong person_VietNam long trong person:" << endl;
    person::person_VietNam::nation::Cham_nation();
    cout << "Call ham Kinh_nation() trong namspace nation long trong person_VietNam long trong person:" << endl;
    person::person_VietNam::nation::Kinh_nation();

    cout<< "------------------------------------------------------"<< endl;

    // su dung using namespace 
    cout << "Call ham skin_color() trong namspace person_USA long trong namespace person : " <<endl;
    skin_color(); // tuong duong voi lenh: person::person_USA::skin_color();
    

    return 0;
}
