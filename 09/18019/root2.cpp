#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>

long long
calc_area (long long a0, long long a1, long long b0, long long b1, long long c0, long long c1)
{
	long long width = max (a1, b1) + c1;
	long long height = max (a0 + b0, c0);
	return width * height;
}

void
solve (void)
{
	long long rect[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> rect[i][j];
		}
	}

	long long ans_area = INT64_INF;

	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 2; b++) {
			for (int c = 0; c < 2; c++) {
				long long width = max (max (rect[0][a], rect[1][b]), rect[2][c]);
				long long height = rect[0][(a+1)&1] + rect[1][(b+1)&1] + rect[2][(c+1)&1];
				ans_area = min (ans_area, width * height);

				ans_area = min (ans_area, calc_area (rect[0][a], rect[0][(a+1)&1], rect[1][b], rect[1][(b+1)&1], rect[2][c], rect[2][(c+1)&1]));
				ans_area = min (ans_area, calc_area (rect[0][a], rect[0][(a+1)&1], rect[2][c], rect[2][(c+1)&1], rect[1][b], rect[1][(b+1)&1]));
				ans_area = min (ans_area, calc_area (rect[1][b], rect[1][(b+1)&1], rect[0][a], rect[0][(a+1)&1], rect[2][c], rect[2][(c+1)&1]));
				ans_area = min (ans_area, calc_area (rect[1][b], rect[1][(b+1)&1], rect[2][c], rect[2][(c+1)&1], rect[0][a], rect[0][(a+1)&1]));
				ans_area = min (ans_area, calc_area (rect[2][c], rect[2][(c+1)&1], rect[0][a], rect[0][(a+1)&1], rect[1][b], rect[1][(b+1)&1]));
				ans_area = min (ans_area, calc_area (rect[2][c], rect[2][(c+1)&1], rect[1][b], rect[1][(b+1)&1], rect[0][a], rect[0][(a+1)&1]));
			}
		}
	}

	cout << ans_area << '\n';
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
