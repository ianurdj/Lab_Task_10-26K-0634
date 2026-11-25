
#include <stdio.h>

int balance(int t[], int n, int bal){
    if (n == 0){
        return bal;
}
    return balance(t, n - 1, bal + t[n - 1]);
}

int deposits(int t[], int n){
    if (n == 0){
        return 0;
}
    if (t[n - 1] > 0){
        return t[n - 1] + deposits(t, n - 1);
    }
    return deposits(t, n - 1);
}

int copyLarge(int t[], int i, int n, int large[], int k){
    if (i == n){
        return k;
    }
    if (t[i] <= -10000){
        large[k] = t[i];
        k++;
    }

    return copyLarge(t, i + 1, n, large, k);
}

int main(){
    int start = 20000;
    int t[7] = {20000, -5000, -12000, 8000, -25000, -2500, 15000};
    int large[7];
    int count, i;

    printf("Final balance: %d\n", balance(t, 7, start));
    printf("Total deposits: %d\n", deposits(t, 7));

    count = copyLarge(t, 0, 7, large, 0);

    printf("Large withdrawals: ");

    for (i = 0; i < count; i++)
        printf("%d ", large[i]);

    printf("\n");

    return 0;
}
