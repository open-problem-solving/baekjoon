#include <iostream>

using namespace std;
typedef long long	ll;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

void
string_set_first_alphabet (int *index_list, char *str)
{
	for (int i = 0; i < strlen (str); i++) {
		int alpha = str[i] - 'A';
		if (index_list[alpha] == -1)
			index_list[alpha] = i;
	}
}

void
solve (void)
{
	char A[31] = {0};
	char B[31] = {0};
	cin >> A >> B;

	int A_index[30];
	int B_index[30];
	memset (A_index, -1, sizeof (A_index));
	memset (B_index, -1, sizeof (B_index));
	string_set_first_alphabet (A_index, A);
	string_set_first_alphabet (B_index, B);

	int row, col;
	int loc = INT32_INF;
	for (int i = 0; i < 26; i++) {
		if (A_index[i] == -1 || B_index[i] == -1)
			continue;
		if (A_index[i] < loc) {
			loc = A_index[i];
			row = B_index[i];
			col = loc;
		}
	}

	int r, c;
	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++)
			cout << '.';
		cout << B[r];
		for (c++; c < strlen (A); c++)
			cout << '.';
		cout << '\n';
	}
	cout << A << '\n';
	for (r++; r < strlen (B); r++) {
		for (c = 0; c < col; c++)
			cout << '.';
		cout << B[r];
		for (c++; c < strlen (A); c++)
			cout << '.';
		cout << '\n';
	}
}

int
main (void)
{
	fastio;

	solve ();

	return 0;
}
