#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  

using namespace std;

int main() {
    fstream user;
    string line;

    user.open("user.txt", ios::in);
    while (getline(user, line)) {
        stringstream s(line);  
        string token;
        while (getline(s, token, ',')) {
            cout << token << "\t";
        }
        cout << endl;
    }
    user.close();
    return 0;
}