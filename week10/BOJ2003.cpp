#include <iostream>
using namespace std;

int arr[10001];
int sum[10001];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp = sum[j] - sum[i-1];
            if (tmp == m) {
                cnt++;
            }
        }
    }
    cout << cnt;
}