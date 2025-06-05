#include <iostream>
using namespace std;

int getPerimeter();

int arr[102][102] = {};

int main() {
    
    int cp[101][3];
    int tc;
    

    //입력
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

    int answer = getPerimeter();

    cout<<answer<<'\n';
    return 0;
}

int getPerimeter(){
    
    int ny[4] = {1,-1,0,0};
    int nx[4] = {0,0,1,-1};
    int perimeter = 0;

    for(int i=1;i<=100;i++){
        for(int ii=1;ii<=100;ii++){
            
            if(arr[i][ii]==0) continue;
            for(int iii=0;iii<4;iii++){
                int next_y = i+ny[iii];
                int next_x = ii+nx[iii];

                if(arr[next_y][next_x]==0){
                    perimeter++;
                } 
            }  
        }
    }
    return perimeter;
}