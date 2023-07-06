#include <iostream>
#include <algorithm>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void
solve (void)
{
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	int sushi[30004] = {0};

	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}

	int maxCnt = 0;

	for (int i = 0; i < N; i++) {
		int visited[3003] = {0};
		visited[c] = 1;

		for (int j = i; j < i + k; j++) {
			visited[sushi[j % N]] = 1;
		}

		int cnt = 0;

		for (int j = 1; j <= 3000; j++) {
			cnt += visited[j];
		}

		maxCnt = max (maxCnt, cnt);
	}

	cout << maxCnt;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
