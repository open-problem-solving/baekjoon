#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF	0x3f3f3f3f

void
solve (void)
{
	int N, M;
	cin >> N >> M;

	int wok[10004] = {0};
	int bool_cook_avail[10004] = {0};
	for (int i = 0; i < M; i++) {
		cin >> wok[i];
		bool_cook_avail[wok[i]] = 1;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (i == j) {
				continue;
			}
			if (N < wok[i] + wok[j]) {
				continue;
			}
			bool_cook_avail[wok[i] + wok[j]] = 1;
		}
	}

	vector<int> cook_avail;
	for (int i = 1; i <= N; i++) {
		if (bool_cook_avail[i] == 1) {
			cook_avail.push_back (i);
		}
	}

	int dp[10004] = {0};
	memset (dp, 0x3f, sizeof (dp));
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int cook : cook_avail) {
			if (cook <= i) {
				dp[i] = min (dp[i], dp[i - cook] + 1);
			}
		}
	}

	cout << ((dp[N] != INF) ? dp[N] : -1);
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
