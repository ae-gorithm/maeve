#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000
using namespace std;

vector<bool> isPrime(MAX + 1, true); 

void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i + i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sieve();

    while (true) {
        int n; cin >> n;
        if (n == 0) break;

        bool found = false;

        for (int a = 3; a <= n / 2; a += 2) {
            int b = n - a;
            if (isPrime[a] && isPrime[b]) {
                cout << n << " = " << a << " + " << b << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}
