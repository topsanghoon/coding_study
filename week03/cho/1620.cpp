#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(NULL);

int N, M;
cin >> N >> M;
map<string, int> m1;
map<int, string> m2;
string str;

//맵에 1번부터 N번 까지 값 삽입,
//m1에 key= 문자   m2 key=숫자
for (int i = 1; i <= N; i++) {
    cin >> str;
    m1[str] = i;
    m2[i] = str;
    // m1.insert({str, i});
    // m2.insert({i,str});
}

for (int i = 0; i < M; i++) {
    cin >> str;
    if (str[0] >= '0' && str[0] <= '9') {
        int num = stoi(str);
        cout << m2[num] << '\\n';
    } else {
        cout << m1[str] << '\\n';
    }
}
return 0;
}
