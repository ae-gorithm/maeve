#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        cout << binary_search(v.begin(), v.end(), a) << '\n';
    }
}