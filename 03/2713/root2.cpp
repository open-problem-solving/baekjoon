#include <iostream>

using namespace std;
#define fastio	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INT32_INF 0x3f3f3f3f
#define INT64_INF 0x3f3f3f3f3f3f3f3f

#include <string.h>

void
solve (void)
{
	string str;
	getline (cin, str);

	int R = 0, C = 0;
	int idx = 0;

	while (str[idx] != ' ') {
		R *= 10;
		R += str[idx] - '0';
		idx++;
	}
	idx++;

	while (str[idx] != ' ') {
		C *= 10;
		C += str[idx] - '0';
		idx++;
	}
	idx++;
	
	char msg_binary[500] = {0};
	for (int i = 0; i < 500; i++)
		msg_binary[i] = '0';
	int msg_len = 0;

	for (int i = idx; i < str.length (); i++) {
		int msg_val = (str[i] != ' ') ? str[i] - 'A' + 1 : 0;
		msg_binary[5 * msg_len + 0] = ((msg_val & (1 << 4)) != 0) + '0';
		msg_binary[5 * msg_len + 1] = ((msg_val & (1 << 3)) != 0) + '0';
		msg_binary[5 * msg_len + 2] = ((msg_val & (1 << 2)) != 0) + '0';
		msg_binary[5 * msg_len + 3] = ((msg_val & (1 << 1)) != 0) + '0';
		msg_binary[5 * msg_len + 4] = ((msg_val & (1 << 0)) != 0) + '0';
		msg_len++;
	}

	char encode_matrix[30][30] = {0};
	int r, c;
	idx = 0;

	if (C <= R) {
		for (int i = 0; i < (C + 1) >> 1; i++) {
			for (r = i, c = i; c < C - i; c++) {
				encode_matrix[r][c] = msg_binary[idx++];
			}

			for (r = i + 1, c = C - i - 1; r < R - i; r++) {
				encode_matrix[r][c] = msg_binary[idx++];
			}

			if (i == ((C + 1) >> 1) - 1 && (C & 1) == 1)
				break;

			for (r = R - i - 1, c = C - i - 2; c >= i; c--) {
				encode_matrix[r][c] = msg_binary[idx++];
			}

			for (r = R - i - 2, c = i; r > i; r--) {
				encode_matrix[r][c] = msg_binary[idx++];
			}
		}
	} else {
		for (int i = 0; i < (R + 1) >> 1; i++) {
			for (r = i, c = i; c < C - i; c++) {
				encode_matrix[r][c] = msg_binary[idx++];
			}

			if (i == ((R + 1) >> 1) - 1 && (R & 1) == 1)
				break;

			for (r = i + 1, c = C - i - 1; r < R - i; r++) {
				encode_matrix[r][c] = msg_binary[idx++];
			}

			for (r = R - i - 1, c = C - i - 2; c >= i; c--) {
				encode_matrix[r][c] = msg_binary[idx++];
			}

			if (i == ((R + 1) >> 1) - 1)
				break;

			for (r = R - i - 2, c = i; r > i; r--) {
				encode_matrix[r][c] = msg_binary[idx++];
			}
		}
	}
	
	for (int r = 0; r < R; r++) {
		cout << encode_matrix[r];
	}
	cout << '\n';
}

int
main (void)
{
	fastio;

	int T = 1;
	cin >> T;
	cin.ignore ();
	while (T--)
		solve ();

	return 0;
}
