#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

struct area_info
{
	int sheep_count;
	int wolf_count;

	area_info operator+ (area_info const &o) const
	{
		return {sheep_count + o.sheep_count, wolf_count + o.wolf_count};
	}
};

int R, C;
char yard[251][251];

bool visited[251][251];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

struct area_info
area_search (int r, int c)
{
	visited[r][c] = true;

	struct area_info ret = {0, 0};
	if (yard[r][c] == 'o')
		ret.sheep_count++;
	else if (yard[r][c] == 'v')
		ret.wolf_count++;

	for (int i = 0; i < 4; i++) {
		int next_r = r + dr[i];
		int next_c = c + dc[i];

		if (next_r < 0 || R <= next_r || next_c < 0 || C <= next_c)
			continue;
		if (visited[next_r][next_c])
			continue;
		if (yard[next_r][next_c] == '#')
			continue;

		ret = ret + area_search (next_r, next_c);
	}

	return ret;
}

void
solve (void)
{
	cin >> R >> C;
	for (int r = 0; r < R; r++)
		cin >> yard[r];

	int ans_sheep = 0;
	int ans_wolf = 0;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (!visited[r][c] && yard[r][c] != '#') {
				struct area_info curr = area_search (r, c);

				if (curr.sheep_count > curr.wolf_count)
					ans_sheep += curr.sheep_count;
				else
					ans_wolf += curr.wolf_count;
			}
		}
	}

	cout << ans_sheep << ' ' << ans_wolf;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
