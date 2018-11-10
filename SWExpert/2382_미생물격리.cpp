#include <iostream>

using namespace std;

int n,m,k, map[100][100],visit[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

struct Node {
	int x, y, num, d;
}typedef Node;

Node nodes[1000];

void disp() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < k; ++i) {
		if (nodes[i].num == 0) continue;
		int y = nodes[i].y;
		int x = nodes[i].x;
		map[y][x] = nodes[i].num;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int get_ans() {
	int ret = 0;
	for (int i = 0; i < k; ++i) {
		ret += nodes[i].num;
	}
	return ret;
}

int is_edge(int y, int x) {
	if (x == 0) return 1;
	if (x == n - 1) return 1;
	if (y == 0) return 1;
	if (y == n - 1) return 1;
	return 0;
}

int solution() {

	for (int i = 0; i < k; ++i) {
		if (nodes[i].num == 0) continue;
		int x = nodes[i].x;
		int y = nodes[i].y;
		int d = nodes[i].d;
		//printf("%d 세포 %d로 이동\n", nodes[i].num, d);
		int ny = dy[d] + y;
		int nx = dx[d] + x;
		if (is_edge(ny, nx)) {
			if (d == 0) nodes[i].d = 1;
			if (d == 1) nodes[i].d = 0;
			if (d == 2) nodes[i].d = 3;
			if (d == 3) nodes[i].d = 2;
			nodes[i].num /= 2;
		}
		else {
			visit[ny][nx] += 1;
		}
		nodes[i].x = nx;
		nodes[i].y = ny;
	}
// 이동완료

	//중복체크
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visit[i][j] > 1) {
				int cnt = 0;
				int target_idx = -1;
				int target_val = 0;
				int target_d = -1;
				for (int z = 0; z < k; ++z) {
					if (nodes[z].num == 0) continue;
					int x = nodes[z].x;
					int y = nodes[z].y;
					if (x == j && y == i) {
						//printf("(%d,%d)점에서 만남\n", y, x);
						if (target_val < nodes[z].num) {
							target_idx = z;
							target_val = nodes[z].num;
							target_d = nodes[z].d;
						}
						cnt += nodes[z].num;
						nodes[z].num = 0;
					}
				}
				//printf("(%d,%d)에서 %d가 이김%d\n",i,j, target_val,cnt);
				nodes[target_idx].d = target_d;
				nodes[target_idx].num = cnt;
			//	printf("(%d,%d), %d\n",i,j, nodes[target_idx].num);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visit[i][j] = 0;
		}
	}

	return 0;
}

int main(void) {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t) {
		cin >> n >> m >> k;

		for (int i = 0; i < k; ++i) {
			int y, x, num, d;
			cin >> y >> x >> num >> d;
			nodes[i].x = x;
			nodes[i].y = y;
			nodes[i].d = d-1;
			nodes[i].num = num;
		}
		for (int time = 0; time < m; ++time) {
			solution();
		}

		printf("#%d %d\n", t, get_ans());
	}
	return 0;
}
