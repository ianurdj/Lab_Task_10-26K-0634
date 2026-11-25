
#include <stdio.h>

int main()
{
    FILE *fp;
    int i, n;
    char city[11], hotCity[11];
    float temp, updTemp, maxTemp = -100;

    fp = fopen("temperature.txt", "wb");

    if (fp == NULL)
    {
        printf("Cannot create file");
        return 1;
    }

    for (i = 0; i < 5; i++)
    {
        printf("Enter city and temperature: ");
        scanf("%10s %f", city, &temp);
        fprintf(fp, "%-10s %5.1f\n", city, temp);
    }
    fclose(fp);

    fp = fopen("temperature.txt", "rb+");

    if (fp == NULL)
    {
        printf("Cannot open file");
        return 1;
    }

    printf("Enter city number: ");
    scanf("%d", &n);

    if (n < 1 || n > 5)
    {
        printf("Invalid number");
        fclose(fp);
        return 1;
    }

    fseek(fp, (n - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f", city, &temp);
    printf("%s %.1f\n", city, temp);

    printf("City number to update: ");
    scanf("%d", &n);

    if (n < 1 || n > 5)
    {
        printf("Invalid number");
        fclose(fp);
        return 1;
        }

    printf("New temperature: ");
    scanf("%f", &updTemp);
    fseek(fp, (n - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f", city, &temp);
    fseek(fp, (n - 1) * 17, SEEK_SET);
    fprintf(fp, "%-10s %5.1f\n", city, updTemp);

    printf("%s updated\n", city);

    rewind(fp);

    for (i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %f", city, &temp);

        if (temp > maxTemp)
        {
            maxTemp = temp;
            sprintf(hotCity, "%s", city);
            }
     }

    printf("Hottest city: %s (%.1f)\n", hotCity, maxTemp);

    fclose(fp);
    return 0;
}
