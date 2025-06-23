#include <iostream>
using namespace std;

int adj[101][101];
int n;

// 플로이드 워셜 알고리즘
void floyd_warshall()
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
                if (adj[i][k] == true && adj[k][j] == true)
                    adj[i][j] = true;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n; 

    // 인접행렬 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

	floyd_warshall();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << adj[i][j] << " ";
		}
		cout << '\n';
	}
}
