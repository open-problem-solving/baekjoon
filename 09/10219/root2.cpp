#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

#define MAX_W 15

void
solve (void)
{
	int H, W;
	cin >> H >> W;
	
	for (int i = 0; i < H; i++) {
		char g[MAX_W] = {0};
		cin >> g;

		for (int j = W - 1; j >= 0; j--)
			cout << g[j];
		cout << '\n';
	}
}

int
main (void)
{
	fastio;

	int T = 1;
	cin >> T;
	while (T--)
		solve ();

	return 0;
}
