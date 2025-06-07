#include <iostream>
using namespace std;

int main() {
    
    int cp[101][3];
    int tc;
    int arr[101][101] = {};
    cin >> tc;
    for(int i=1; i<=tc; i++){
        cin >> cp[i][1] >> cp[i][2];
    }
    
    for(int i=1; i<=tc; i++){

        
        int y = cp[i][1];
        int x = cp[i][2];

        for(int ii = 0; ii < 10; ii++){
            for(int iii=0; iii<10; iii++){
                arr[y+ii][x+iii] = 1;
            }
        }
    }
    int answer = 0;
    for(int i=1;i<=100;i++){
        for(int ii=1; ii<=100;ii++){
            answer += arr[i][ii];
        }
    }
    cout<<answer<<'\n';
    return 0;
}