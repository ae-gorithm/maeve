#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 점수로 비교
bool compare(const pair<int, int>&a, const pair<int, int>&b) {
    return a.second > b.second;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N; cin >> N;         // 정수의 개수
    vector<pair<int, int> > hw(N);

    int maxDay = 0;         // 제일 늦는 마감일
    int score = 0;          // 웅찬이의 점수 ~

    for (int i = 0; i < N; i++) {
        cin >> hw[i].first >> hw[i].second;
        maxDay = max(maxDay, hw[i].first);
    }

    // 점수 기준 내림차순 정렬
    sort(hw.begin(), hw.end(), compare);

    vector<bool> isChecked(maxDay + 1, false);

    for (int i = 0; i < N; i++) {
        int d = hw[i].first;
        int w = hw[i].second;

        for (int j = d; j > 0; j--) {
            if (isChecked[j] == false) {
                score += w;
                isChecked[j] = true;
                break;
            }   

        }
    }
    cout << score << '\n';
}