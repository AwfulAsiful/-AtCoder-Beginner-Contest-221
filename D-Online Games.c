/* https://atcoder.jp/contests/abc221/tasks/abc221_d */

#include <stdio.h>

typedef struct {
	int key, id;
} data;

void merge_sort(int n, data x[])
{
	static data y[400003] = {};
	if (n <= 1) return;
	merge_sort(n / 2, &(x[0]));
	merge_sort((n + 1) / 2, &(x[n/2]));
	
	int i, p, q;
	for (i = 0, p = 0, q = n / 2; i < n; i++) {
		if (p >= n / 2) y[i] = x[q++];
		else if (q >= n) y[i] = x[p++];
		else y[i] = (x[p].key < x[q].key)? x[p++]: x[q++];
	}
	for (i = 0; i < n; i++) x[i] = y[i];
}

int main()
{
	int i, N, A[200001], B[200001];
	data d[400003];
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &(A[i]), &(B[i]));
		d[i*2-2].key = A[i];
		d[i*2-2].id = i;
		d[i*2-1].key = A[i] + B[i];
		d[i*2-1].id = i + N;
	}
	merge_sort(N * 2, d);
	
	int j, n = 0, x[400001];
	for (i = 0; i < N * 2; i = j) {
		x[++n] = d[i].key;
		for (j = i; j < N * 2 && d[j].key == x[n]; j++) {
			if (d[j].id <= N) A[d[j].id] = n;
			else B[d[j].id - N] = n;
		}
	}
	
	int k, num[400001] = {}, ans[200001] = {};
	for (i = 1; i <= N; i++) {
		num[A[i]]++;
		num[B[i]]--;
	}
	for (i = 1, k = 0; i < n; i++) {
		k += num[i];
		ans[k] += x[i+1] - x[i];
	}
	for (i = 1; i < N; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[N]);
	fflush(stdout);
	return 0;
}