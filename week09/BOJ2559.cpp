#include <iostream>
#include <algorithm>
using namespace std;

int n, k; 
int sum[100001];
int ans = -10000001;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }

    for (int i = k; i <= n; i++) {
        ans = max(ans, sum[i] - sum[i-k]);
    }
    cout << ans << '\n';
}
