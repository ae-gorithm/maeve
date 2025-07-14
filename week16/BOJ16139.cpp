// 50점짜리 코드
// #include <iostream>
// using namespace std;

// string str;             // 문자열 S

// void sol(char a, int l, int r) {
//     int cnt = 0;
//     for (int i = l; i <= r; i++) {
//         if (str[i] == a) {
//             cnt++;
//         }
//     }
//     cout << cnt << '\n';
// }

// int main(void) {
//     ios::sync_with_stdio(false); 
//     cin >> str;
//     int q; cin >> q;            // 질문의 수 q

//     for (int i = 0; i < q; i++) {
//         char a; cin >> a;
//         int l; cin >> l;
//         int r; cin >> r;

//         sol(a, l, r);
//     }
// }


#include <iostream>
using namespace std;

int arr[26][200001];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string str; cin >> str;
    int q; cin >> q;


    int size = str.size();
    
    // 누적합 구하기
    for (int i = 0; i < size; i++) {
        int a = str[i] - 'a';

        for (int j = 0; j < 26; j++) {
            arr[j][i + 1] = arr[j][i]; 
        }
        arr[a][i + 1]++;  
    }

    for (int i = 0; i < q; i++) {
        char a; int l, r;
        cin >> a >> l >> r;

        int c = a - 'a';

        // 횟수 계산
        cout << arr[c][r+1] - arr[c][l] << '\n';
    }
}
