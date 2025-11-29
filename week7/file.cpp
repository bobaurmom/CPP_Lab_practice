#include <iostream>
#include <fstream>
#include <string>
using namespace std;    


int main() {
    int ID, age;
    string name;
    fstream user;
    user.open("user.csv", ios::out);
    user<<"this is user file\n";
    user<<"id,name,age\n";
    for (int k=1; k <= 4 ; k++){
        cout<<"ID:";cin >> ID;
        cout<<"name:"; cin >> name;
        cout<<"age:"; cin>> age;
        user << ID << "," << name << "," << age << endl;
    }

    user.close();
    return 0;
}