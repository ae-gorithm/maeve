#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int N; cin >> N;            // 과일의 개수
    vector<int> fruits(N);

    for (int i = 0; i < N; i++) {
        cin >> fruits[i];
    }

    vector<int> arr(10, 0);     // 과일 개수 세기

    int left = 0, right = 0;    // 투포인터
    int curCnt = 0;             // 현재 윈도우 내 과일 종류
    int ans = 0;                // 정답 (최대 길이)

    // 투포인터 (오른쪽 포인터 이동하면서)
    while (right < N) {
        int fruit = fruits[right];
        if (arr[fruit] == 0) curCnt++; // 새로운 과일이면 종류 증가
        arr[fruit]++;                  // 과일 개수 증가
        right++;

        // 과일 종류가 2개 이상이면 왼쪽 포인터를 줄임
        while (curCnt > 2) {
            int leftFruit = fruits[left];
            arr[leftFruit]--;
            if (arr[leftFruit] == 0) // 아예 사라지면 종류 감소
                curCnt--; 
            left++;
        }

        ans = max(ans, right - left);       // 최대 길이
    }

    cout << ans << '\n';

}