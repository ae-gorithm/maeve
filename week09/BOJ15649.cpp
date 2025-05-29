#include <iostream>
using namespace std;

int N, M;
int num[9];          
bool used[9];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) 
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!used[i]) {           
            used[i] = true;       
            num[depth] = i;       
            dfs(depth + 1);       
            used[i] = false;      
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    dfs(0);
}
