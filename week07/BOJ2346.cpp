#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;            // 풍선의 개수
    deque<pair<int, int> > dq;  // 풍선 인덱스, 정수 저장 덱
    vector<int> v;              // 터진 풍선 저장
    int a;
    

    for (int i = 1; i <= n; i++) {
        cin >> a;
        dq.push_back(make_pair(i, a));
    }

    a = dq.front().second;
    v.push_back(dq.front().first);

    dq.pop_front(); // 첫번째 풍선 제거

    while (dq.size() != 0) {
        if (a > 0) {
            // 다시 덱 생성
            for (int i = 0; i < a-1; i++) { 
				dq.push_back(dq.front());
				dq.pop_front();
            }
            a = dq.front().second;
            v.push_back(dq.front().first);
            dq.pop_front(); // 풍선 제거
        } else {
            // 다시 덱 생성
            for (int i = 0; i > a+1; i--) {
				dq.push_front(dq.back());
				dq.pop_back();
            }
            a = dq.back().second;
            v.push_back(dq.back().first);
            dq.pop_back();  // 풍선 제거
        }
    }

    // 터진 풍선 번호 출력
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}