
#include <stdio.h>

int main()
{
    FILE *fp;
    int i, roll, leave, r, att;
    char name[16];
    float per;
    int rolls[5] = {1, 2, 3, 4, 5};
    char names[5][16] = {"Ayesha", "Bilal", "Hamza", "Sana", "Zainab"};
    int marks[5] = {18, 14, 20, 12, 16};

    fp = fopen("attendance.txt", "wb");

    if (fp == NULL)
    {
        printf("Cannot create file");
        return 1;
     }

    for (i = 0; i < 5; i++){
        fprintf(fp, "%-3d %-15s %3d\n", rolls[i], names[i], marks[i]);
    }
    fclose(fp);

    fp = fopen("attendance.txt", "rb+");

    if (fp == NULL)
    {
        printf("Cannot open file");
        return 1;
     }

    printf("Roll number: ");
    scanf("%d", &roll);

    if (roll < 1 || roll > 5)
    {
        printf("Invalid roll number");
        fclose(fp);
        return 1;
     }

    fseek(fp, (roll - 1) * 24, SEEK_SET);
    fscanf(fp, "%d %s %d", &r, name, &att);

    per = att * 100.0 / 20;

    printf("%s: %d / 20 (%.1f%%)", name, att, per);
    if (per < 75)
        printf(" Short attendance");

    printf("\n");

    printf("Roll number for leave: ");
    scanf("%d", &roll);

    if (roll < 1 || roll > 5)
    {
        printf("Invalid roll number");
        fclose(fp);
        return 1;
    }

    printf("Lectures: ");
    scanf("%d", &leave);

    fseek(fp, (roll - 1) * 24, SEEK_SET);
    fscanf(fp, "%d %s %d", &r, name, &att);

    att = att + leave;

    if (att > 20){
        att = 20;
    }
    fseek(fp, (roll - 1) * 24, SEEK_SET);
    fprintf(fp, "%-3d %-15s %3d\n", r, name, att);

    printf("%s: %d / 20 (%.1f%%)\n", name, att, att * 100.0 / 20);

    fseek(fp, -24, SEEK_END);
    fscanf(fp, "%d %s %d", &r, name, &att);

    printf("Last record: %d %s %d\n", r, name, att);

    fclose(fp);
    return 0;
}
