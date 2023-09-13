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
	
	char encode_matrix[30][30] = {0};
	int r, c;
	for (r = 0; r < R; r++)
		for (c = 0; c < C; c++)
			encode_matrix[r][c] = str[idx++];

	char msg_binary[500] = {0};
	idx = 0;

	if (C <= R) {
		for (int i = 0; i < (C + 1) >> 1; i++) {
			for (r = i, c = i; c < C - i; c++) {
				msg_binary[idx++] = encode_matrix[r][c];
			}

			for (r = i + 1, c = C - i - 1; r < R - i; r++) {
				msg_binary[idx++] = encode_matrix[r][c];
			}

			if (i == ((C + 1) >> 1) - 1 && (C & 1) == 1)
				break;

			for (r = R - i - 1, c = C - i - 2; c >= i; c--) {
				msg_binary[idx++] = encode_matrix[r][c];
			}

			for (r = R - i - 2, c = i; r > i; r--) {
				msg_binary[idx++] = encode_matrix[r][c];
			}
		}
	} else {
		for (int i = 0; i < (R + 1) >> 1; i++) {
			for (r = i, c = i; c < C - i; c++) {
				msg_binary[idx++] = encode_matrix[r][c];
			}

			if (i == ((R + 1) >> 1) - 1 && (R & 1) == 1)
				break;

			for (r = i + 1, c = C - i - 1; r < R - i; r++) {
				msg_binary[idx++] = encode_matrix[r][c];
			}

			for (r = R - i - 1, c = C - i - 2; c >= i; c--) {
				msg_binary[idx++] = encode_matrix[r][c];
			}

			if (i == ((R + 1) >> 1) - 1)
				break;

			for (r = R - i - 2, c = i; r > i; r--) {
				msg_binary[idx++] = encode_matrix[r][c];
			}
		}
	}

	string msg;

	for (int i = 4; i < idx; i += 5) {
		int msg_val = 0;
		msg_val += (msg_binary[i - 4] - '0') * (1 << 4);
		msg_val += (msg_binary[i - 3] - '0') * (1 << 3);
		msg_val += (msg_binary[i - 2] - '0') * (1 << 2);
		msg_val += (msg_binary[i - 1] - '0') * (1 << 1);
		msg_val += (msg_binary[i - 0] - '0') * (1 << 0);

		if (msg_val == 0)
			msg += ' ';
		else
			msg += (char) (msg_val - 1 + 'A');
	}
	
	if (msg.size () != 0) {
		for (int i = msg.length () - 1; i >= 0; i--) {
			if (msg[i] == ' ')
				msg.erase (i, 1);
			else
				break;
		}

		if (msg.size () != 0) {
			while (msg[0] == ' ') {
				msg = &msg[1];
			}
		}

		cout << msg;
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
