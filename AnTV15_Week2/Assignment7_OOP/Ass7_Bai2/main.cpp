#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Polygon{
    private:
        int m_num_edges;
        vector<float> m_list_edges;
    public:
        Polygon(int num_edges, vector<float> list_edges): m_num_edges(num_edges), m_list_edges(list_edges) 
        {}
        void printEdges(){
            cout << "Chieu dai cac canh: " << endl;
            for(int i= 0; i< m_num_edges; i++){
                cout << m_list_edges[i] << "\t";
            }
            cout << endl;
        }
        virtual float calculatePerimeter(){
            // cout << "Polygon class" <<endl; // check call func
            float perimetrt = 0;
            for(int i= 0; i< m_num_edges; i++){
                perimetrt = perimetrt + m_list_edges[i];
                // cout << m_arr_edges[i] << "\t"<< endl;
            }
            return perimetrt;
        }
        friend class Triangle;
        friend class Quadrilateral;
};

class Triangle : public Polygon{
    public:
        Triangle(vector<float> list_edges) : Polygon(3, list_edges){}

        float calculatePerimeter() override { 
            // cout << "Triangle class"<< endl; // check call func
            float perimeter = 0;
            for (int i = 0; i < m_num_edges; i++){
                perimeter = perimeter + m_list_edges[i];
            }
            return perimeter;
        }

        float calculateArea(){
            float area = 0;
            float p = calculatePerimeter() / 2;
            area = sqrt((p - m_list_edges[0]) * (p - m_list_edges[1]) * (p - m_list_edges[2]));
            return area;
        }

        bool checkEdgesTriangle(){
            bool status_check = false;
            int sum_edge_0_1 = m_list_edges[0] + m_list_edges[1];
            int sum_edge_0_2 = m_list_edges[0] + m_list_edges[2];
            int sum_edge_1_2 = m_list_edges[1] + m_list_edges[2];

            if((m_list_edges[0] == -1) || (m_list_edges[1] == -1) || (m_list_edges[2] == -1 )){
                status_check = false;
                cout << "===> Bi loi trong khi nhap chieu dai canh!!" << endl;
            }
            else if((m_list_edges[0] <= 0) || (m_list_edges[1] <= 0) || (m_list_edges[2] <= 0 )){
                status_check = false;
            } 
            else if ((sum_edge_0_1 > m_list_edges[2]) && 
                    (sum_edge_0_2 > m_list_edges[1]) && 
                    (sum_edge_1_2 > m_list_edges[0])){
                status_check = true;
                    }
            else status_check = false;
            return status_check;
        }

        bool checkPytago(){
            bool check_pytago = false;
            float edge_0_1 = sqrt( m_list_edges[0] * m_list_edges[0] + m_list_edges[1] * m_list_edges[1]);
            float edge_0_2= sqrt( m_list_edges[0] * m_list_edges[0] + m_list_edges[2] * m_list_edges[2]);
            float edge_1_2 = sqrt( m_list_edges[1] * m_list_edges[1] + m_list_edges[2] * m_list_edges[2]);

            if(m_list_edges[0] == edge_1_2 || m_list_edges[1] == edge_0_2 || m_list_edges[2] == edge_0_1){
                check_pytago = true;
            }
            else check_pytago = false;
            return check_pytago;
        }
};

class Quadrilateral: public Polygon{
    public:

       Quadrilateral(vector<float> list_edges) : Polygon(4, list_edges){}

        float calculatePerimeter() override { 
            // cout << "Quadrilateral class"<< endl; // check call func
            float perimeter = 0;
            for (int i = 0; i < m_num_edges; i++){
                perimeter = perimeter + m_list_edges[i];
            }
            return perimeter;
        }

        float calculateArea(){
            float area = 0;
            float p = calculatePerimeter() / 2;
            area = sqrt((p - m_list_edges[0]) * (p - m_list_edges[1]) * (p - m_list_edges[2]));
            return area;
        }

        bool checkEdgesQuadrilateral(){
            bool status_check = false;
            float sum_edge_0_1 = m_list_edges[0] + m_list_edges[1];
            float sum_edge_0_3 = m_list_edges[0] + m_list_edges[3];
            float sum_edge_1_2 = m_list_edges[1] + m_list_edges[2];
            float sum_edge_2_3 = m_list_edges[2] + m_list_edges[3];

            if((m_list_edges[0] == -1) || (m_list_edges[1] == -1) || (m_list_edges[2] == -1 ) || (m_list_edges[3] == -1 )){
                status_check = false;
                cout << "===> Bi loi trong khi nhap chieu dai canh!!" << endl;
            }
            else if((m_list_edges[0] <= 0) || (m_list_edges[1] <= 0) || (m_list_edges[2] <= 0) || (m_list_edges[3] <= 0)){
                status_check = false;
            } 
            else if ((sum_edge_0_1 > m_list_edges[2]) && 
                    (sum_edge_1_2 > m_list_edges[3]) && 
                    (sum_edge_2_3 > m_list_edges[0]) &&
                    (sum_edge_0_3 > m_list_edges[1])){
                status_check = true;
                    }
            else status_check = false;
            return status_check;
        }
};


struct structEdges{
    float a,b,c,d;
};

