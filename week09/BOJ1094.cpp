#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x; cin >> x;
    int ans = 0;

    while (x > 0) {
        if (x % 2 == 1) ans++;
        x /= 2;
    }
    cout << ans;
}
