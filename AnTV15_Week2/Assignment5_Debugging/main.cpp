#include <iostream>

using namespace std;

void swap(int evenNumber, int oddNumber) {
    int temp = evenNumber;
    evenNumber = oddNumber;
    oddNumber = temp;
}
void swap_(int& evenNumber, int& oddNumber) {
    int temp = evenNumber; 
    evenNumber = oddNumber; 
    oddNumber = temp; 
}
int main() {
    int evenNumberA = 2;
    int oddNumberA  = 3;
    cout << "evenNumberA:" << evenNumberA << "\toddNumberA:" << oddNumberA << endl;
    swap(evenNumberA, oddNumberA);
    cout << "evenNumberA:" << evenNumberA << "\toddNumberA:" << oddNumberA << endl;
    cout << "=====================" << endl;
    int evenNumberB = 2;
    int oddNumberB  = 3;
    cout << "evenNumberB:" << evenNumberB << "\toddNumberB:" << oddNumberB << endl;
    swap_(evenNumberB, oddNumberB);
    cout << "evenNumberB:" << evenNumberB << "\toddNumberB:" << oddNumberB << endl;    
    return 0;
}
