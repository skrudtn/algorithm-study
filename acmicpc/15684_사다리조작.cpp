#include <iostream>

using namespace std;

int ans,n,m,h,chk[3],map[31][11];

int correct() {
	int ret = 0;
	for (int start = 0; start < n; ++start) {
		int y = 0;
		int x = start;
		while (y != h) {
			if (map[y][x]) {
				x = map[y][x] - 1;
			}
			y += 1;
		}
		if (x != start) {
			return 0;
		}
	}

	return 1;
}

int can_put(int idx) {
	int row, col;
	row = idx / n;
	col = idx % n;
	if (col + 1 >= n) {
		return 0;
	}

	if (map[row][col] == 0 && map[row][col+1]==0) {
		return 1;
	}
	
	return 0;
}

void solution(int idx, int cnt, int cnt_max){
	if (cnt == cnt_max) {
		for (int i = 0; i < cnt_max; ++i) {
			int row = chk[i] / n;
			int col = chk[i] % n;
			map[row][col] = col+2;
			map[row][col+1] = col+1;
		}

		if (correct()) {
			ans = cnt_max;
		}
		
		for (int i = 0; i < cnt_max; ++i) {
			int row = chk[i] / n;
			int col = chk[i] % n;
			map[row][col] = 0;
			map[row][col+1] = 0;
		}
		
		return;
	}
	else if (idx == n * h) {
		return;
	}
	else {
		if (can_put(idx)) {
			chk[cnt] = idx;
			solution(idx + 1, cnt + 1, cnt_max);
		}
		chk[cnt] = 0;
		solution(idx + 1, cnt, cnt_max);
	}
}

int main(void) {
	ans = -1;
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		b--; a--;
		map[a][b + 1] = b+1;
		map[a][b] = b+2;
	}
	if (correct()) {
		ans = 0;
	}
	else {
		for (int i = 1; i <= 3; ++i) {
			if (ans != -1) break;
			solution(0, 0, i);
		}
	}
	printf("%d", ans);


	return 0;
}
