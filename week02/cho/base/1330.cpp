#include <iostream>
using namespace std;

int main() {
int A, B;
cin >> A >> B;
int cmp = (A > B) ? 1 : (A < B) ? -1 : 0;

switch (cmp) {
    case 1:
        cout << ">" << endl;
        break;
    case -1:
        cout << "<" << endl;
        break;
    case 0:
        cout << "==" << endl;
        break;
}
return 0;
}