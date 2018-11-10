//5:39 ~ 6:22
//7:39 ~ 8:31
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ans,n,p_cnt,s_cnt,map[10][10];

struct Step {
	int y, x, k,weight=3;
}typedef Step;

struct Person {
	int y, x, dst, dist, depth=0, arrive=0, clear=0;
}typedef Person;

Person person[10];
Step steps[2];

vector<Person> a_person;
vector<Person> b_person;

bool cmp(const Person &p1,const Person &p2) {
	return p1.dist < p2.dist ? 1 : 0;
}

int abs(int a) { return a >= 0 ? a : -a; }
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }

int get_dist(int y1, int x1, int y2, int x2) {
	return abs(y1 - y2) + abs(x1 - x2);
}

int clear(int flg) {
	Person cur;
	if (flg) {
		for (int i = 0; i < a_person.size(); ++i) {
			cur = a_person[i];
			if (!cur.clear) {
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i < b_person.size(); ++i) {
			cur = b_person[i];
			if (!cur.clear) {
				return 0;
			}
		}
	}
	//printf("clear");
	return 1;
}

int solution() {
	int a_time = 0;
	
	while (!clear(1)) {
		a_time++;
		for (int i = 0; i < a_person.size(); ++i) {
			Person *cur = &a_person[i];
			Step *dst_step = &steps[cur->dst];
			if (cur->clear) continue;
			if (cur->arrive) {
				if (cur->depth == 0) {
					
					if (dst_step->weight) {
						dst_step->weight--;
						cur->depth++;
					}
					else {
					}
				}
				else {
					if (cur->depth == dst_step->k) {
						cur->clear = 1;
						dst_step->weight++;
					}
					else {
						cur->depth++;
					}
				}
			}
			else {
				if (cur->dist == a_time) {
					cur->arrive = 1;
				}
			}

		}
	}

	int b_time = 0;
	while (!clear(0)) {
		b_time++;
		for (int i = 0; i < b_person.size(); ++i) {
			Person *cur = &b_person[i];
			Step *dst_step = &steps[cur->dst];
			if (cur->clear) continue;
			if (cur->arrive) {
				if (cur->depth == 0) {

					if (dst_step->weight) {
						dst_step->weight--;
						cur->depth++;
					}
					else {
					}
				}
				else {
					if (cur->depth == dst_step->k) {
						cur->clear = 1;
						dst_step->weight++;
					}
					else {
						cur->depth++;
					}
				}
			}
			else {
				if (cur->dist == b_time) {
					cur->arrive = 1;
				}
			}

		}
	}

	return max(a_time,b_time);
}

void init_all() {
	for (int i = 0; i < p_cnt; ++i) {
		person[i].arrive = 0;
		person[i].clear = 0;
		person[i].depth = 0;
		person[i].x = 0;
		person[i].y = 0;
		person[i].dist = -1;
		person[i].dst = -1;
	}
	for (int i = 0; i < s_cnt; ++i) {
		steps[i].weight = 3;
		steps[i].k = 0;
		steps[i].x = 0;
		steps[i].y = 0;
	}
}

void init() {
	for (int i = 0; i < p_cnt; ++i) {
		person[i].arrive = 0;
		person[i].clear = 0;
		person[i].depth = 0;
	}
	for (int i = 0; i < s_cnt; ++i) {
		steps[i].weight = 3;
	}
}

void dfs(int cnt) {
	if (cnt == p_cnt) {
		a_person.clear();
		b_person.clear();
		for (int i = 0; i < p_cnt; ++i) {
			if (person[i].dst == 0) {
				a_person.push_back(person[i]);
			}
			else if (person[i].dst == 1) {
				b_person.push_back(person[i]);
			}
		}
		
		sort(a_person.begin(), a_person.end(), cmp);
		sort(b_person.begin(), b_person.end(), cmp);
		//목적지 결정 완료

		init();
		ans = min(ans, solution());
		return;
	} else{
		person[cnt].dst = 0;
		person[cnt].dist = get_dist(person[cnt].y, person[cnt].x, steps[0].y, steps[0].x);
		dfs(cnt + 1);
		person[cnt].dst = 1;
		person[cnt].dist = get_dist(person[cnt].y, person[cnt].x, steps[1].y, steps[1].x);
		dfs(cnt + 1);
	}
}

int main(void) {
	int tc,tmp;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		cin >> n;
		p_cnt = s_cnt = 0;
		ans = 0x7fffffff;
		init_all();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> tmp;
				if (tmp == 1) {
					person[p_cnt].x = j;
					person[p_cnt].y = i;
					p_cnt++;
				}
				else if (tmp > 1) {
					steps[s_cnt].x = j;
					steps[s_cnt].y = i;
					steps[s_cnt].k = tmp;
					s_cnt++;
				}
				map[i][j] = tmp;
			}
		}
		dfs(0);
		cout << "#" << t << " " << ans << endl;
	}

	return 0;
}

