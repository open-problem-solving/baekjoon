#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

void
solve (void)
{
	int N, M, K;
	cin >> N >> M >> K;
	cout << K / M << ' ' << K % M;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
