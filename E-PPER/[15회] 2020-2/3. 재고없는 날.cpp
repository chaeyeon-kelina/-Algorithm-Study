#include <stdio.h>

int solution(int n, int m) {
	//�� �Ʒ� �ʿ��� ���� �� �ʿ��� �ڵ带 �ۼ��ϼ���
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
	int m;	//�԰�
	int n;	//��Ʈ�� ���
	int answer;
	scanf("%d %d", &n, &m);
	answer = solution(n, m);
	printf("%d", answer);

	return 0;
}