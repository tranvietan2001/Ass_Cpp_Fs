#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;
const float PI = 3.14159;
class Point{
    private:
        float x;
        float y;
    public:
        Point(): x(0), y(0){}
        Point(float x_value, float y_value): x(x_value), y(y_value){}
        Point(const Point& other): x(other.x), y(other.y){}
        ~Point(){}

        float getX(){
            return x;
        }

        float getY(){
            return y;
        }

        void setX(float x_value){
            x = x_value;
        }

        void setY(float y_value){
            y = y_value;
        }

        Point operator+(const Point& other){
            return Point(x + other.x, y + other.y);
        }
        Point operator-(const Point& other){
            return Point(x - other.x, y - other.y);
        }
        Point operator*(float scalar){
            return Point(x * scalar, y * scalar);
        }
        Point operator/(float scalar){
            if (scalar == 0)
                return Point();
            else
                return Point(x / scalar, y / scalar);
        }
        Point operator+=(const Point& other){
            x += other.x;
            y += other.y;
            return *this;
            
        }
        Point operator-=(const Point& other){
            x -= other.x;
            y -= other.y;
            return *this;
            
        }
        
        Point operator*=(float scalar){
            x *= scalar;
            y *= scalar;
            return *this;
            
        }
        
        Point operator/=(float scalar){
            if (scalar == 0)
                return *this;
            else{
                x /= scalar;
                y /= scalar;
                return *this;
            }
        }

        float distance(const Point& other){
            float dx = x - other.x;
            float dy = y - other.y;
            float result = sqrt(dx * dx + dy * dy);
            return result;
        }

        // tich da huong. phep nhan 2 vector
        float dotProduct(const Point& other){
            float result = x * other.x + y * other.y;
            return result;
        }

        friend class Shape;
};

class Shape : public Point{
    private:

    public:
        
        virtual float getPerimeter() = 0;
        virtual float getArea() = 0;
        //đọc shape từ string file: số đầu tiên là type  các số tiếp theo là hình
        virtual string fromString(const string &s) = 0;
        // sau kh đọc được type từ file thì viết ra file mới những gì đọc được như type,tọa độ
        virtual string toString() = 0;
};

class Triangle : public Shape{
    private:
        Point a;
        Point b;
        Point c;
        vector<float> v_data;

    public:
        // Triangle(): a(0,0), b(0,0), c(0,0){};
        Triangle(Point x, Point y, Point z):a(x), b(y), c(z) {}
    float getPerimeter() override{
        float d_ab = a.distance(b);
        float d_ac = a.distance(c);
        float d_bc = b.distance(c);
        float perimeter = d_ab + d_ac + d_bc;
        return perimeter;
    }
    float getArea() override{
        float d_ab = a.distance(b);
        float d_ac = a.distance(c);
        float d_bc = b.distance(c);
        float p = d_ab + d_ac + d_bc;
        float px = p/2;
        float area = sqrt(px * (px - d_ab) * (px - d_ac) * (px -d_bc)) ;
        return area;
    }
    string fromString(const string &s) override{


    }   

    string toString() override{
        ostringstream oss;
        // oss << "Tri : a(" << a.getX << "," << a.getY << ")";
        oss << "Tri o()";
        return oss.str();
    } 

    void setData(float value){
        // cout << "setData()" << endl;
        v_data.push_back(value);
    }

    void getData(){
        int i;
        // cout << "getData()" << endl;
        for(const float& data : v_data){
            if(i!=v_data.size())
                cout << data << "-";
            else cout << endl; 
        }
    }
};

class Rectangle : public Shape{
    private:
        Point o;
        float h;
        float w;
    public:
        Rectangle(): o(0,0), h(0), w(0){}
        Rectangle(Point v_o, float v_h, float v_w): o(v_o), h(v_h), w(v_w){}

        float getPerimeter() override{
            float p = (h + w) * 2 ;
            return p;
        }
        float getArea() override{
            float area = h * w;
            return area;
        }
        string fromString(const string &s) override{

        }   

        string toString() override{
            ostringstream oss;
            // oss << "Rec o(" << o.getX << "," << o.getY << ")";
            oss << "Rec o()";
            return oss.str();
        } 

};

class Circle : public Shape{
    private:
        Point o;
        float r;
        float pi = PI;
    public:
        Circle(): o(0,0), r(0), pi(pi){}
        Circle(Point v_o, float v_r): o(v_o), r(v_r){}
        float getPerimeter() override{
            float p = 2 * r * pi;
            return p;

        }
        float getArea() override{
            float area = pi * r * r;
            return area;
        }
        string fromString(const string &s) override{

        }   

