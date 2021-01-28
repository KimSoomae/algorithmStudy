#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int T, result;
vector <pair<int, int>> spot; //거북이가 가는 위치 담을 벡터
string S;
char direction[4] = { 'N','W','S','E' };

void find_spot(char a, int d, int x, int y) { //거북이 옮겨주는 함수
	if (d == 0) {//북쪽 방향
		if (a == 'F') {
			spot.push_back(make_pair(x, y + 1));
			return;
		}
		else if (a == 'B') {
			spot.push_back(make_pair(x, y - 1));
			return;
		}
	}
	else if (d == 1) {//서쪽 방향
		if (a == 'F') {
			spot.push_back(make_pair(x - 1, y));
			return;
		}
		else if (a == 'B') {
			spot.push_back(make_pair(x + 1, y));
			return;
		}
	}

	else if (d == 2) {//남쪽 방향
		if (a == 'F') {
			spot.push_back(make_pair(x, y - 1));
			return;
		}
		else if (a == 'B') {
			spot.push_back(make_pair(x, y + 1));
			return;
		}
	}

	else {//동쪽 방향
		if (a == 'F') {
			spot.push_back(make_pair(x + 1, y));
			return;
		}
		else if (a == 'B') {
			spot.push_back(make_pair(x - 1, y));
			return;
		}
	}

}



int main()
{
	cin >> T;
	while (T > 0) {
		int d = 0;
		int minx = 0; int miny = 0; int maxx = 0; int maxy = 0;
		cin >> S;
		spot.clear();
		spot.push_back(make_pair(0, 0));
		for (int i = 0; i < S.size();i++) {
			int x = spot.back().first;
			int y = spot.back().second;
			if (S[i] == 'L') { //L이면 왼쪽으로 90도 돌려주기
				d++;
			}
			else if (S[i] == 'R') { //R이면 오른쪽으로 90도 돌려주기
				if (d == 0) {
					d += 3;
				}
				else {
					d--;
				}
			}
			else {
				d = d % 4; //방향은 4개밖에 없으니까
				find_spot(S[i], d, x, y);
			}
		}

		for (int i = 0; i < spot.size();i++) { //직사각형 넓이 구하기
			maxx = max(maxx, spot[i].first);
			maxy = max(maxy, spot[i].second);
			minx = min(minx, spot[i].first);
			miny = min(miny, spot[i].second);
		}
		result = (maxx - minx) * (maxy - miny);
		printf("%d\n", result);
		T--;
	}


}
