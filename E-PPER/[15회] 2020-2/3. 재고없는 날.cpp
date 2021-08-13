#include <stdio.h>

int solution(int n, int m) {
	//이 아래 필요한 변수 및 필요한 코드를 작성하세요
	int answer = 0;
	while (n != 0) {
		answer++;
		if (answer % m == 0)
			n += 1;
		n--;
	}
	return answer;
}

int main() {
	int m;	//입고
	int n;	//노트북 재고
	int answer;
	scanf("%d %d", &n, &m);
	answer = solution(n, m);
	printf("%d", answer);

	return 0;
}
