#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        vector <int> students;
        int num;
        cin >> num;
        cout << num << " ";

        int answer = 0;

        for(int i = 0; i < 20; i++){
            int temp;
            cin >> temp;

            int cnt = 0;
            int pos = 0;

            while (pos < students.size() && students[pos] < temp)
                pos++;

            cnt = students.size() - pos;
            answer += cnt;

            students.insert(students.begin() + pos, temp);
        }


        cout << answer << "\n";
    }

    return 0;
}