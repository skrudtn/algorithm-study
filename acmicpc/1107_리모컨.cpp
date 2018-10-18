#include <iostream>
#include <string>

using namespace std;

int m, possi[10];
string dst;

int min(int a, int b) { return a > b ? b : a; }

int chk(string str) {
	for (int idx = 0; idx < str.length(); ++idx) {
		if (!possi[str.at(idx) - '0']) {
			return 0;
		}
	}
	return 1;
}


int main(void) {
	int ans = 0x7fffffff;
	string src = "100";
	cin >> dst;
	cin >> m;

	for (int i = 0; i < 10; ++i) {
		possi[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		possi[a] = 0;
	}

	for (int i = 0; i < 1000000; ++i) {
		string str = to_string(i);
		if (chk(str)) {
			int tmp = stoi(dst) - i;
			ans = min(ans, abs(tmp) + str.length());
		}
	}
	ans = min(ans, abs(stoi(dst) - stoi(src)));

	printf("%d\n", ans);
	return 0;
}
