#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;
const float PI = 3.14159;

const string file_input = "data.txt";
const string file_out = "output.txt";

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

class Shape{
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
        ostringstream oss;
        oss << "Triangle";
        return oss.str();
    }   

    string toString() override{
        ostringstream oss;
        oss << "0 " << a.getX() << " " << a.getY() << " " << b.getX() << " " << b.getY() << " " << c.getX() << " " << c.getY() << "\t\t\t" 
            << "-> 0 la type Triangle, (" << a.getX() << "," << a.getY()<< "), (" << b.getX() << "," << b.getY()<< "), ("<< c.getX() << "," << c.getY()<< ""<< ") la 3 dinh cua tam giac";
        return oss.str();
    } 

};

class Rectangle : public Shape{
    private:
        Point o;
        float w;
        float h;
    public:
        Rectangle(): o(0,0), w(0), h(0){}
        Rectangle(Point v_o, float v_w, float v_h): o(v_o), w(v_w), h(v_h){}

        float getPerimeter() override{
            float p = (h + w) * 2 ;
            return p;
        }
        float getArea() override{
            float area = h * w;
            return area;
        }
        string fromString(const string &s) override{
            ostringstream oss;
            oss << "Rectangle";
            return oss.str();
        }   

        string toString() override{
            ostringstream oss;
            oss << "1 " << o.getX() << " " << o.getY() << " " << w << " " << h << "\t\t\t\t" 
            << "-> 1 la type Recangle, (" << o.getX() << "," << o.getY()<< ") la tam, " << w << " la width," << h<< " la height";
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
            ostringstream oss;
            oss << "Cricle";
            return oss.str();
        }   

        string toString() override{
            ostringstream oss;
            oss << "2 " << o.getX() << " " << o.getY() << " " << r << "\t\t\t\t" 
            << "-> 2 la type Circle, (" << o.getX() << "," << o.getY()<< ") la tam, " << r << " la ban kinh";
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
            ostringstream oss;
            oss << "Ellipse";
            return oss.str();
        }   

        string toString() override{
            ostringstream oss;
            oss << "3 " << o.getX() << " " << o.getY() << " " << r1 << " " << r2 << "\t\t\t\t" 
            << "-> 3 la type Ellipse, (" << o.getX() << "," << o.getY()<< ") la tam, (" << r1 << "," << r2<< ") la ban kinh (rx, ry)";
            return oss.str();
        } 

};

class ShapeFactory{
    public:
        Shape* createShape(int type, const string& s) {
            istringstream iss(s);
            if (type == 0) {
                vector<float> list_value;
                float value;
                while (iss >> value){
                    // cout << value << "\t";
                    list_value.push_back(value);
                }
                // for(const float& l: list_value){
                //     cout << l << endl;
                // }
                // cout << "-------------" << endl;
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

                Point o(list_value[0], list_value[1]);
                float w = list_value[2];
                float h = list_value[3];
                return new Rectangle(o, w, h);
            }
            else if(type == 2){
                vector<float> list_value;
                float value;
                while (iss >> value){
                    list_value.push_back(value);
                }
;
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
            while (getline(inputFile, line)) {
                int type = line[0] - '0'; // chuyển string thành int, từ ký tự số thành giá trị số
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
            for (Shape* shape : shapes) {
                outputFile << shape->toString() << std::endl;
            }
            outputFile.close();
        }
};



int main(int argc, char const *argv[]){

    ShapeFactory shapeFactory;

    list<Shape*> shapes = shapeFactory.readShapesFromFile(file_input);
    for (Shape* shape : shapes) {
        // std::cout << "Shape: " << shape->toString() << std::endl;
        cout << "Shape: " << shape->fromString("") << std::endl;
        cout << "Perimeter: " << shape->getPerimeter() << std::endl;
        cout << "Area: " << shape->getArea() << std::endl;
        // cout << std::endl;
        cout << "---------------------------------" << endl;
    }
    

    shapeFactory.saveShapesToFile(file_out, shapes);

    // Cleanup
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
     