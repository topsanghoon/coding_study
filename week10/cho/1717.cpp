//https://www.acmicpc.net/problem/1717
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,M;
vector<int> arr;


/*
경로 압축이 적용되지 않은 코드
1 2 3 4 5 6 7
1 1 2 3 4 5 6  -> find_parent(7) = find_parent(6)->find_parent(5)
->find_parent(4)->find_parent(3)->find_parent(2)->find_parent(1)=1   1 이 출력 된다. 
이후 find_parent(4) 도 동일하게  4 3 2 1 로 
O(N)의 시간이 항상 걸리게 되고 부모 노드를 찾을때마다 정직하게 찾게 되는 코드 
*/
int find_parent1(int num){
    if(num==arr[num]) return num;
    return find_parent1(arr[num]);
}

/* 
//경로 압축이 적용된 코드
1 2 3 4 5 6 7
1 1 2 3 4 5 6  -> find_parent(7) = find_parent(6)->find_parent(5)
->find_parent(4)->find_parent(3)->find_parent(2)->find_parent(1)=1   1 이 출력 된다.
=> return을 호출에 그치는 것이 아니라 arr[num] 부모 노드 저장 배열에 저장하면서 호출 하기때문에
 1을 찾고 난 이후엔 1~7의 부모 노드는 1로 갱신이 되고  이후 또다시 find를 하게 되면 O(1)의 시간만에 추적이 가능하다.!!!
*/ 
int find_parent2(int num){
    if(num==arr[num]) return num;
    return arr[num] = find_parent2(arr[num]);
}

void check_parent(int num1,int num2){
    int x1 = find_parent2(num1);
    int x2 = find_parent2(num2);
    if(x1==x2) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
// 서로 공동의 부모를 바라 보게 만들면 된다.!! 단순히 말해 트리를 만든다고 생각을 해보자! 
void union_parent(int num1,int num2){
    int x1 = find_parent2(num1);
    int x2 = find_parent2(num2);
    if(x1<x2) arr[x2] = x1;
    else arr[x1] = x2;
}
//원소의 크기(원소수) 균형 있게 유지 - 집합 크기 관리
vector<int> tree_size;
void union_sets(int num1,int num2){
    num1=find_parent2(num1);
    num2=find_parent2(num2);
    if(num1 !=num2){
        if(tree_size[num1] <tree_size[num2]) swap(num1,num2);
        arr[num2] = num1;
        tree_size[num1]+=tree_size[num2];
    }
}

// 크기의 높이 최소화, find가 빨라짐 - 높이 관리
vector<int> tree_rank;
void union_sets(int num1, int num2) {
    num1 = find_parent2(num1);
    num2 = find_parent2(num2);
    if (num1 != num2) {
        if (tree_rank[num1] < tree_rank[num2]) swap(num1, num2);
        arr[num2] = num1;
        if (tree_rank[num1] == tree_rank[num2]) tree_rank[num1]++;
    }
}

//<<endl 를 사용할시 버퍼를 지우는 로직이 포함이 되어 있어 코테문제 풀때는 사용 하지 않는것이 좋다. 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

     cin>>N>>M;
     arr.resize(N+1);
     tree_size.resize(N+1);
     tree_rank.resize(N+1);

     for (int i = 0; i <= N; i++)
     {
        arr[i]=i;
     }

     int sel,num1,num2;
     for(int i=0;i<M;i++){
        cin>>sel>>num1>>num2;
        if(sel==0) union_parent(num1,num2);        
        else if(sel==1) check_parent(num1,num2);
     }
     
}