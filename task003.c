#include <stdio.h>
#include <string.h>
typedef struct {
    int num;
    char departcity[20];
    char destincity[20];
    char date[15];
    int seats;
} flight;
flight f[4];
void flightdetails() {
    int number, i, found = 0;
    printf("Enter flight number for details: ");
    scanf("%d", &number);
    for (i = 0; i < 4; i++) {
        if (number == f[i].num) {
            printf("\n--- Flight Details ---\n");
            printf("Flight number: %d\n", f[i].num);
            printf("Departure city: %s\n", f[i].departcity);
            printf("Destination city: %s\n", f[i].destincity);
            printf("Date: %s\n", f[i].date);
            printf("Available seats: %d\n\n", f[i].seats);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No information found for this flight.\n");
    }
}

void bookaseat() {
    int number, i, found = 0;
    printf("Enter flight number to book seat: ");
    scanf("%d", &number);
    for (i = 0; i < 4; i++) {
        if (number == f[i].num) {
            found = 1;
            if (f[i].seats > 0) {
                f[i].seats--;
                printf("Seat booked successfully! Remaining seats: %d\n", f[i].seats);
            } else {
                printf("Sorry! No seats left on this flight.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("No flight found with this number.\n");
    }
}
int main() {
    f[0].num = 101; strcpy(f[0].departcity, "Karachi"); strcpy(f[0].destincity, "Lahore"); strcpy(f[0].date, "10-12-25"); f[0].seats = 10;
    f[1].num = 202; strcpy(f[1].departcity, "Lahore"); strcpy(f[1].destincity, "Dubai"); strcpy(f[1].date, "14-12-25"); f[1].seats = 5;
    f[2].num = 303; strcpy(f[2].departcity, "Islamabad"); strcpy(f[2].destincity, "Karachi"); strcpy(f[2].date, "20-12-25"); f[2].seats = 4;
    f[3].num = 404; strcpy(f[3].departcity, "Karachi"); strcpy(f[3].destincity, "London"); strcpy(f[3].date, "25-12-25"); f[3].seats = 2;
    int choice;
    do {
        printf("\nWelcome to Airways\n");
        printf("1. Show Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                flightdetails();
                break;

            case 2:
                bookaseat();
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid input.\n");
        }
    } while (choice != 3);
    return 0;
}

