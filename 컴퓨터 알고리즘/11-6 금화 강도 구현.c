
//동적프로그래밍
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(x,y) ((x)>(y) ? (x):(y))
#define min(x,y) ((x)<(y) ? (x):(y))

int A[8][8] =
{
	{1,3,7,2,11,17,16,25},
	{6,2,3,4,7,2,12,15},
	{11,4,6,8,8,1,9,14},
	{20,8,8,11,6,3,3,9},
	{0,10,9,8,7,15,17,22},
	{17,12,7,10,3,1,8,13},
	{19,25,10,15,14,11,3,3},
	{21,18,16,20,15,13,19,0}
};
int m[8][8];

int B[15][15];

void print(int n, int Arr[][8]) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)   
		{
			printf("%02d ", Arr[i][j]);
		}
		printf("\n");         
	}
}


int minGold(int n) {
	m[0][0] = A[0][0];
	int i, j, k;
	int minRight, minDown;
	int cost;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 && j == 0)
				continue;
			minRight = 100000;
			for (k = j - 1; k >= 0; k--) {
				cost = m[i][k] + A[i][j];
				minRight = min(minRight, cost);
			}
			minDown = 100000;
			for (k = i - 1; k >= 0; k--) {
				cost = m[k][j] + A[i][j];
				minDown = min(minDown, cost);
			}
			m[i][j] = min(minRight, minDown);
		}
	}

	return m[n-1][n-1];
}

int minGold_2(int n) {
	m[0][0] = B[0][0];
	int i, j, k;
	int minRight, minDown;
	int cost;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 && j == 0)
				continue;
			minRight = 100000;
			for (k = j - 1; k >= 0; k--) {
				cost = m[i][k] + B[i][j];
				minRight = min(minRight, cost);
			}
			minDown = 100000;
			for (k = i - 1; k >= 0; k--) {
				cost = m[k][j] + B[i][j];
				minDown = min(minDown, cost);
			}
			m[i][j] = min(minRight, minDown);
		}
	}

	return m[n - 1][n - 1];
}

int main() {
//	print(8, A);
//	print(8, m);  배열 출력

	printf("1번 : %d", minGold(8));	//원문제에 주어진 8x8 배열 A

	//임의의 15x15 배열
	srand((int)time(NULL));
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			B[i][j] = rand() % 99 + 1;
		}
	}
	printf("\n");

	printf("2번 : %d", minGold_2(15));

	return 0;
}




//분할통치법
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(x,y) ((x)>(y) ? (x):(y))
#define min(x,y) ((x)<(y) ? (x):(y))

int A[8][8] =
{
	{1,3,7,2,11,17,16,25},
	{6,2,3,4,7,2,12,15},
	{11,4,6,8,8,1,9,14},
	{20,8,8,11,6,3,3,9},
	{0,10,9,8,7,15,17,22},
	{17,12,7,10,3,1,8,13},
	{19,25,10,15,14,11,3,3},
	{21,18,16,20,15,13,19,0}
};

int B[15][15];

int rGoldForward(int i, int j) {
	if (i == 0 && j == 0)
		return A[0][0];

	int k;
	int minRight, minDown;
	int cost;

	minRight = 100000;
	for (k = j - 1; k >= 0; k--) {
		cost = rGoldForward(i,k) + A[i][j];
		minRight = min(minRight, cost);
	}
	minDown = 100000;
	for (k = i - 1; k >= 0; k--) {
		cost = rGoldForward(k,j) + A[i][j];
		minDown = min(minDown, cost);
	}
	
	return min(minRight, minDown);
}

int rGoldForward_2(int i, int j) {
	if (i == 0 && j == 0)
		return B[0][0];

	int k;
	int minRight, minDown;
	int cost;

	minRight = 100000;
	for (k = j - 1; k >= 0; k--) {
		cost = rGoldForward_2(i, k) + B[i][j];
		minRight = min(minRight, cost);
	}
	minDown = 100000;
	for (k = i - 1; k >= 0; k--) {
		cost = rGoldForward_2(k, j) + B[i][j];
		minDown = min(minDown, cost);
	}

	return min(minRight, minDown);
}

int main() {
	printf("1번 : %d\n", rGoldForward(7, 7));	//원문제에 주어진 8x8 배열 A

	//임의의 15x15 배열
	srand((int)time(NULL));
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			B[i][j] = rand() % 99 + 1;
		}
	}
	printf("\n");

	printf("2번 : %d", rGoldForward_2(14, 14));

	return 0;
}
