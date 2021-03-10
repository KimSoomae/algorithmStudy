#include <string>
#include <vector>

using namespace std;
string answer = "";
int tmp;
void find(int a, int tmp) {
	if (a < 1) {
		return;
	}
	tmp = a % 3;;
	find((a - 1) / 3, tmp);
	if (tmp == 1) {
		answer += "1";
	}
	else if (tmp == 2) {
		answer += "2";
	}
	else if (tmp == 0) {
		answer += "4";
	}

}
string solution(int n) {
	find(n, n % 3);
	return answer;
}