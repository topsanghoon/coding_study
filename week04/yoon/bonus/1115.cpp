#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
int a[50], cnt;
bool visited[50];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) if(!visited[i]) {
        cnt++;
        visited[i]=1;
        for(int j=a[i]; j!=i; j=a[j]) visited[j]=1;
    }
    if(cnt==1) cout << 0;
    else cout << cnt;
}