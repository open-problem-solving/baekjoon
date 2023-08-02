#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int N, S, R;
	bool team_is_broken[15] = {false};
	bool team_has_spare[15] = {false};

	cin >> N >> S >> R;
	for (int i = 0; i < S; i++) {
		int team_num;
		cin >> team_num;
		team_is_broken[team_num] = true;
	}
	for (int i = 0; i < R; i++) {
		int team_num;
		cin >> team_num;
		team_has_spare[team_num] = true;
	}

	for (int t = 1; t <= N; t++) {
		if (!team_is_broken[t])
			continue;
		if (team_has_spare[t]) {
			team_has_spare[t] = false;
			team_is_broken[t] = false;
		}
	}

	int cnt = 0;
	for (int t = 1; t <= N; t++) {
		if (!team_is_broken[t])
			continue;
		cnt++;
		for (int i = -1; i < 2; i += 2) {
			if (team_has_spare[t + i]) {
				team_has_spare[t + i] = false;
				team_is_broken[t] = false;
				cnt--;
				break;
			}
		}
	}

	cout << cnt;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