        string toString() override{
            ostringstream oss;
            // oss << "Cir o(" << o.getX << "," << o.getY << ")";
            oss << "Cir o()";
            return oss.str();
        } 
};

class Ellipse : public Shape{
    private:
        Point o;
        float r1;
        float r2;
        float pi = PI;
    public:
        Ellipse(): o(0,0), r1(0), r2(0), pi(PI){}
        Ellipse(Point v_o, float v_r1, float v_r2): o(v_o), r1(v_r1), r2(v_r2){}
        float getPerimeter() override{
            float p = 2 * pi * sqrt((r1 * r1 + r2 * r2) / 2);
            return p;
        }
        float getArea() override{
            float area = pi * r1 * r2;
            return area;
        }
        string fromString(const string &s) override{

        }   

        string toString() override{
            ostringstream oss;
            // oss << "Elli o(" << o.getX << "," << o.getY << ")";
            oss << "Ell o()";
            return oss.str();
        } 

};

class ShapeFactory{
    public:
        Shape* createShape(int type, const std::string& s) {
            std::istringstream iss(s);
            if (type == 0) {
                vector<float> list_value;
                float value;
                while (iss >> value){
                    list_value.push_back(value);
                }
                for(const float& l: list_value){
                    cout << l << endl;
                }
                cout << "-------------" << endl;
                Point a(list_value[0], list_value[1]);
                Point b(list_value[2], list_value[3]);
                Point c(list_value[4], list_value[5]);
                return new Triangle(a, b, c);
            }
            else if(type == 1){
                vector<float> list_value;
                float value;
                while (iss >> value){
                    list_value.push_back(value);
                }
                for(const float& l: list_value){
                    cout << l << endl;
                }
                cout << "-------------" << endl;
                Point o(list_value[0], list_value[1]);
                float h = list_value[2];
                float w = list_value[3];
                return new Rectangle(o, h, w);
            }
            else if(type == 2){
                vector<float> list_value;
                float value;
                while (iss >> value){
                    list_value.push_back(value);
                }
                for(const float& l: list_value){
                    cout << l << endl;
                }
                cout << "-------------" << endl;
                Point o(list_value[0], list_value[1]);
                float r = list_value[2];
                return new Circle(o, r );
            }
            else if(type == 3){
                vector<float> list_value;
                float value;
                while (iss >> value){
                    list_value.push_back(value);
                }
                for(const float& l: list_value){
                    cout << l << endl;
                }
                cout << "-------------" << endl;
                Point o(list_value[0], list_value[1]);
                float r1 = list_value[2];
                float r2 = list_value[3];
                return new Ellipse(o, r1, r2);
            }
            else return nullptr;
        }

        list<Shape*> readShapesFromFile(const string& filename) {
            list<Shape*> shapes;
            ifstream inputFile(filename);
            string line;
            while (std::getline(inputFile, line)) {
                int type = line[0] - '0';
                string shapeData = line.substr(2);
                Shape* shape = createShape(type, shapeData);
                if (shape != nullptr) {
                    shapes.push_back(shape);
                }
            }
            inputFile.close();
            return shapes;
        }
        void saveShapesToFile(const string& filename, const list<Shape*>& shapes) {
            ofstream outputFile(filename);
            cout << " Save" << endl;
            for (Shape* shape : shapes) {
                outputFile << shape->toString() << std::endl;
                cout << " Save" << endl;
            }
            outputFile.close();
        }
};

