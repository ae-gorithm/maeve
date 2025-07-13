#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;    // 음의 수
    int p; cin >> p;    // 플렛의 수

    int cnt = 0;        // 손가락 이동 횟수

    // 각 줄마다의 스택
    vector<stack<int> > guitar(7);

    for (int i = 0; i < n; i++) {
        int line; cin >> line;
        int fret; cin >> fret;
        
        // top이 fret보다 크면 pop
        while (!guitar[line].empty() && guitar[line].top() > fret) {
            guitar[line].pop();
            cnt++;
        } 

        // 같은 게 나오면 continue
        if (!guitar[line].empty() && guitar[line].top() == fret) {
            continue;
        }

        // 들어온 fret 누그리
        guitar[line].push(fret);
        cnt++;
    }

    // 출력
    cout << cnt;
}
