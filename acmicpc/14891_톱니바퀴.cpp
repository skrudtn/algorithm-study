#include <iostream>

using namespace std;

int k,ans, map[4][8];

int get_ans() {
	int ret = 0;
	if (map[0][0]) ret += 1;
	if (map[1][0]) ret += 2;
	if (map[2][0]) ret += 4;
	if (map[3][0]) ret += 8;
	return ret;
}

void turn(int num, int d) {
	if (d == 1) {
		int tmp = map[num][7];
		for (int i = 6; i >= 0; --i) {
			map[num][i + 1] = map[num][i];
		}
		map[num][0] = tmp;
	}
	else {
		int tmp = map[num][0];
		for (int i = 0; i < 7; ++i) {
			map[num][i] = map[num][i + 1];
		}
		map[num][7] = tmp;
	}
}


void left_chk(int num, int d) {
	if (num == 0) {
		return;
	}
	if (map[num][6] == map[num - 1][2]) {
		return;
	}

	left_chk(num - 1, -d);
	turn(num-1, -d);
}

void right_chk(int num, int d) {
	if (num == 3) {
		return;
	}
	if (map[num][2] == map[num + 1][6]) {
		return;
	}

	right_chk(num + 1, -d);
	turn(num+1, -d);
}


int main(void) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 8; ++j) {
			scanf(" %1d",&map[i][j]);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int num, d;
		scanf("%d %d", &num, &d);
		num--;
		left_chk(num, d);
		right_chk(num, d);
		turn(num, d);
	}
	ans = get_ans();
	printf("%d", ans);

	return 0;
}
