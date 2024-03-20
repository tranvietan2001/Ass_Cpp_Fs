// // // #include <fstream>
// // // #include <iostream>
// // // using namespace std;
 
// // // int main (){
    
// // //    char data[100];

// // //    // mo mot file trong che do write.
// // //    ofstream outfile;
// // //    outfile.open("data_test.txt");

// // //    cout << "Ghi du lieu toi file!" << endl;
// // //    cout << "Nhap ten cua ban: "; 
// // //    cin.getline(data, 100);

// // //    // ghi du lieu da nhap vao trong file.
// // //    outfile << data << endl;

// // //    cout << "Nhap tuoi cua ban: "; 
// // //    cin >> data;
// // //    cin.ignore();
   
// // //    // ghi du lieu da nhap vao trong file.
// // //    outfile << data << endl;

// // //    // dong file da mo.
// // //    outfile.close();

// // //    // mo mot file trong che do read.
// // //    ifstream infile; 
// // //    infile.open("data_test.txt"); 
 
// // //    cout << "\n===========================\n" ;
// // //    cout << "Doc du lieu co trong file!" << endl; 
// // //    infile >> data; 

// // //    // ghi du lieu tren man hinh.
// // //    cout << data << endl;
   
// // //    // tiep tuc doc va hien thi du lieu.
// // //    infile >> data; 
// // //    cout << data << endl; 

// // //    // dong file da mo.
// // //    infile.close();

// // //    return 0;
// // // }


// // #include <iostream>
// // #include <fstream>
// // #include <sstream>
// // #include <vector>

// // // hình vuông
// // class Square {
// // private: 
// //     std::vector<int> coordinates;

// // public:
// //     Square(const std::vector<int>& coords) : coordinates(coords) {}

// //     void printCoordinates() const {
// //         std::cout << "Square coordinates: ";
// //         for (size_t i = 0; i < coordinates.size(); i += 2) {
// //             std::cout << "(" << coordinates[i] << "," << coordinates[i + 1] << ") ";
// //         }
// //         std::cout << std::endl;
// //     }
// // };

// // class Triangle {
// // private:
// //     std::vector<int> coordinates;

// // public:
// //     Triangle(const std::vector<int>& coords) : coordinates(coords) {}

// //     void printCoordinates() const {
// //         std::cout << "Triangle coordinates: ";
// //         for (size_t i = 0; i < coordinates.size(); i += 2) {
// //             std::cout << "(" << coordinates[i] << "," << coordinates[i + 1] << ") ";
// //         }
// //         std::cout << std::endl;
// //     }
// // };

// // int main() {
// //     std::ifstream inputFile("data.txt");
// //     std::string line;
    
// //     while (std::getline(inputFile, line)) {
// //         char shapeType = line[0];
// //         std::vector<int> coords;
        
// //         std::istringstream iss(line.substr(2));
// //         int x, y;
// //         while (iss >> x >> y) {
// //             coords.push_back(x);
// //             coords.push_back(y);
// //         }
        
// //         if (shapeType == '0') {
// //             Square square(coords);
// //             square.printCoordinates();
// //         } else if (shapeType == '1') {
// //             Triangle triangle(coords);
// //             triangle.printCoordinates();
// //         }
// //     }
    
// //     inputFile.close();
    
// //     return 0;
// // }


// // // #include <iostream>
// // // #include <fstream>
// // // #include <sstream>
// // // #include <string>
// // // #include <list>
// // // #include <math.h>

// // // class Shape {
// // // public:
// // //     virtual ~Shape() {}

// // //     virtual double getPerimeter() const = 0;
// // //     virtual double getArea() const = 0;
// // //     virtual std::string toString() const = 0;
// // // };

// // // class Rectangle : public Shape {
// // // private:
// // //     double width;
// // //     double height;

// // // public:
// // //     Rectangle(double width, double height) : width(width), height(height) {}

// // //     double getPerimeter() const override {
// // //         return 2 * (width + height);
// // //     }

// // //     double getArea() const override {
// // //         return width * height;
// // //     }

// // //     std::string toString() const override {
// // //         std::ostringstream oss;
// // //         oss << "Rectangle - Width: " << width << ", Height: " << height;
// // //         return oss.str();
// // //     }
// // // };

// // // class Triangle : public Shape {
// // // private:
// // //     double base;
// // //     double height;

// // // public:
// // //     Triangle(double base, double height) : base(base), height(height) {}

// // //     double getPerimeter() const override {
// // //         return base + 2 * sqrt(base * base / 4 + height * height);
// // //     }

// // //     double getArea() const override {
// // //         return 0.5 * base * height;
// // //     }

// // //     std::string toString() const override {
// // //         std::ostringstream oss;
// // //         oss << "Triangle - Base: " << base << ", Height: " << height;
// // //         return oss.str();
// // //     }
// // // };

// // // class ShapeFactory {
// // // public:
// // //     Shape* createShape(int type, const std::string& s) {
// // //         std::istringstream iss(s);
// // //         double val1, val2;
// // //         iss >> val1 >> val2;
// // //         if (type == 0) {
// // //             return new Rectangle(val1, val2);
// // //         } else if (type == 1) {
// // //             return new Triangle(val1, val2);
// // //         }
// // //         return nullptr;
// // //     }

