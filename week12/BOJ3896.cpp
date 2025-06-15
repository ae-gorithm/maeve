#include <iostream>
#include <cmath>
using namespace std;

// 특정 수가 소수인지 판별
bool isPrime(int k) {
    if (k < 2) return false; 
    int a = (int)sqrt(k);
    for (int i = 2; i <= a; i++){
        if (k % i == 0) 
            return false;
    }
    return true;
}

void sol(int k) {
    // 해당 수가 소수일 경우는 바로 0 출력
    if (isPrime(k) == true) {
        cout << 0 << '\n';
        return;
    } 
    // k보다 작은 가장 가까운 소수
    int prev = k - 1;
    while (prev >= 2 && !isPrime(prev)) {
        prev--;
    }

    // k보다 큰 가장 가까운 소수
    int next = k + 1;
    while (!isPrime(next)) {
        next++;
    }
    cout << (next - prev) << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;

    for (int i = 0; i < t; i++) {
        int k; cin >> k;
        sol(k);
    }
    return 0;
}
