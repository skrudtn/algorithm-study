#include <stdio.h>

using namespace std;

int n, m,arr[8],visit[8];

void swap(int a,int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void solution(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			arr[depth] = i+1;
			solution(depth + 1);
			visit[i] = 0;
		}
	}

}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 8; ++i) {
		arr[i] = i+1;
	}
	solution(0);
	return 0;
}
