#include <iostream>
#include <vector>

using namespace std;

class HUMAN{
    private:
        string m_name;
        string m_id_number;
        int m_age;
        int m_year_birth;
        string m_job;
    public:
        HUMAN():m_name(), m_id_number(), m_age(), m_year_birth(), m_job(){}
        HUMAN(string name, string id_number, int age, int year_birth, string job): m_name(name), m_id_number(id_number), m_age(age), m_year_birth(year_birth), m_job(job){}
        
        virtual void addInforHuman(const HUMAN& inforHuman) = 0;

        void displayInforHuman(){
            cout << "Ho va ten: " << m_name << endl;
            cout << "So CMND/CCCD: " << m_id_number << endl;
            cout << "Tuoi: " << m_age << endl;
            cout << "Nam sinh: " << m_year_birth << endl;
            cout << "Nghe nghiep: " << m_job << endl;
        }
};

class TOWN : public HUMAN {
    private:
        int m_number_member;
        string m_number_house;
        vector<HUMAN> list_infor_human;

    public:
        TOWN(): number_house(), list_infor_human(){}
        TOWN(string num_house): m_number_house(num_house) {}

        void addInforHuman(const HUMAN& inforHuman) override{
            list_infor_human.push_back(inforHuman);
        }



};

void inputInforFamily(){
    TOWN town;
    vector<HUMAN> list_infor;

    cout << "Ho Ten: "
    getline(cin, )

    town.addInforHuman()
}

void outputInforFamily(){

}

int main(int argc, char const *argv[])
{
    int n = 0;
    cout << "Nhap n ho dan: " ;
    if(cin >> n){

    }
    return 0;
}
