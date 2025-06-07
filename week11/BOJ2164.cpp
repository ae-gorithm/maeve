#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}

/*
1. 제일 위에 있는 카드 버리기 (pop)
2. 1번 하고 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮기기
-> 마지막에 남게 되는 카드 출력
*/