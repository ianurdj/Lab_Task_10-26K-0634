
#include <stdio.h>

int main(){
    FILE *fp;
    int i, n, count = 0;
    char cat[13], oldCat[13];
    float amt, newAmt, total = 0, oldAmt;

    char cats[4][13] = {"Food", "Transport", "Books", "Mobile"};
    float amts[4] = {1200, 500, 850, 300};

    fp = fopen("expenses.txt", "wb");

    if (fp == NULL){
        printf("Cannot create file");
        return 1;
    }

    for (i = 0; i < 4; i++){
               fprintf(fp, "%-12s %9.2f\n", cats[i], amts[i]);
}
    fclose(fp);

    printf("Category: ");
    scanf("%12s", cat);

    printf("Amount: ");
    scanf("%f", &amt);

    fp = fopen("expenses.txt", "ab");

    if (fp == NULL){
        printf("Cannot open file");
        return 1;
    }

    fprintf(fp, "%-12s %9.2f\n", cat, amt);
    fclose(fp);

    fp = fopen("expenses.txt", "rb+");

    if (fp == NULL){
        printf("Cannot open file");
        return 1;
    }

    fseek(fp, -46, SEEK_END);

    fscanf(fp, "%s %f", oldCat, &oldAmt);
    fscanf(fp, "%s %f", cat, &amt);

    printf("Latest two: %s %.2f, %s %.2f\n", oldCat, oldAmt, cat, amt);
        printf("Entry to fix: ");
    scanf("%d", &n);

    printf("New amount: ");
    scanf("%f", &newAmt);

    if (n < 1){
        printf("Invalid entry");
        fclose(fp);
        return 1;
    }

    fseek(fp, (n - 1) * 23, SEEK_SET);

    if (fscanf(fp, "%s %f", cat, &amt) != 2){
        printf("Entry not found");
        fclose(fp);
        return 1;
    }

    fseek(fp, (n - 1) * 23, SEEK_SET);
    fprintf(fp, "%-12s %9.2f\n", cat, newAmt);

    rewind(fp);

    while (fscanf(fp, "%s %f", cat, &amt) == 2)
    {
        printf("%-12s %.2f\n", cat, amt);
        total += amt;
        count++;
    }

    printf("Total: %.2f\n", total);

    fclose(fp);
    return 0;
}
