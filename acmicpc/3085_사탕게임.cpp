#include <iostream>

using namespace std;

int n;
char map[50][50];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

int max(int a, int b) { return a > b ? a : b; }

int chk() {
	int ret = 0;

	for (int i = 0; i < n; ++i) {
		for (int src = 0; src < n; ++src) {
			char target = map[i][src];
			int cnt = 0;
			for (int j = src; j < n; ++j) {
				if (target != map[i][j]) {
					ret = max(ret, cnt);
					break;
				}
				cnt++;
			}
			ret = max(ret, cnt);
		}
	}

	for (int j = 0; j < n; ++j) {
		for (int src = 0; src < n; ++src) {
			char target = map[src][j];
			int cnt = 0;
			for (int i = src; i < n; ++i) {
				if (target != map[i][j]) {
					ret = max(ret, cnt);
					break;
				}
				cnt++;
			}
			ret = max(ret, cnt);
		}
	}

	return ret;
}

int isOnMap(int y, int x) {
	return y < n && x < n;
}

void swap(int y1, int x1, int y2, int x2) {
	char tmp = map[y1][x1];
	map[y1][x1] = map[y2][x2];
	map[y2][x2] = tmp;
}

int main(void) {
	int ans=0;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf(" %1c", &map[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int d = 0; d < 2; ++d) {
				int nx = dx[d] + j;
				int ny = dy[d] + i;
				if (!isOnMap(ny, nx)) continue;
				swap(i, j, ny, nx);
				ans = max(ans, chk());
				swap(i, j, ny, nx);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

