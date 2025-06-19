#include <iostream>
using namespace std;

int paper[2187][2187];
int cnt[3];

bool isSameNumber(int x, int y, int size) {
    int num = paper[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            // 숫자가 다르면
            if (paper[i][j] != num) return false;
        }
    }

    // 숫자가 다 같음녀
    return true;
}

void sol(int x, int y, int size) {
    // 모두 같은지 판단
    if (isSameNumber(x, y, size)) {
        // 같으면
        int num = paper[x][y];
        cnt[num+1]++;
        return;
    }

    // 다르면 다시 분할
    int newSize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sol(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    sol(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << '\n';
    }
}

/*
모두 같은지 판단 (isSameNumber)
- 맞으면
: 그대로 사용한다.
    - 어떤 숫자로 채워져있는지 확인한다. (cnt 배열에 개수 추가)

- 아니면 
: 9개로 분할정복

cnt[3] = 0, 1, 2
실제: -1, 0, 1
*/
