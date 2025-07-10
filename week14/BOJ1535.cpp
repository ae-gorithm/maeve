#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin >> N;

    vector<int> L(N); 
    vector<int> J(N); 

    // 입력받기
    for (int i = 0; i < N; i++) cin >> L[i];
    for (int i = 0; i < N; i++) cin >> J[i];

    vector<int> dp(101, 0); 

    // dp 배열 채우기
    for (int i = 0; i < N; i++) {
        for (int j = 100; j >= L[i]; --j) {
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }

    int ans = 0;
    for (int i = 1; i < 100; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}

/*
dp 점화식
기존 방법으로 한 최대 기쁨, i번을 택해서 얻은 기쁨 중 max 
=> dp[j] = max(dp[j], dp[i-L[i]] + J[i])
- i번째 행동이 체력에 들어갈 수 있는지
- 중복 방지 위해 역순으로
*/
