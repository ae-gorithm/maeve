#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;             // 피연산자의 개수
    string str; cin >> str;      // 후위 표기식

    stack<double> st;
    int num[26];                 // 값 저장


    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            st.push(num[str[i] - 'A']);
        } else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();

            if (str[i] == '+') st.push(a + b);
            else if (str[i] == '-') st.push(a - b);
            else if (str[i] == '*') st.push(a * b);
            else if (str[i] == '/') st.push(a / b);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top();
}
