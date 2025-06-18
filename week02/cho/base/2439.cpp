#include <iostream>
using namespace std;

int main() {
int N;
cin >> N;
for (int i=1; i<N+1; i++) {
    for (int j=1; j<=N-i; j++) {
        cout<<' ';
    }
    for(int k=1;k<=i;k++){
        cout<<"*";
    }

    cout<<'\\n';
}

return 0;
}