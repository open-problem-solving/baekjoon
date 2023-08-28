#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

int
chocolate_cutting (int w, int h)
{
	if (w == 1 && h == 1)
		return 0;

	if (w < h) {
		int tmp = w;
		w = h;
		h = tmp;
	}

	return chocolate_cutting ((w >> 1) + (w & 1), h) + chocolate_cutting (w >> 1, h) + 1;
}

void
solve (void)
{
	int N, M;
	cin >> N >> M;
	cout << chocolate_cutting (N, M);
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
