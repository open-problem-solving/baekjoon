#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG_10_4 14
#define LOG_10_5 17
#define LOG_10_6 20

#include <vector>
#include <queue>
#include <string.h>

#define MAX_N 100005

struct burrow {
	int to;
	int length;
};

int N;
int energy[MAX_N];
vector<struct burrow> adj_list[MAX_N];

int level[MAX_N];
struct burrow sparse_table[MAX_N][LOG_10_5];

void
tree_set_level ()
{
	memset (level, -1, sizeof (level));

	queue<int> q;
	q.push (1);
	sparse_table[1][0] = { 1, 0 };
	level[1] = 0;

	while (!q.empty ()) {
		int curr = q.front ();
		q.pop ();

		for (struct burrow next : adj_list[curr]) {
			if (level[next.to] != -1) {
				continue;
			}

			sparse_table[next.to][0] = { curr, next.length };
			level[next.to] = level[curr] + 1;
			q.push (next.to);
		}
	}
}

void
sparse_table_init ()
{
	for (int j = 1; j < LOG_10_5; j++) {
		for (int i = 1; i <= N; i++) {
			struct burrow prev = sparse_table[i][j - 1];
			sparse_table[i][j] = { sparse_table[prev.to][j - 1].to,
				sparse_table[prev.to][j - 1].length + prev.length };
		}
	}
}

struct burrow
sparse_table_find_burrow (int src, int move_level)
{
	struct burrow dst = { src, 0 };

	for (int i = 0; i < LOG_10_5; i++) {
		if ((move_level & (1 << i)) != 0) {
			dst.length += sparse_table[dst.to][i].length;
			dst.to = sparse_table[dst.to][i].to;
		}
	}

	return dst;
}

int
ans_find_highest_room (int start)
{
	int left, right;
	left = 0;
	right = level[start];

	while (left <= right) {
		int mid = (left + right) >> 1;

		struct burrow move_result = sparse_table_find_burrow (start, mid);
		if (move_result.length < energy[start]) {
			left = mid + 1;
		}
		else if (move_result.length > energy[start]) {
			right = mid - 1;
		}
		else {
			return move_result.to;
		}
	}

	return sparse_table_find_burrow (start, right).to;
}

void
solve (void)
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> energy[i];
	}
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj_list[a].push_back ({ b, c });
		adj_list[b].push_back ({ a, c });
	}

	tree_set_level ();
	sparse_table_init ();

	for (int i = 1; i <= N; i++) {
		cout << ans_find_highest_room (i) << '\n';
	}
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
