//15:20 15:58
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq_p;
    priority_queue<int> pq_m;
    while(n--){
        int temp = 0;
        cin >> temp;

        if(temp == 0){
            if(pq_p.empty() && pq_m.empty()){
                cout << "0" << "\n";
            }
            else if(pq_p.empty()){ //양수쪽이 비어있으면
                cout << pq_m.top() << "\n", pq_m.pop();
            }
            else if(pq_m.empty()){
                cout << pq_p.top() << "\n", pq_p.pop();
            }
            else{
                int p_min = pq_p.top();
                int m_min = pq_m.top();

                if(abs(m_min) <= p_min) cout << m_min << "\n", pq_m.pop();
                else cout << p_min << "\n", pq_p.pop();
            }

        }
        else{
            if(temp > 0) pq_p.push(temp);
            if(temp < 0) pq_m.push(temp);
        }
    }

    return 0;
}