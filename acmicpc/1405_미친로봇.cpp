#include <iostream>
#include <cmath>

using namespace std;

int n, visit[29][29], map[29][29];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
double percent[4];

double solution(int y, int x, int cnt) {
	if (cnt == n) {
		return 1.0;
	}
	double ret = 0.0;
	for (int d = 0; d < 4; ++d) {
		
		int nx = dx[d] + x;
		int ny = dy[d] + y;
		if (visit[ny][nx]) continue;
		visit[ny][nx] = 1;
		ret += solution(ny, nx, cnt + 1) * percent[d];
		visit[ny][nx] = 0;
	}

	return ret;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < 4; ++i) {
		cin >> percent[i];
		percent[i] *= 0.01;
	}

	visit[14][14] = 1;
	double ans = solution(14, 14, 0);

	printf("%0.9f\n", ans);

	return 0;
}
