#include <iostream>

using namespace std;

string check_lengh_string(string s1, string s2){
    if(s1.length() > s2.length())
        return s1;
    else if(s1.length() < s2.length())
        return s2;
    else return "equal length !";

}
int main(int argc, char const *argv[])
{
    string s1, s2;

    cout << "Nhap chuoi thu nhat: " ;
    // cin.ignore();
    getline(cin, s1);
    cout << endl;

    cout << "Nhap chuoi thu hai: ";
    getline(cin, s2);
    cout << endl;
    // cout << s1.length()<<endl;
    // cout << s2.length()<<endl;
    cout << "Ket qua so sanh hai chuoi s1 va s2: " << check_lengh_string(s1,s2) << endl;

    return 0;
}
