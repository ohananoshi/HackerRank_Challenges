#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int a;
	int b;
	int c;
}triangle;

int comp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), comp);

}

int main()
{
	int n;
	int lado[50][3] = {32,56,43,46,67,45,48,42,25,50,39,57,26,20,13,35,30,15,65,11,61,59,21,67,30,39,60,38,53,18,30,53,24,40,31,25,27,57,38,47,48,62,17,27,35,55,61,50,68,44,66,24,58,52,53,44,44,69,63,69,26,22,8,60,65,64,55,53,54,24,36,33,43,29,50,28,26,40,42,42,53,2,64,65,68,39,60,50,60,54,66,62,64,13,17,23,62,58,62,50,46,62,19,44,62,63,29,48,53,51,3,38,46,27,30,44,40,35,34,4,41,44,38,53,40,30,38,32,52,69,38,67,68,33,68,25,31,41,63,41,55,38,21,42,63,56,34,33,16,36};
	double areas[n], semi_p;

	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		tr[i].a = lado[i][0];
		tr[i].b = lado[i][1];
		tr[i].c = lado[i][2];
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
        semi_p = (tr[i].a + tr[i].b + tr[i].c)/2;
        areas[i] = pow(semi_p*(semi_p-tr[i].a)*(semi_p-tr[i].b)*(semi_p-tr[i].c), 0.5);
		printf("%d %d %d - %.2f\n", tr[i].a, tr[i].b, tr[i].c, areas[i]);
	}
	return 0;
}
