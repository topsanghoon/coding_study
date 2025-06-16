#include <iostream>
#include <set>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n;
    int a;
    set<int> cardset;// 중복되는 카드를 제거하기 위해 set 구조 활용
    for(int i=0;i<n;i++){
        cin >> a;
        cardset.insert(a);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a;
        cout << cardset.count(a)<<' '; // 입력값이 카드셋에 있는지 확인 (시간복잡도: O(logN))
    }
    
    return 0;
}