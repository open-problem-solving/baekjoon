#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define MAX_G 100005

int gate_link_list[MAX_G];

int
gate_find_empty (int gate_num)
{
	if (gate_num == gate_link_list[gate_num]) {
		return gate_num;
	} else {
		gate_link_list[gate_num] = gate_find_empty (gate_link_list[gate_num]);
		return gate_link_list[gate_num];
	}
}

void
solve (void)
{
	int G, P;
	cin >> G >> P;

	for (int i = 1; i <= G; i++) {
		gate_link_list[i] = i;
	}

	int ans_cnt = 0;
	bool flag = false;

	for (int i = 0; i < P; i++) {
		int g_i;
		cin >> g_i;

		if (flag)
			continue;

		int gate_empty = gate_find_empty (g_i);
		if (gate_empty != 0) {
			gate_link_list[gate_empty]--;
			ans_cnt++;
		} else {
			flag = true;
		}
	}

	cout << ans_cnt;
}

int
main (void)
{
	fastio;

	int T = 1;
	// cin >> T;
	while (T--)
		solve ();

	return 0;
}
