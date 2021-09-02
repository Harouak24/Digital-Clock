#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int main(void) {
    int sec, min, hours, month, day, year;
    printf("Welcome to Harouak's Digital Clock!\n");
    printf("Set Date (EX: 04 09 2002): ");
    scanf("%d%d%d", &day, &month, &year);
    printf("Set Time (EX: 23 14 33): ");
    scanf("%d%d%d", &hours, &min, &sec);
    if (hours > 23 || min > 60 || sec > 60 || day > 31 || month > 12) {
        printf("Stop playing man!\n");
        return 0;
    }
    while (1) {
        system("clear");
        sec++;
        printf("\n\t\t---Harouak's Digital Clock---\n");
        printf("\n\t\t\tDate: %02d/%02d/%04d\n", day, month, year);
        printf("\n\t\t\tClock: %02d : %02d : %02d\n", hours, min, sec);
        printf("\n\t\t-----------------------------\n");
        fflush(stdout);
        if (sec > 59) {
            min++;
            sec = 0;
        }
        if (min > 59) {
            hours++;
            min = 0;
        }
        if (hours > 23) {
            hours = 0;
            min = 0;
            sec = 0;
            day++;
        }
        if ((month == 2 && day > 28) || (day > 31 && month % 2 == 1) || (day > 30 && month % 2 == 0)) {
            month++;
            day = 1;
        }
        if (month > 12) {
            month = 1;
            day = 1;
            year++;
        }
        sleep(1);
    }

    return 0;
}