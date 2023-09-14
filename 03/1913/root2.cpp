#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define MAX_N 1003

void
solve (void)
{
	int N, value_find;
	cin >> N >> value_find;

	int table[MAX_N][MAX_N] = {0};
	int val = N * N;

	int r, c;
	int value_r = 0, value_c = 0;
	bool flag = true;

	for (int i = 0; i < (N + 1) >> 1; i++) {
		for (r = i, c = i; r < N - i; r++) {
			if (flag && val == value_find) {
				value_r = r;
				value_c = c;
				flag = false;
			}
			table[r][c] = val--;
		}

		if (i == N >> 1)
			break;

		for (r = N - i - 1, c = i + 1; c < N - i; c++) {
			if (flag && val == value_find) {
				value_r = r;
				value_c = c;
				flag = false;
			}
			table[r][c] = val--;
		}

		for (r = N - i - 2, c = N - i - 1; r >= i; r--) {
			if (flag && val == value_find) {
				value_r = r;
				value_c = c;
				flag = false;
			}
			table[r][c] = val--;
		}

		for (r = i, c = N - i - 2; c > i; c--) {
			if (flag && val == value_find) {
				value_r = r;
				value_c = c;
				flag = false;
			}
			table[r][c] = val--;
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << table[r][c] << ' ';
		}
		cout << '\n';
	}
	cout << value_r + 1 << ' ' << value_c + 1 << '\n';
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
