#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int a;
	int b;
	int c;
}triangle;

void modified_insertion_sort(double *a, int *index, int n){
    int i, j, temp, temp2;

    for(i = 1; i < n; i++){
        temp = a[i];
        for(j = i; ((j > 0) && (temp < a[j - 1])); j--){
            a[j] = a[j - 1];
            a[j - 1] = temp;
            temp2 = index[j];
            index[j] = index[j-1];
            index[j-1] = temp2;
        }
    }
}

double tr_area(int a, int b, int c){
    double semi_p, area;

    semi_p = (a+b+c)/2;
    area = pow(semi_p*(semi_p-a)*(semi_p-b)*(semi_p-c), 0.5);
    return area;
}

void sort_by_area(triangle* tr, int n) {

    double areas[n];
    int index[n];
    triangle temp;

    for(int i = 0; i < n; i++){
        index[i] = i;
        areas[i] = tr_area(tr[i].a, tr[i].b, tr[i].c);
    }

    modified_insertion_sort(areas, index, n);

    for(int i = 0; i < n; i++){
        printf("%d - %d - %.2f\n", i, index[i], areas[i]);
        if(i == index[i]) continue;
        else{
            temp.a = tr[i].a;
            temp.b = tr[i].b;
            temp.c = tr[i].c;
            printf("->%d - %d - %d\n", temp.a, temp.b, temp.c);
            tr[i].a = tr[index[i]].a;
            tr[i].b = tr[index[i]].b;
            tr[i].c = tr[index[i]].c;
            printf("->>%d - %d - %d\n", tr[i].a, tr[i].b, tr[i].c);
            tr[index[i]].a = temp.a;
            tr[index[i]].b = temp.b;
            tr[index[i]].c = temp.c;
            printf("->>>%d - %d - %d\n", tr[index[i]].a, tr[index[i]].b, tr[index[i]].c);
        }

    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
