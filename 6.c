
#include <stdio.h>

void grow(int h[], int n){
    if (n == 0)
        return;
    h[n - 1] = h[n - 1] + (int)(h[n - 1] * 0.10);

    grow(h, n - 1);
}

int tallest(int h[], int n){
    int p;

    if (n == 1){
        return 0;
}
    p = tallest(h, n - 1);

    if (h[n - 1] > h[p]){
        return n - 1;
    }
    return p;
}

int search(int h[], int n, int target){
    if (n == 0){
        return -1;
}
    if (h[n - 1] == target){
        return n - 1;
    }
    return search(h, n - 1, target);
}

int main(){
    int id[6] = {101, 102, 103, 104, 105, 106};
    int h[6] = {45, 120, 78, 200, 95, 150};
    int i, p, target;

    grow(h, 6);

    printf("New heights: ");

    for (i = 0; i < 6; i++)
        printf("%d ", h[i]);

    printf("\n");

    p = tallest(h, 6);

    printf("Tallest: tower %d (%d m)\n", id[p], h[p]);
    printf("Height to search: ");
    scanf("%d", &target);

    p = search(h, 6, target);

    if (p == -1){
        printf("Tower not found\n");
}
    else{
        printf("Tower %d is %d m\n", id[p], h[p]);
}
    return 0;
}
