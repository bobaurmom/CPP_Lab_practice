//Group 5 (se nita , oeng chheangsing , sun david , ching norin ,No vannydet)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

 
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    fstream file;
    file.open("bubble.csv",ios::out);
    file<<"bubble sort"<<endl;
    for (int i=0 ; i<1000;i++){
        file<<arr[i]<<endl;
    }
    file.close();
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i+ 1; j <n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr[i], arr[min]);
        }
    }
    fstream file;
    file.open("select.csv",ios::out);
    file<<"selective sort"<<endl;
    for (int i=0 ; i<1000;i++){
        file<<arr[i]<<endl;
    }
    file.close();
}
int main(){
    int num;
    int arr[1000];
    fstream file;
    file.open("file.csv",ios::out);
    file<<"all random Number"<<endl;
    for(int i=0 ; i< 1000 ; i++){
        num= rand() % 991 + 10;
        file<<num<<endl;
    }
    file.close();
    file.open("file.csv",ios::in);
    string line;
    int i=0;
    while(getline(file,line)){
        int num_val;
        istringstream ss(line);
        if (ss >> num_val) {
            arr[i] = num_val; 
            i++;
        }
    }
    file.close();
    selectionSort(arr,1000);
    bubbleSort(arr,1000);
    return 0;
}
