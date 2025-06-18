#include <iostream>
using namespace std;
#include <vector>
int main() {
    
    int n;
    cin>>n;
    vector<double>arr=vector<double>(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double mx=0;
    
    for(int i=0;i<n;i++){
        if(mx<arr[i]){
            mx=arr[i];
        }
    }
    
    double sum=0;
    for(int i=0;i<n;i++){
        sum += (arr[i] /mx)* 100 ;
    }

    //평균 구하기 
    
    double avr;

    avr=sum/n;;
    cout<<avr;
    
    
    return 0;
}