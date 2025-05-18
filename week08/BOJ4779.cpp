#include <iostream>
#include <cmath>
using namespace std;

void sol(int n) {
    if (n == 0) {
        cout << "-";
        return;
    } 

    sol(n-1);
    for (int i = 0; i < pow(3, n-1); i++) {
        cout << " ";
    }
    sol(n-1);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {
        sol(n);
        cout << "\n";
    }
    return 0;
}