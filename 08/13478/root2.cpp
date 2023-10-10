#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

struct rectangle {
	double W, H;
};

int
rect_count_folding (struct rectangle src, struct rectangle dst)
{
	if (src.W < dst.W || src.H < dst.H) {
		return INT32_INF;
	}

	int cnt = 0;

	while (dst.W < src.W) {
		src.W /= 2;
		cnt++;
	}

	while (dst.H < src.H) {
		src.H /= 2;
		cnt++;
	}

	return cnt;
}

void
solve (void)
{
	struct rectangle init, target;
	cin >> init.W >> init.H;
	cin >> target.W >> target.H;

	struct rectangle tmp;
	int ans_cnt = INT32_INF;

	tmp.W = init.W;
	tmp.H = init.H;
	ans_cnt = min (ans_cnt, rect_count_folding (tmp, target));

	tmp.W = init.H;
	tmp.H = init.W;
	ans_cnt = min (ans_cnt, rect_count_folding (tmp, target));

	cout << (ans_cnt != INT32_INF ? ans_cnt : -1);
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
