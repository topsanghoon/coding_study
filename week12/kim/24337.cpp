 #include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void arr_swap(int src, int dst)
{
    int tmp = arr[src];
    arr[src] = arr[dst];
    arr[dst] = tmp;
}

int main(){

    int n,a,b;
    cin >> n >> a >> b;
    arr = vector<int>(n,1);
    
    if(a==1 && b==1){
        for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

if((a+b)>n+1){
    cout << -1;
        return 0;
    }
    
    if(a<b){
        arr[n-b] = b;
        for(int i=n-b+1;i<n;i++){
            arr[i] = arr[i-1]-1;
        }
        if(a==1){
            arr_swap(0,n-b);
        }
        else {
            arr[n-b-1] = a-1;
            int tmp = a-2;
            int idx = n-b-2;
            while(tmp>1){
                arr[idx--] = tmp--;
            }
        }
    } else {

        arr[n-b] = a;
        int tmp = b-1;
        int idx = n-b+1;
        while(tmp>1){
            arr[idx++] = tmp--;
        } 
        tmp = a-1;
        idx = n-b-1;
        while(tmp>1){
            arr[idx--] = tmp--;
        } 
    }

    
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }



    return 0;
}