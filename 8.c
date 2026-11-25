
#include <stdio.h>

void makeScore(int change[], int score[], int i, int n, int cur){
    if (i == n)
        return;

    cur = cur + change[i];
    score[i] = cur;

    makeScore(change, score, i + 1, n, cur);
}

int lowCount(int score[], int n){
    if (n == 0)
        return 0;

    if (score[n - 1] < 50)
        return 1 + lowCount(score, n - 1);

    return lowCount(score, n - 1);
}

void reverse(int a[], int l, int r){
int temp;

    if (l >= r){
        return;
    }

    temp = a[l];
    a[l] = a[r];
    a[r] = temp;

    reverse(a, l + 1, r - 1);
}

int main(){
    int start = 70;
    int change[10] = {5, -8, -10, -12, 4, 6, 3, 7, -2, 5};
    int score[10];
    int i;
    makeScore(change, score, 0, 10, start);

    printf("Daily scores: ");

    for (i = 0; i < 10; i++)
        printf("%d ", score[i]);

    printf("\n");

    printf("Days below 50: %d\n", lowCount(score, 10));

    reverse(score, 0, 9);

    printf("Latest first: ");
    
    for (i = 0; i < 10; i++)
        printf("%d ", score[i]);

    printf("\n");

    return 0;
}
