#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;    // 테스트 케이스의 개수
    
    for (int i = 0; i < t; i++) {
        int n, m; cin >> n >> m;
        for (int j = 0; j < m; j++) {
            int a, b; cin >> a >> b;
        }
        cout << n-1 << "\n";
    }
    return 0;
}