#include <stdio.h>
void main() {
	int stack[100000]; char res[200000];
	int i, n, k, stkIdx = 0, resIdx = 0, max = 0; scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		if (k > max)
			for (i = max; i < k; i++) {
				stack[stkIdx++] = i + 1;
				res[resIdx++] = '+';
			}
		else
			if (stack[stkIdx - 1] != k) {
				puts("NO"); return;
			}
		stkIdx--;
		res[resIdx++] = '-';
		if (max < k) max = k;
	}
	for (i = 0; i < resIdx; i++) printf("%c\n", res[i]);
}
