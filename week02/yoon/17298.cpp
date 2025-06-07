//13:57 14:48
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n), result(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        while(!st.empty() && A[st.top()] < A[i]) {
            result[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}



/*
int main(){
    ios::sync_with_stdio(false);      
    cin.tie(0);     

    int n = 0;
    cin >> n;

    stack <int> st;
    for(int i =0; i < n; i++){
        int temp = 0;
        cin >> temp;

        if(!st.empty() && st.top() < temp){
            stack <int> temp_st;
            while(!st.empty() && st.top() < temp){
                temp_st.push(temp);
                st.pop();
            }
            while(!st.empty()){
                temp_st.push(-1);
                st.pop();
            }

            while(!temp_st.empty()){
                cout << temp_st.top() << " ";
                temp_st.pop();
            }
        }
        st.push(temp);
    }   

    while(!st.empty()){
        cout << "-1" << " ";
        st.pop();
    }

    return 0;
}
*/