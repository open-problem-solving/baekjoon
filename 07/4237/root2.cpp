#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int n;
	int A[30004] = {0};

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];

	int B_cnt = 1;

	for (int i = 1; i < n; i++) {
		if (B_cnt & 1) {
			if (A[i] < A[i - 1])
				B_cnt++;
		} else {
			if (A[i - 1] < A[i])
				B_cnt++;
		}
	}

	cout << B_cnt << '\n';
}

int
main (void)
{
	fastio;

	int T;
	cin >> T;
	while (T--)
		solve ();

	return 0;
}
