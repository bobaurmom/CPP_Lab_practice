#include <iostream>
using namespace std;
//exercise 5
int main(){
    int array [3]= {4,6,20};
    cout<<"array=";
    int temp =0;
    for (int i=0 ; i<3 ;i++){
        cout<< array[i]<<" ";
        if (array[i+1]> array[i] ){
            temp = array[i+1];
        }
    }
    cout<<"\n";
    cout<< "maximum="<<temp<<"\n";
    cout << "array position 3="<<array[3-1];
    cout<<"\nreverse data";
    for (int i=0 ; i<3 ;i++){
        cout<< " "<< array [3-i-1] ;

    }
    
}