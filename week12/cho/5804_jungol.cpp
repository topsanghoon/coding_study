//https://jungol.co.kr/problem/5804?cursor=OCwzLDg%3D

/*
이진 탐색을 이용한 풀이 
이진 탐색의 대상: 나무 사이의 거리!!  
start:1(최소거리-직접구하기for문으로구하기 어려우니 1로 지정)
end: 맨 끝과 처음 사이의 거리
거리의 중앙을  mid로 설정 , start>end가 될때까지 탐색!! 

이처럼 이진 탐색의 대상이 arr의 값이 아니라 사이의 거리를 개별적으로 탐색 할수 있다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int N,M;
//K:mid  M: 나무 갯수 기준 값 
bool CanPlant(int K,int M){
    int cur=0;
    int cnt=1;
    for(int i=1;i<N;i++){
        if((arr[i]-arr[cur])<K) continue;
        cnt++;
        cur=i;
    }
    return (cnt>=M);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;
    arr.resize(N,0);
    for(int i=0;i<N;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());

    int start=1;
    int end=arr[N-1]-arr[0];
    int ans=0;
    while(start<=end){
        int mid = (end+start)/2;
        if(CanPlant(mid,M)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    cout<<ans;
    
    return 0;
}
