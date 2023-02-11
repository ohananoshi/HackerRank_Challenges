#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.

    int max_end = 0, max_or = 0, max_xor = 0;
    int i, u;

    for(i = 1; i < n; i++){
      for(u = i + 1; u <= n; u++){
          if(((i & u) > max_end) && ((i & u) < k)) max_end = (i & u);
          if(((i | u) > max_or) && ((i | u) < k)) max_or = (i | u);
          if(((i ^ u) > max_xor) && ((i ^ u) < k)) max_xor = (i ^ u);
          printf("%d - %d\n",i,u);
      }
    }
    printf("%d\n%d\n%d",max_end, max_or, max_xor);
}

int main() {
    int n, k;

    do{
        scanf("%d %d", &n, &k);
    }while(((n < 2) || (n > 1000)) || ((k < 2) || (k > n)));
    calculate_the_maximum(n, k);

    return 0;
}
