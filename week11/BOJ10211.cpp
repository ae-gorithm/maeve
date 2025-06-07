#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;        // 테스트 케이스

    for (int i = 0; i < t; i++) {
        int n; cin >> n;   
        int x[n+1]; 
        vector<int> sum(n+1, 0);


        for (int j = 1; j <= n; j++) {
            cin >> x[j];
            sum[j] = sum[j-1] + x[j];
        }

        int max = -1000000; 

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int cur = sum[j] - sum[i-1];
                if (cur > max) {
                    max = cur;
                }
            }
        }

        cout << max << '\n';
    }
}