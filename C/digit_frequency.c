#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char string[1000];
    int n_count[10] = {0,0,0,0,0,0,0,0,0,0};

    scanf("%s", string);

    for(int i = 0; i < strlen(string); i++){
        if(string[i] == '0') n_count[0]++;
        if(string[i] == '1') n_count[1]++;
        if(string[i] == '2') n_count[2]++;
        if(string[i] == '3') n_count[3]++;
        if(string[i] == '4') n_count[4]++;
        if(string[i] == '5') n_count[5]++;
        if(string[i] == '6') n_count[6]++;
        if(string[i] == '7') n_count[7]++;
        if(string[i] == '8') n_count[8]++;
        if(string[i] == '9') n_count[9]++;
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", n_count[i]);
    }
    return 0;
}