int main(int argc, char const *argv[]){
    // float x1,x2,y1,y2;
    // Point p1, p2;
    // cout << "_Point_" << endl;

    // cout << " Nhap toa do diem tu nhat: " << endl;
    // cout << " - x1 = ";
    // cin >> x1;
    // cout << " - y1 = ";
    // cin >> y1;
    // p1.setX(x1);
    // p1.setY(y1);

    // cout << " Nhap toa do diem tu hai: " << endl;
    // cout << " - x2 = ";
    // cin >> x2;
    // cout << " - y2 = ";
    // cin >> y2;
    // p2.setX(x2);
    // p2.setY(y2);
    // cout << "------------------------" << endl;

    // cout << "_Toa do 2 diem vua mhap_" << endl;
    // cout << "-- P1(" << p1.getX() << ", " << p1.getY() << ")" << endl;
    // cout << "-- P2(" << p2.getX() << ", " << p2.getY() << ")" << endl;
    // cout << "------------------------" << endl;

/**************************************************************/

    // ifstream input_file("data.txt");

    // string line;

    // vector<float> tri;

    // while (getline(input_file, line)){
    //     char shapType = line[0];

    //     cout<< shapType << endl;
    //     cout << " =====" << endl;
    //     if (shapType == '0'){
    //         cout << "Tam giac" << endl;
    //         Triangle c_tri;
    //         istringstream iss(line.substr(2));
    //         float x1, y1, x2,y2,x3,y3;
    //         // iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    //         // cout << x1 << "-"<< y1 <<"-"<< x2 << "-"<< y2 << "-"<< x3 << "-"<< y3 << endl;
    //         while (iss >> x1){
    //             // cout << x1 << "-";
    //             // tri.push_back(x1);
    //             c_tri.setData(x1);
    //         }
    //         // cout << endl;
    //         // cout << " -----" << endl;
    //         // for(const float& d : tri){
    //         //     cout << d ;
    //         // }
    //         // cout << endl;
    //         c_tri.getData();
            
    //     }
    //     else if (shapType == '1'){
    //         cout << "Chu Nhat" << endl;

    //         istringstream iss(line.substr(2));
    //         float o_x, o_y, h, w;
    //         iss >> o_x >> o_y >> h >> w;
    //         cout << o_x << "-"<< o_y << "-" << h << "-" << w << endl;
            
    //     }
    //     else if (shapType == '2'){
    //         cout << "Tron" << endl;

    //         istringstream iss(line.substr(2));
    //         float o_x, o_y, r;
    //         iss >> o_x >> o_y >> r ;
    //         cout << o_x << "-"<< o_y << "-" << r << endl;
                      
    //     }
    //     else if (shapType == '3'){
    //         cout << "Elip" << endl;

    //         istringstream iss(line.substr(2));
    //         float o_x, o_y, r1,r2;
    //         iss >> o_x >> o_y >> r1 >> r2;
    //         cout << o_x << "-"<< o_y << "-" << r1 << "-" << r2 << endl;
    //     }
    //     else cout << "Error type" << endl;
    // }

    // input_file.close();
    
    // ifstream inputFile("data.txt");
    // if (!inputFile) {
    //     std::cerr << "khong the mo file input.txt!" << std::endl;
    //     return 1;
    // }

    // while (getline(inputFile, line)){
    //     char shapType = line[0];
    //     cout << line.size() << endl;
    // }

    // cout << " ddd" << endl;


/**********************************************************************/

    // Đọc từng dòng trong file và ghi dữ liệu vào cuối mỗi dòng
    // std::string line_out;
    // std::ofstream outputFile("output.txt");
    // if (!outputFile) {
    //     std::cerr << "khong the tao file output.txt!" << std::endl;
    //     return 1;
    // }

    // while (std::getline(inputFile, line_out)) {
    //     std::stringstream ss(line_out);
        // int num;

        // // Ghi dữ liệu vào cuối mỗi dòng
        // while (ss >> num) {
        //     outputFile << num << "==> abc ";
        // }

        // // Ghi kết thúc dòng
        // outputFile << std::endl;

        // std::string::size_type pos = inputFile.tellg();
        // if (pos == std::string::npos || pos == line_out.length()) {
        //     std::cout << "con tro da don toi cuoi dong!" << std::endl;
        // } else {
        //     std::cout << "con tro chua doc toi cuoi dong!" << std::endl;
        // }
    // }

    // Đóng file
    // inputFile.close();
    // outputFile.close();

    // std::cout << "du leu da ghi vao output.txt!" << std::endl;
/*****************************************************/
    // ShapeFactory shape_factory;
    // string file_name = "data.txt";
    // list<Shape*> shapes = shape_factory.readShapesFromFile(file_name);

    // for(Shape* shape : shapes){
    //     // cout <<  << endl;
    // }
    // return 0;

    /*************************************/
        ShapeFactory shapeFactory;

    std::list<Shape*> shapes = shapeFactory.readShapesFromFile("data.txt");
    for (Shape* shape : shapes) {
        std::cout << "Shape: " << shape->toString() << std::endl;
        std::cout << "Perimeter: " << shape->getPerimeter() << std::endl;
        std::cout << "Area: " << shape->getArea() << std::endl;
        std::cout << std::endl;
    }
    cout << " **********************8" << endl;

    shapeFactory.saveShapesToFile("output.txt", shapes);

    // Cleanup
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
     