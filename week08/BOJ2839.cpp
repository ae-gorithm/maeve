#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;    // 배달해야 하는 설탕
    int cnt = 0;        // 봉지의 개수

    while (n >= 0) {
        if (n % 5 == 0) {    
            cnt += n / 5;    
            cout << cnt;
            return 0;           
        }
        n -= 3; 
        ++cnt;
    }
    cout << -1 << '\n';
}

/*
그리디 알고리즘
: 최적의 답만을 선택하여 답을 내자

- 최적의 상황: 5로 나누면 가장 최적의 상황(봉지의 개수가 줄어듦)이 된다.
따라서 가능한 5Kg 봉지를 사용

1. 5로 나누어 떨어지면
    - 갯수에 5로 나눈 몫 더하고
    - 정답 출력
2. 5로 안 나눠지면 3kg 봉지 사용
    - 봉지 수 1 더한다.

이 과정을 n < 0이 될때까지 한다.

만약 n이 음수가 되면 정확하게 n키로를 맞출 수 없는 경우이르모 -1을 출력한다.
*/