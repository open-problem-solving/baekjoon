#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#define LOG2_10_4 14
#define LOG2_10_5 17
#define LOG2_10_6 20

#include <vector>

#define MAX_ANGLE 360000

vector<int>
kmp_get_partial_match (vector<bool> &pattern)
{
	int const size = pattern.size ();
	vector<int> pi (size, 0);
	int matched = 0;

	for (int i = 1; i < size; i++) {
		while (matched > 0 && pattern[i] != pattern[matched]) {
			matched = pi[matched - 1];
		}
		if (pattern[i] == pattern[matched]) {
			matched++;
			pi[i] = matched;
		}
	}

	return pi;
}

bool
kmp_search (vector<bool> &src, vector<bool> &pattern)
{
	int const src_size = src.size ();
	int const pattern_size = pattern.size ();

	vector<int> pi = kmp_get_partial_match (pattern);
	int matched = 0;

	for (int i = 0; i < src_size; i++) {
		while (matched > 0 && src[i] != pattern[matched]) {
			matched = pi[matched - 1];
		}
		if (src[i] == pattern[matched]) {
			if (matched == pattern_size - 1) {
				return true;
			}
			else {
				matched++;
			}
		}
	}

	return false;
}

void
solve (void)
{
	int n;
	cin >> n;

	vector<bool> clock[2];
	clock[0].resize (MAX_ANGLE << 1, false);
	clock[1].resize (MAX_ANGLE, false);

	for (int i = 0; i < n; i++) {
		int angle;
		cin >> angle;
		clock[0][angle] = clock[0][MAX_ANGLE + angle] = true;
	}
	for (int i = 0; i < n; i++) {
		int angle;
		cin >> angle;
		clock[1][angle] = true;
	}

	if (kmp_search (clock[0], clock[1])) {
		cout << "possible";
	}
	else {
		cout << "impossible";
	}
}

int
main (void)
{
	fastio;

	int T = 1;
	// cin >> T;
	while (T--) {
		solve ();
	}

	return 0;
}
