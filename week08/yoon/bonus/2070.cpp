//재도전전전전전전전전전전전전전전전전전전전전전전전전전

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main() {
//     string text;
//     cin >> text;

//     vector<string> answer;
//     string prev = "";
//     string current = "";

//     for(int i = 0; i < text.size(); i++){
//         prev += '1';
//     }

//     bool flag = true;
//     for (char ch : text) {
//         if (ch == '0') {
//             if(flag != true){
//                 flag = true;

//                 if (prev >= current) {
//                     answer.push_back(current);
//                     prev = current;
//                     current = "";
//                 }
//             }
//         }
//         else {
//             flag = false;
//         }

//         current += ch; 
//     }

//     //if(!prev.empty())answer.push_back(prev);

//     if (!current.empty()) {
//         answer.push_back(current);
//     }

//     // 출력
//     for (const string& s : answer) {
//         cout << "(" << s << ")";
//     }

//     return 0;
// }
