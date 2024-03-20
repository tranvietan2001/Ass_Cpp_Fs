#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int columns;
    float** data;

public:
    Matrix(){}
    Matrix(int r, int c) {
        rows = r;
        columns = c;

        // Cấp phát bộ nhớ cho ma trận
        data = new float*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new float[columns];
        }
    }
    // Giải phóng bộ nhớ của ma trận khi đối tượng bị hủy
    // ~Matrix() {
    //     for (int i = 0; i < rows; i++) {
    //         delete[] data[i];
    //     }
    //     delete[] data;
    // }  
    // ==> Lỗi chỉ chạy được 1 chức năng là dừng chương trình. tối chạy bt, sáng chạy lỗi :)))

    void inputMatrix() {
        cout << "Nhap gia tri cho ma tran " << rows << "x" << columns << ":" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << "Nhap gia tri cho phan tu: [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    void outputMatrix() {
        cout << "Ma tran: " << rows << "x" << columns << ":" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matrix sumMatrix(const Matrix& other){
        Matrix sum_matrix (rows, columns);
        if((rows != other.rows) || (columns != other.columns)){
            cout << "==> 2 ma tran khong cung cap! Chuc nang tinh toan khong dap ung!" << endl;
        }
        else {
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    sum_matrix.data[i][j] = data[i][j] + other.data[i][j];  
                }
            }
        }
        return sum_matrix;       
    }

    Matrix subMatrix(const Matrix& other){
        Matrix sub_matrix (rows, columns);
        if((rows != other.rows) || (columns != other.columns)){
            cout << "==> 2 ma tran khong cung cap! Chuc nang tinh toan khong dap ung!" << endl;
        }
        else {
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    sub_matrix.data[i][j] = data[i][j] - other.data[i][j];  
                }
            }
        }
        return sub_matrix;       
    }

    Matrix mulMatrix(const Matrix& other){
        Matrix mul_matrix (rows, other.columns);
        if((rows != other.rows) || (columns != other.columns)){
            cout << "==> 2 ma tran khong cung cap! Chuc nang tinh toan khong dap ung!" << endl;
        }else{
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < other.columns; j++) {
                    float sum = 0;
                    for (int k = 0; k < columns; k++) {
                        sum += data[i][k] * other.data[k][j];
                    }
                    mul_matrix.data[i][j] = sum;
                }
            }
        }

        return mul_matrix;  
    }

    Matrix divMatrix(const Matrix& other){
        Matrix div_matrix (rows, columns);
        if(other.rows != other.columns){
            cout<< "==> Ma tran B khong phai ma tran vuong. Khong thuc hien duoc phep tinh nay " << endl; 
        }
        else if(((rows != other.rows) || (columns != other.columns))){
            cout << "==> 2 ma tran khong cung cap! Chuc nang tinh toan khong dap ung!" << endl;
        }
        else {
            for (int i = 0; i < rows; i++){
                    for(int j = 0; j < columns; j++){
                        if(other.data[i][j] == 0)
                            return div_matrix;
                    }
                }

           div_matrix = mulMatrix(inverseMatrix(other, other.rows));
        }
        return div_matrix;       
    }
    
    // tính định thức của ma trận
    // float det(float a[][100], int n){
    float det(Matrix a, int n){
        n = a.rows;
        int i, j, k, count = 0, check;
        float b[100], h, result = 1;

        for (i = 0; i < n - 1; i++){
            if (a.data[i][i] == 0){
                check = 0;
                for (j = i + 1; j < n; j++){
                    if (a.data[i][j] != 0){
                        for (k = 0; k < n; k++) {
                            float t = a.data[k][i];
                            a.data[k][i] = a.data[k][j];
                            a.data[k][j] = t;
                        }
                        count++;
                        check++;
                        break;
                    }
                }
                if (check == 0)
                    return 0;
            }
            
            b[i] = a.data[i][i];
            for (j = 0; j < n; j++)
                a.data[i][j] /= b[i];
            for (j = i + 1; j < n; j++)
            {
                h = a.data[j][i];
                for (k = 0; k < n; k++)
                    a.data[j][k] = a.data[j][k] - h * a.data[i][k];
            }
        }
        b[n - 1] = a.data[n - 1][n - 1];
        for (i = 0; i < n; i++)
            result *= b[i];
        if (count % 2 == 0)
            return result;
        return -result;
    }
    float con(Matrix a, int n, int h, int c) {
        n = a.rows;
        // float b[100][100];
        Matrix b;
        int i, j, x = -1, y;
        for (i = 0; i < n; i++)
        {
            if (i == h)
                continue;
            x++;
            y = -1;
            for (j = 0; j < n; j++)
            {
                if (j == c)
                    continue;
                y++;
                b.data[x][y] = a.data[i][j];
            }
        }
        if ((h + c) % 2 == 0)
            return det(b, n - 1);
        return -det(b, n - 1);
    }

    Matrix inverseMatrix( const Matrix a, int n){
        Matrix inverse;
        n = a.rows;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                inverse.data[i][j] = con(a, n, i, j);
            }
        }

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++){
                float t = inverse.data[i][j];
                inverse.data[i][j] = inverse.data[j][i];
                inverse.data[j][i] = t;
            }

        float k = det(a, n);
        if (k == 0){
            cout << "\nkhong co ma tran nghich dao!";
            inverse = Matrix();
        }
        else{
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    inverse.data[i][j] /= k;
          
        }
        return inverse;
    }

};

