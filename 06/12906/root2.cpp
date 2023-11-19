#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <string.h>
#include <set>
#include <queue>
#include <utility>

struct hanoi {
	string tower[3];
};

bool
check_hanoi_completed (struct hanoi &state)
{
	char ans_disk[] = "ABC";

	for (int i = 0; i < 3; i++) {
		for (char c : state.tower[i]) {
			if (c != ans_disk[i]) {
				return false;
			}
		}
	}

	return true;
}

string
remove_top (string &tower)
{
	string ret = "";
	for (int i = 0; i < tower.length () - 1; i++) {
		ret += tower[i];
	}
	return ret;
}

inline pair<pair<string, string>, string>
set_make_pair (struct hanoi &state)
{
	return { { state.tower[0], state.tower[1] }, state.tower[2] };
}

int
find_min_move (struct hanoi &start)
{
	queue<pair<struct hanoi, int>> q;
	set<pair<pair<string, string>, string>> visited;
	q.push ({ start, 0 });
	visited.insert (set_make_pair (start));

	int tower_move[3][2] = { { 1, 2 }, { 0, 2 }, { 0, 1 } };

	while (!q.empty ()) {
		struct hanoi curr = q.front ().first;
		int curr_cnt = q.front ().second;
		q.pop ();

		if (check_hanoi_completed (curr)) {
			return curr_cnt;
		}

		struct hanoi next;
		string src_tower;
		string move_disk;
		int dst_tower_idx;
		int rest_tower_idx;

		for (int i = 0; i < 3; i++) {
			src_tower = curr.tower[i];
			if (src_tower.length () <= 0) {
				continue;
			}

			next.tower[i] = remove_top (src_tower);
			move_disk = src_tower[src_tower.length () - 1];

			for (int j = 0; j < 2; j++) {
				dst_tower_idx = tower_move[i][j];
				rest_tower_idx = tower_move[i][(j + 1) & 1];

				next.tower[dst_tower_idx] = curr.tower[dst_tower_idx] + move_disk;
				next.tower[rest_tower_idx] = curr.tower[rest_tower_idx];
				if (visited.find (set_make_pair (next)) != visited.end ()) {
					continue;
				}

				q.push ({ next, curr_cnt + 1 });
				visited.insert (set_make_pair (next));
			}
		}
	}

	return -1;
}

void
solve (void)
{
	struct hanoi start;

	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;
		if (num != 0) {
			cin >> start.tower[i];
		}
		else {
			start.tower[i] = "";
		}
	}

	cout << find_min_move (start);
}

int
main (void)
{
	fastio;

	int T = 1;
	// cin >> T;
	while (T--) {
		solve ();
	}

	return 0;
}
