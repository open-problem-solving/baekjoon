#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <string.h>

#define MAX_N 100005

int parent_piece[MAX_N];
int weight_diff_root[MAX_N];

int
weight_find_parent (int piece_num)
{
	int curr_parent = parent_piece[piece_num];

	if (curr_parent == -1) {
		return piece_num;
	}

	int new_parent = weight_find_parent (curr_parent);
	weight_diff_root[piece_num] += weight_diff_root[curr_parent];
	return parent_piece[piece_num] = new_parent;
}

void
weight_union (int a, int b, int w)
{
	int root_a = weight_find_parent (a);
	int root_b = weight_find_parent (b);

	if (root_a == root_b) {
		return;
	}

	weight_diff_root[root_b] = weight_diff_root[a] - weight_diff_root[b] + w;
	parent_piece[root_b] = root_a;
}

int
weight_calc_diff (int a, int b)
{
	if (weight_find_parent (a) == weight_find_parent (b)) {
		return weight_diff_root[b] - weight_diff_root[a];
	}
	else {
		return INT32_INF;
	}
}

void
solve (void)
{
	int N, M;
	char opt;
	int a, b, w;

	while (true) {
		memset (parent_piece, -1, sizeof (parent_piece));
		memset (weight_diff_root, 0, sizeof (weight_diff_root));

		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}

		for (int i = 0; i < M; i++) {
			cin >> opt >> a >> b;
			if (opt == '!') {
				cin >> w;
			}

			if (opt == '!') {
				weight_union (a, b, w);
			}
			else if (opt == '?') {
				int diff = weight_calc_diff (a, b);
				if (diff != INT32_INF) {
					cout << diff << '\n';
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
		}
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