int main() {
    int rows_a, columns_a, rows_b, columns_b;
    char choose;
    
    cout << "==== CHUONG TRINH TINH TOAN MA TRAN ====" << endl;
    cout << " ==>Thong tin ma tran A: " << endl;
    cout << " - Nhap so hang cua ma tran A: ";
    cin >> rows_a;
    cout << " - Nhap so cot cua ma tran A : ";
    cin >> columns_a;
    Matrix matrix_A(rows_a, columns_a);
    matrix_A.inputMatrix();
    cout << "MA TRAN A => ";
    matrix_A.outputMatrix();
    cout << "-----------------------------" << endl;

    cout << " ==>Thong tin ma tran B: " << endl;
    cout << " - Nhap so hang cua ma tran B: ";
    cin >> rows_b;
    cout << " - Nhap so cot cua ma tran B : ";
    cin >> columns_b;
    Matrix matrix_B(rows_b, columns_b);
    matrix_B.inputMatrix();
    cout << "MA TRAN B => ";
    matrix_B.outputMatrix();
    cout << "-----------------------------" << endl;

    do{
        cout << "==== CHUONG TRINH TINH TOAN 2 MA TRAN ====" << endl;
        cout << "==== 1. Tong 2 ma tran                ====" << endl;
        cout << "==== 2. Hieu 2 ma tran                ====" << endl;
        cout << "==== 3. Tich 2 ma tran                ====" << endl;
        cout << "==== 4. Thuong 2 ma tran              ====" << endl;
        cout << "==== 0. Thoat chuong trinh            ====" << endl;
        cout << "==========================================" << endl;
        cout << "--> Nhap chuc nang so : ";
        cin >> choose;
        
        Matrix result(rows_a, columns_a);

        switch (choose){
        case '1':
            cout << "==> TONG 2 MA TRAN" << endl;
            result = matrix_A.sumMatrix(matrix_B);  
            cout << "===> KET QUA" << endl;
            result.outputMatrix();  
            break;
        case '2':
            cout << "==> HIEU 2 MA TRAN" << endl;
            result = matrix_A.subMatrix(matrix_B);  
            cout << "===> KET QUA" << endl;
            result.outputMatrix(); 
            
            break;
        case '3':
            cout << "==> TICH 2 MA TRAN" << endl;
            result = matrix_A.mulMatrix(matrix_B);  
            cout << "===> KET QUA" << endl;
            result.outputMatrix(); 
            
            break;
        case '4':
            cout << "==> THUONG 2 MA TRAN" << endl;
            result = matrix_A.divMatrix(matrix_B);
            // cout << result.det(matrix_A, rows_a) << endl;
            result.outputMatrix();
            break;
        case '0':
            cout << "===> THOAT CHUONG TRINH" << endl;
            break;
        default:
            cout << "===> ERROR: Lua chon khong hop le! Vui long nhap lai !!!." << endl;
            break;
        }

        

    }while(choose != '0');

  
    return 0;
}