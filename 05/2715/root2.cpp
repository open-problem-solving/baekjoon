#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <vector>
#include <math.h>
#include <algorithm>

int
find_max_abs_idx (int arr[50], int start, int end)
{
	int val_max = -INT32_INF;
	int idx;

	for (int i = start; i <= end; i++) {
		int arr_val = abs (arr[i]);
		if (val_max < arr_val) {
			val_max = arr_val;
			idx = i;
		}
	}

	return idx;
}

void
flip_pancakes (int arr[50], int end)
{
	reverse (arr + 1, arr + end + 1);
	for (int i = 1; i <= end; i++)
		arr[i] *= -1;
}

void
solve (void)
{
	int M;
	int pancake_list[50] = {0};

	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> pancake_list[i];

	vector<int> ans_flip;

	for (int i = M; i > 0; i--) {
		if (i == 1) {
			if (pancake_list[1] < 0)
				ans_flip.push_back (1);
			break;
		}

		int max_idx = find_max_abs_idx (pancake_list, 1, i);

		if (max_idx == i) {
			if (pancake_list[max_idx] > 0)
				continue;
			ans_flip.push_back (max_idx);
			ans_flip.push_back (1);
			ans_flip.push_back (i);
		} else if (max_idx == 1) {
			if (pancake_list[max_idx] > 0)
				ans_flip.push_back (1);
			ans_flip.push_back (i);
			flip_pancakes (pancake_list, i);
		} else {
			ans_flip.push_back (max_idx);
			flip_pancakes (pancake_list, max_idx);
			ans_flip.push_back (1);
			ans_flip.push_back (i);
			flip_pancakes (pancake_list, i);
		}
	}

	cout << ans_flip.size () << ' ';
	for (int num : ans_flip)
		cout << num << ' ';
	cout << '\n';
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