void funcTriangle(){
    int n;
    vector<structEdges> v_lists;
    cout << "Nhap so luong tam giac: " ;
    if(cin>>n){

        cout << "Nhap chieu dai cac canh cua " << n << " tam giac" << endl;
        for (int i = 0; i < n; i++){
            structEdges struct_edge ;
            cout << "===> Tam giac thu " << i+1 << endl;
            cout << " - Nhap chieu dai canh a: " ;
            if(cin >> struct_edge.a){
                cout << " - Nhap chieu dai canh b: " ;
                if(cin >> struct_edge.b){
                    cout << " - Nhap chieu dai canh c: " ;
                    if(cin >> struct_edge.c){
                        cout << "===> Da lua thong tin 3 canh vua nhap!" << endl;
                        v_lists.push_back(struct_edge);
                    }
                    else {
                        cin.clear();
                        cin.ignore();
                        cout << "==> Loi! Chieu dai canh nhap khong phai la so!" << endl;
                        struct_edge.c = -1;
                    }
                }
                else {
                    cin.clear();
                    cin.ignore();
                    cout << "==> Loi! Chieu dai canh nhap khong phai la so!" << endl;
                    struct_edge.b = -1;
                }
            } else {
                cin.clear();
                cin.ignore();
                cout << "==> Loi! Chieu dai canh nhap khong phai la so!" << endl;
                struct_edge.a = -1;
            }
            cout << "-------------------------------------" << endl;
        }

        cout << "=== CHU VI, DIEN TICH CUA CAC TAM GIAC ===" << endl;
        int j = 0;
        for (const structEdges& v_list : v_lists) {           
            Triangle c_tri({v_list.a,v_list.b, v_list.c});
            cout << "===> Tam Giac Thu: " << ++j <<  endl;
            c_tri.printEdges();
            if (c_tri.checkEdgesTriangle()){
                if (c_tri.checkPytago()){
                    cout<< "===> 3 canh cua ta giac thoa man dinh ly Pytago !!!"<< endl;
                }
                cout << " - Chu vi: " ;
                cout << (c_tri.calculatePerimeter()) << endl;    
                cout << " - Dien tich: " ;
                cout << (c_tri.calculateArea()) << endl;  
            }
            else {
                cout <<  "==> Chieu dai 3 canh nay khong thoa dieu kien la 3 canh cua tam giac !" << endl ;
            }
            cout << "----------------------" << endl;
        }
    }
    else cout << "n sai! "<< endl;
}

void funcQuadrilateral(){
int n;
    vector<structEdges> v_lists;
    cout << "Nhap so luong tu giac: " ;
    if(cin>>n){

        cout << "Nhap chieu dai cac canh cua " << n << " tuA giac" << endl;
        for (int i = 0; i < n; i++){
            structEdges struct_edge ;
            cout << "===> Tu giac thu " << i+1 << endl;
            cout << " - Nhap chieu dai canh a: " ;
            if(cin >> struct_edge.a){
                cout << " - Nhap chieu dai canh b: " ;
                if(cin >> struct_edge.b){
                    cout << " - Nhap chieu dai canh c: " ;
                    if(cin >> struct_edge.c){
                        cout << " - Nhap chieu dai canh d: " ;
                        if(cin >> struct_edge.d){
                            cout << "===> Da lua thong tin 4 canh vua nhap!" << endl;
                            v_lists.push_back(struct_edge);
                        }
                        else{
                            cin.clear();
                            cin.ignore();
                            cout << "==> Loi! Chieu dai canh nhap khong phai la so!" << endl;
                            struct_edge.d = -1;
                        }
                    }
                    else {
                        cin.clear();
                        cin.ignore();
                        cout << "==> Loi! Chieu dai canh nhap khong phai la so!" << endl;
                        struct_edge.c = -1;
                    }
                }
                else {
                    cin.clear();
                    cin.ignore();
                    cout << "==> Loi! Chieu dai canh nhap khong phai la so!" << endl;
                    struct_edge.b = -1;
                }
            } else {
                cin.clear();
                cin.ignore();
                cout << "==> Loi! Chieu dai canh nhap khong phai la so!" << endl;
                struct_edge.a = -1;
            }
            cout << "-------------------------------------" << endl;
        }

        cout << "=== CHU VI, DIEN TICH CUA CAC TU GIAC ===" << endl;
        int j = 0;

        for (const structEdges& v_list : v_lists) {           
            Quadrilateral c_qua({v_list.a,v_list.b, v_list.c, v_list.d});
            cout << "===> Tu Giac Thu: " << ++j <<  endl;
            c_qua.printEdges();
            if (c_qua.checkEdgesQuadrilateral()){
                
                cout << " - Chu vi: " ;
                cout << (c_qua.calculatePerimeter()) << endl;    
                cout << " - Dien tich: " ;
                cout << (c_qua.calculateArea()) << endl;  
            }
            else {
                cout <<  "==> Chieu dai 4 canh nay khong thoa dieu kien la 4 canh cua tu giac !" << endl ;
            }
            cout << "----------------------" << endl;
        }
    }
    else cout << "n sai! "<< endl;
}

int main(int argc, char const *argv[]){
  

    char choose;

    do{
        cout << "==== CHUONG TRINH DA GIAC ====" << endl;
        cout << "==== 1. Tam Giac          ====" << endl;
        cout << "==== 2. Tu Giac           ====" << endl;
        cout << "==== 0. Thoat             ====" << endl;
        cout << "==============================" << endl;
        cout << "--> Nhap chuc nang so : ";
        cin >> choose;

        switch (choose)
        {
        case '1':
            cout << "===> TAM GIAC" << endl;
            funcTriangle();
            break;
        case '2':
            cout << "===> TU GIAC" << endl;
            funcQuadrilateral();
            break;
        case '0':
            cout << "===> THOAT CHUONG TRINH" << endl;
            break;
        default:
            cout << "===> ERROR: Lua chon khong hop le! Vui long nhap lai !!!." << endl;
            break;
        }

    }while (choose != '0');

       
    return 0;
}
