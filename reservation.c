#include <stdio.h>
#define TOTAL_SEATS 20
#define PRICE_LOW 500
#define PRICE_HIGH 1000
int main() {
    int seats[TOTAL_SEATS] = {0};
    int numUsers, numSeats, seatNumber, totalPrice = 0;
    printf("Enter the number of users booking tickets: ");
    scanf("%d", &numUsers);
    int userPrices[numUsers]; 
    for (int i = 0; i < numUsers; i++) {
        printf("\n--- User %d ---\n", i + 1);
        int userPrice = 0; 
        printf("Enter the number of seats to be booked: ");
        scanf("%d", &numSeats);
        for (int j = 0; j < numSeats; j++) {
            printf("Enter seat number %d: ", j + 1);
            scanf("%d", &seatNumber);
            if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
                printf("Invalid seat number. Please try again.\n");
                j--;  // 
                continue;
            }
            if (seats[seatNumber - 1] == 1) {
                printf("Seat number %d is already booked. Please choose another seat.\n", seatNumber);
                j--; 
                continue;
            }
            seats[seatNumber - 1] = 1;  

            if (seatNumber >= 1 && seatNumber <= 10) {
                userPrice += PRICE_LOW;
            } else {
                userPrice += PRICE_HIGH;
            }
        }
        userPrices[i] = userPrice;  
        totalPrice += userPrice;  
    }
    printf("\n--- Ticket Prices ---\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: Rs%d\n", i + 1, userPrices[i]);
    }
    printf("\nTotal price for all booked tickets: Rs%d\n", totalPrice);

    return 0;
}