// // //     std::list<Shape*> readShapesFromFile(const std::string& filename) {
// // //         std::list<Shape*> shapes;
// // //         std::ifstream inputFile(filename);
// // //         std::string line;
// // //         while (std::getline(inputFile, line)) {
// // //             int type = line[0] - '0';
// // //             std::string shapeData = line.substr(2);
// // //             Shape* shape = createShape(type, shapeData);
// // //             if (shape != nullptr) {
// // //                 shapes.push_back(shape);
// // //             }
// // //         }
// // //         inputFile.close();
// // //         return shapes;
// // //     }

// // //     void saveShapesToFile(const std::string& filename, const std::list<Shape*>& shapes) {
// // //         std::ofstream outputFile(filename);
// // //         for (const Shape* shape : shapes) {
// // //             outputFile << shape->toString() << std::endl;
// // //         }
// // //         outputFile.close();
// // //     }
// // // };

// // // int main() {
// // //     ShapeFactory shapeFactory;

// // //     std::list<Shape*> shapes = shapeFactory.readShapesFromFile("data.txt");
// // //     for (Shape* shape : shapes) {
// // //         std::cout << "Shape: " << shape->toString() << std::endl;
// // //         std::cout << "Perimeter: " << shape->getPerimeter() << std::endl;
// // //         std::cout << "Area: " << shape->getArea() << std::endl;
// // //         std::cout << std::endl;
// // //     }

// // //     shapeFactory.saveShapesToFile("output.txt", shapes);

// // //     // Cleanup
// // //     for (Shape* shape : shapes) {
// // //         delete shape;
// // //     }

// // //     return 0;
// // // }


// // #include <iostream>
// // #include <fstream>
// // #include <string>

// // void writeDataAtPosition(const std::string& filename, int position, const std::string& data) {
// //     std::fstream file(filename, std::ios::in | std::ios::out);
// //     if (!file) {
// //         std::cerr << "khong the mo file " << filename << "!" << std::endl;
// //         return;
// //     }

// //     // Đưa con trỏ đọc/ghi tới vị trí xác định
// //     file.seekp(position, std::ios::beg);

// //     // Ghi dữ liệu vào vị trí xác định
// //     file << data;

// //     file.close();
// // }

// // int main() {
// //     std::string filename = "data.txt";
// //     std::string line;
// //     std::ifstream inputFile(filename);
// //     // std::ofstream outFile("output.txt");
// //     std::fstream file("data_test.txt", std::ios::in | std::ios::out);
// //     int i = 0;
// //     while (getline(inputFile, line)){
// //         std::cout << line.size() << std::endl;
// //         std:: cout << ++i << std::endl;
// //         // file.seekp(line.size(), std::ios::beg);
// //         // file << "==>";
// //     }
// //     inputFile.close();
// //     // outFile.close();
// //     return 0;
// // }


// // #include <iostream>
// // #include <fstream>
// // #include <vector>
// // #include <sstream>

// // void appendDataToLines(const std::string& filename, const std::string& data) {
// //     std::ifstream inputFile(filename);
// //     if (!inputFile) {
// //         std::cerr << "Không thể mở file " << filename << "!" << std::endl;
// //         return;
// //     }

// //     std::vector<std::string> lines;
// //     std::string line;
// //     while (std::getline(inputFile, line)) {
// //         line += " " + data;
// //         lines.push_back(line);
// //     }

// //     inputFile.close();

// //     std::ofstream outputFile(filename);
// //     if (!outputFile) {
// //         std::cerr << "Không thể tạo file " << filename << "!" << std::endl;
// //         return;
// //     }

// //     for (const std::string& line : lines) {
// //         outputFile << line << std::endl;
// //     }

// //     outputFile.close();
// // }

// // int main() {
// //     std::string filename = "data.txt";
// //     std::string data = "new data";

// //     appendDataToLines(filename, data);

// //     std::cout << "Dữ liệu đã được ghi vào cuối mỗi dòng trong file " << filename << "." << std::endl;

// //     return 0;
// // }


// #include <iostream>
// #include <fstream>
// #include <vector>

// void writeConditionalDataPerLine(const std::string& filename, const std::vector<std::string>& lines) {
//     std::ofstream outputFile(filename);
//     if (!outputFile) {
//         std::cerr << "Không thể tạo file " << filename << "!" << std::endl;
//         return;
//     }

//     for (const std::string& line : lines) {
//         char firstChar = line[0];
//         std::string data;

//         if (firstChar == '0') {
//             data = "Hình tam giác";
//         } else if (firstChar == '1') {
//             data = "Hình vuông";
//         } else {
//             data = "Dữ liệu không hợp lệ";
//         }

//         outputFile << data << std::endl;
//     }

//     outputFile.close();
// }

// int main() {
//     std::string filename = "data.txt";
//     std::vector<std::string> lines = {"0ABC", "1XYZ", "2DEF"};

//     writeConditionalDataPerLine(filename, lines);

//     std::cout << "Dữ liệu đã được ghi vào từng dòng trong file " << filename << "." << std::endl;

//     return 0;
// }