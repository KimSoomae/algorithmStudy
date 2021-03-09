#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
long long solution(int w, int h) {
	long long answer = 1;
	int temp = gcd(w, h);
	answer = long(w) * long(h);
	answer -= long(w) + long(h) - temp;

	return answer;
}