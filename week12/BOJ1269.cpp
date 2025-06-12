#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    set<int> A_set, B_set;

    for (int i = 0; i < A; i++) {
        int tmp; cin >> tmp;
        A_set.insert(tmp);
    }

    for (int i = 0; i < B; i++) {
        int tmp; cin >> tmp;
        B_set.insert(tmp);
    }

    // A - B
    set<int> A_B;
    set_difference(A_set.begin(), A_set.end(), B_set.begin(), B_set.end(), inserter(A_B, A_B.begin()));

    // B - A
    set<int> B_A;
    set_difference(B_set.begin(), B_set.end(), A_set.begin(), A_set.end(), inserter(B_A, B_A.begin()));

    // 대칭 차집합
    set<int> result;
    set_union(A_B.begin(), A_B.end(), B_A.begin(), B_A.end(), inserter(result, result.begin()));

    cout << result.size() << '\n';

    return 0;
}
