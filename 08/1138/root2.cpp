#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int N;
	int left_tall;

	int ans_loc[11] = {0};

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> left_tall;

		int cnt_tall = 0;
		for (int l = 0; l < N; l++) {
			if (ans_loc[l] != 0)
				continue;
			
			if (cnt_tall == left_tall) {
				ans_loc[l] = i;
				break;
			}
			cnt_tall++;
		}
	}

	for (int i = 0; i < N; i++)
		cout << ans_loc[i] << ' ';
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
