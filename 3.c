
#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp;
    int i, room, nights, r, n;
    char status, name[21], search[21];
    float rate;
    char guest[10][21];
    int rooms[10], found;

    fp = fopen("hotel.txt", "wb");

    if (fp == NULL) {
        printf("Cannot create file");
        return 1;
    }

    for (i = 101; i <= 110; i++){
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n", i, 'F', "-", 0, 8000.0);
    }
    fclose(fp);

    fp = fopen("hotel.txt", "rb+");

    if (fp == NULL)
    {
        printf("Cannot open file");
        return 1;
    }

    printf("Check-in room: ");
    scanf("%d", &room);

    printf("Name: ");
    scanf("%20s", name);

    printf("Nights: ");
    scanf("%d", &nights);

    if (room < 101 || room > 110)
    {
        printf("Invalid room");
        fclose(fp);
        return 1;
    }

    fseek(fp, (room - 101) * 40, SEEK_SET);
    fscanf(fp, "%d %c %s %d %f", &r, &status, guest[0], &n, &rate);

    if (status == 'F')
    {
        fseek(fp, (room - 101) * 40, SEEK_SET);
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n", room, 'B', name, nights, 8000.0);
        printf("Room booked\n");
    }
    else
        printf("Room already booked\n");

    rewind(fp);

    for (i = 0; i < 10; i++){
        fscanf(fp, "%d %c %s %d %f", &rooms[i], &status, guest[i], &n, &rate);

    printf("Search name: ");
    scanf("%20s", search);

    found = 0;
}

    for (i = 0; i < 10; i++)
      {
        if (strcmp(guest[i], search) == 0)
        {
            printf("%s is in room %d\n", search, rooms[i]);
            found = 1;
            break;
        }
      }

    if (!found){
        printf("Name not found\n");
    }
    printf("Check-out room: ");
    scanf("%d", &room);
    
    if (room < 101 || room > 110)
    {
        printf("Invalid room");
        fclose(fp);
        return 1;
        }

    fseek(fp, (room - 101) * 40, SEEK_SET);
    fscanf(fp, "%d %c %s %d %f", &r, &status, name, &nights, &rate);

    if (status == 'B'){
        printf("Bill: %d x %.2f = %.2f\n", nights, rate, nights * rate);

        fseek(fp, (room - 101) * 40, SEEK_SET);
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n", room, 'F', "-", 0, 8000.0);
    }
    else{
        printf("Room is already free\n");
    }
    fclose(fp);
    return 0;
}
