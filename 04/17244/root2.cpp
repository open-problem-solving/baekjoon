#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <queue>
#include <string.h>

#define MAX_N 51
#define MAX_M 51
#define MAX_BIT ((1 << 5) - 1)

struct search_frame {
	int r, c;
	int item_bit;
	int cnt_search;
};

int N, M;
char house_map[MAX_N][MAX_M];

vector<int> item_pos_list;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int searching_dp[MAX_N][MAX_M][MAX_BIT + 1];

int
convert_item_pos_idx (int item_pos)
{
	for (int i = 0; i < item_pos_list.size (); i++) {
		if (item_pos_list[i] == item_pos) {
			return i;
		}
	}
	return -1;
}

int
map_find_min_route (int src, int dst)
{
	queue<struct search_frame> q;
	q.push ({ src / 100, src % 100, MAX_BIT - (1 << item_pos_list.size ()) + 1, 0});
	searching_dp[src / 100][src % 100][0] = 0;

	while (!q.empty ()) {
		struct search_frame curr = q.front ();
		q.pop ();

		for (int i = 0; i < 4; i++) {
			int next_r = curr.r + dr[i];
			int next_c = curr.c + dc[i];

			if (next_r < 1 || M < next_r || next_c < 1 || N < next_c) {
				continue;
			}
			else if (house_map[next_r][next_c] == '#') {
				continue;
			}

			if (house_map[next_r][next_c] == '.' || house_map[next_r][next_c] == 'S') {
				if (searching_dp[next_r][next_c][curr.item_bit] != -1) {
					continue;
				}

				searching_dp[next_r][next_c][curr.item_bit] = curr.cnt_search + 1;
				q.push ({ next_r, next_c, curr.item_bit, curr.cnt_search + 1 });
			}
			else if (house_map[next_r][next_c] == 'E') {
				if (curr.item_bit == MAX_BIT) {
					return curr.cnt_search + 1; 
				}
				
				searching_dp[next_r][next_c][curr.item_bit] = curr.cnt_search + 1;
				q.push ({ next_r, next_c, curr.item_bit, curr.cnt_search + 1 });
			}
			else if (house_map[next_r][next_c] == 'X') {
				int item_idx = convert_item_pos_idx (next_r * 100 + next_c);
				int next_item_bit = curr.item_bit | (1 << item_idx);

				if (searching_dp[next_r][next_c][next_item_bit] != -1) {
					continue;
				}

				searching_dp[next_r][next_c][next_item_bit] = curr.cnt_search + 1;
				q.push ({ next_r, next_c, next_item_bit, curr.cnt_search + 1 });
			}
		}
	}

	return -1;
}

void
solve (void)
{
	int pos_src;
	int pos_dst;

	cin >> N >> M;
	for (int r = 1; r <= M; r++) {
		for (int c = 1; c <= N; c++) {
			char space;
			cin >> space;
			house_map[r][c] = space;

			if (space == 'X') {
				item_pos_list.push_back (r * 100 + c);
			}
			else if (space == 'S') {
				pos_src = r * 100 + c;
			}
			else if (space == 'E') {
				pos_dst = r * 100 + c;
			}
		}
	}

	memset (searching_dp, -1, sizeof (searching_dp));

	cout << map_find_min_route (pos_src, pos_dst);
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
