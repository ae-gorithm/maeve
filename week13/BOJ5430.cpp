#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

// 배열 전처리
deque<int> preprocess(int n, const string& StringArr) {
    deque<int> dq;
    string tmp;

    for (int i = 1; i < StringArr.size(); i++) {
        char c = StringArr[i];

        if (isdigit(c) == true) {
            tmp += c;
        } else if (((c == ',') || (c == ']')) && !tmp.empty()) {
            dq.push_back(stoi(tmp));
            tmp.clear();
        }
    }
    return dq;
}

// 문제 해결
void sol(string p, deque<int> dq) {
    bool isReversed = false;

    for (char c: p) {
        if (c == 'D') {                 // D: 첫번째 수 버리기 (비어있으면 에러 출력하고 끝)
            if (dq.empty() == true) {
                cout << "error\n";
                return;
            } else {
                if (isReversed == false) {
                    dq.pop_front();
                } else
                    dq.pop_back();
            }
        } else if (c == 'R') {         // R: 배열에 있는 수 뒤집기
            isReversed = !isReversed;
        }
    }

    // 출력하기 
    cout << "[";

    if (isReversed == false) {          // 안 뒤집혔을 경우
        while (dq.size() > 1) {
            cout << dq.front() << ',';
            dq.pop_front();
        }
        if (!dq.empty()) {
            cout << dq.front();
        }
        
    } else {                            // 뒤집혔을 경우
         while (dq.size() > 1) {
            cout << dq.back() << ',';
            dq.pop_back();
         }
         if (!dq.empty()) {
            cout << dq.back();
         }
    }
    cout << "]\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;

    for (int i=0; i < T; i++) {
        string p; cin >> p;                     // 함수 p
        int n; cin >> n;                        // 배열에 있는 수의 개수
        string StringArr; cin >> StringArr;     // 배열 입력

        deque<int> dq = preprocess(n, StringArr);
        sol(p, dq);
    }

    return 0;
}