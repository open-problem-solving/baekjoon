#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <algorithm>
#include <string.h>

int N, K;
long long power_10[18] = {1};

long long N2K2sum[20][20];

long long
dp_subnumbers_sum (int n, int k, char *num)
{
	long long &ret = N2K2sum[n][k];

	if (ret != -1)
		return ret;

	if (k == 1 || n - k == 1) {
		ret = 0;

		int index_10 = max (k, n - k) - 1;
		bool flag = false;

		for (int i = N - n; i < N; i++) {
			if (flag) {
				ret += (num[i] - '0') * power_10[index_10];
				index_10--;
				continue;
			}

			if (i == N - 1) {
				ret += num[i] - '0';
			} else if (num[i] < num[i + 1]) {
				ret += num[i] - '0';
				flag = true;
			} else {
				ret += (num[i] - '0') * power_10[index_10];
				index_10--;
			}
		}
	} else {
		ret = max (dp_subnumbers_sum (n - 1, k, num) + (num[N - n] - '0') * power_10[n - k - 1],
				dp_subnumbers_sum (n - 1, k - 1, num) + (num[N - n] - '0') * power_10[k - 1]);
	}

	return ret;
}

void
solve (void)
{
	char number[20] = {0};
	
	cin >> N >> K;
	cin >> number;

	memset (N2K2sum, -1, sizeof (N2K2sum));

	if (N - K < K)
		K = N - K;

	cout << dp_subnumbers_sum (N, K, number) << '\n';
}

int
main (void)
{
	fastio;

	for (int i = 1; i < 18; i++)
		power_10[i] = power_10[i - 1] * 10;

	int T;
	cin >> T;
	while (T--)
		solve ();

	return 0;
}
