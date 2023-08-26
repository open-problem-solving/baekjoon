#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

struct cake {
	int x, y, z;
};

void
solve (void)
{
	cake a, c;
	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;
	cout << c.x - a.z << ' ' << c.y / a.y << ' ' << c.z - a.x;
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
