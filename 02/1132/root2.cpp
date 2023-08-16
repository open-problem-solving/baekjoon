#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>
#include <algorithm>

void
solve (void)
{
	int N;
	char natural_num[20] = {0};

	int alpha_cnt_bit = 0;
	bool alpha2first[10] = {false};
	ll alpha2digit_sum[10] = {0};	

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> natural_num;

		int first_alpha = natural_num[0] - 'A';
		if (!alpha2first[first_alpha])
			alpha2first[first_alpha] = true;

		ll digit = 1;
		for (int j = strlen (natural_num) - 1; j >= 0; j--, digit *= 10) {
			int alpha = natural_num[j] - 'A';
			alpha_cnt_bit |= 1 << alpha;
			alpha2digit_sum[alpha] += digit;
		}
	}

	if (alpha_cnt_bit == (1 << 10) - 1) {
		int min_alpha_not_first;
		ll min_digit_sum = INT64_INF;

		for (int i = 0; i < 10; i++) {
			if (!alpha2first[i] && alpha2digit_sum[i] < min_digit_sum) {
				min_alpha_not_first = i;
				min_digit_sum = alpha2digit_sum[i];
			}
		}
		alpha2digit_sum[min_alpha_not_first] = 0;
	}

	sort (alpha2digit_sum, alpha2digit_sum + 10);

	ll ans_sum = 0;
	for (int i = 9; i >= 0; i--)
		ans_sum += alpha2digit_sum[i] * i;
	cout << ans_sum;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
