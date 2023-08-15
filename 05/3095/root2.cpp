#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

int N;
char matrix[2003][2003];

int matrix_sum[2003][2003];

int ans_cnt;

int matrix_calc_sum (int x1, int y1, int x2, int y2)
{
	return matrix_sum[x1][y1] + matrix_sum[x2 - 1][y2 - 1]
		- matrix_sum[x1][y2 - 1] - matrix_sum[x2 - 1][y1];
}

void
matrix_find_plus (int row, int col)
{
	int range;

	for (range = 1; true; range++) {
		if (row - range < 1 || N < row + range || col - range < 1 || N < col + range)
			break;

		if (matrix_calc_sum(row - 1, col - 1, row - range, col - range) != 0)
			break;
		if (matrix_calc_sum(row + range, col + range, row + 1, col + 1) != 0)
			break;
		if (matrix_calc_sum(row - 1, col + range, row - range, col + 1) != 0)
			break;
		if (matrix_calc_sum(row + range, col - 1, row + 1, col - range) != 0)
			break;

		if (matrix_calc_sum(row - 1, col, row - range, col) != range)
			break;
		if (matrix_calc_sum(row, col - 1, row, col - range) != range)
			break;
		if (matrix_calc_sum(row + range, col, row + 1, col) != range)
			break;
		if (matrix_calc_sum(row, col + range, row, col + 1) != range)
			break;

		ans_cnt++;
	}
}

void
solve (void)
{
	cin >> N;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> matrix[r][c];
			matrix_sum[r][c] = matrix[r][c] - '0'
					+ matrix_sum[r - 1][c] + matrix_sum[r][c - 1] - matrix_sum[r - 1][c - 1];
		}
	}

	ans_cnt = 0;
	for (int r = 2; r < N; r++) {
		for (int c = 2; c < N; c++) {
			if (matrix[r][c] == '1')
				matrix_find_plus (r, c);
		}
	}

	cout << ans_cnt;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
