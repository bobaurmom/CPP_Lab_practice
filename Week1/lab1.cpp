#include <iostream>
using namespace std;
//exercise 4 a
float computeA (int n){
    float a=0;
    float sumA=0 ;
    while (a!=n){
        sumA += (a+1);
        a++;
    }
    return sumA;
}
//exercise 4 b
float computeB (int n){
    int a=0;
    float sumB=0 ;
    while (a!=n){
        sumB += (a+1)*(a+1);
        a++;
    }
    return sumB;
}
//exercise 4 c
float computeC (int n){
    float a=0;
    float sumC=0 ;
    while (a!=n){
        sumC += 1/(a+1);
        a++;
    }
    return sumC;
}


int main(){
//exercise 1
    string name = "Nita";
    int group =1 ;
    int year =2;
    string depart = "data science";
    cout<<"welcome to data stucture and programming class\n";
    cout<<"My name is "<<name<<" I am currently a year" <<year<<" student from group "<<group <<depart<<" department.\n I am so excited to start my class in this term.";
    cout<<"\n";
//exercise 2
    int input[10]= {0,1,2,3,4,5,6,7,8,9};
    int count =0;
    for (int i=9; i>=0 ;i--){
        cout<<input[i]<<"\n" ;
        //exercise 2 part b
        if ( input[i] %2==0){
            count++;
        }
    }
    cout << count;
    cout<< "\n";
//exercise 3
    int array[5]={10,30,23,54,60};
    int arrlenght = sizeof(array)/sizeof(array[0]);
    int max= array[0];
    int min= array[0];
    for (int i=0 ; i< arrlenght ;i++){
        if ( array[i]> max){
            max = array[i];
        }
        if(array[i]<min)
            min = array[i];
    }
    cout<<"minumum"<<min<<"\n";
    cout<<"maximum"<< max<<endl;
//exercise 4
    cout<< computeA(5)<<"\n";
    cout<< computeB(5)<<"\n";
    cout<< computeC(5)<<"\n";
//exercise 5
// a compute average of 3 x=4 , y=6 , z=20
//-it (o(1))
// b.display all data in a array
// - if 1D array it will have (o(n))
// - if 2D array it will have (o(nxm)) 2D square is (o(n^2))
// c.find maximun number in an array
// - it will have (o(n))
// d. print an array element at 3
// - it (o(1))
// e. show reverse data from array
// - if 1D array it will have (o(n))
// - if 2D array it will have (o(nxm)) 
    return 0;
}
