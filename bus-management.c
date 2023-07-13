#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TICKETS 100 // Maximum number of tickets available
#define MAX_NAME_LEN 50 // Maximum length of passenger name

struct Ticket {
    int id; // Unique identifier for the ticket
    char name[MAX_NAME_LEN]; // Name of the passenger
    int seat_num; // Seat number
    int bus_num; // Bus number
    float price; // Price of the ticket
    int is_booked; // Indicates whether the ticket is booked or not
};

// Initializes the ticket array with default values
void init_tickets(struct Ticket tickets[]) {
    for (int i = 0; i < MAX_TICKETS; i++) {
        tickets[i].id = i + 1;
        tickets[i].name[0] = '\0';
        tickets[i].seat_num = i + 1;
        tickets[i].bus_num = 0;
        tickets[i].price = 0.0;
        tickets[i].is_booked = 0;
    }
}

// Displays the menu options
void display_menu() {
    printf("Online Bus Tickets\n");
    printf("-------------------\n");
    printf("1. Book a ticket\n");
    printf("2. Cancel a ticket\n");
    printf("3. Display all tickets\n");
    printf("4. Exit\n");
}

// Books a ticket by finding the first available seat and assigning it to the passenger
void book_ticket(struct Ticket tickets[]) {
    char name[MAX_NAME_LEN];
    float price;
    int bus_num;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the price of the ticket: ");
    scanf("%f", &price);

    printf("Enter the bus number: ");
    scanf("%d", &bus_num);

    // Find the first available seat and assign it to the passenger
    int seat_num = -1;
    for (int i = 0; i < MAX_TICKETS; i++) {
        if (!tickets[i].is_booked) {
            seat_num = i + 1;
            break;
        }
    }

    // If no seats are available, display an error message and return
    if (seat_num == -1) {
        printf("Sorry, all seats are booked.\n");
        return;
    }

    // Assign the ticket to the passenger
    tickets[seat_num - 1].name[0] = '\0';
    strcat(tickets[seat_num - 1].name, name);
    tickets[seat_num - 1].seat_num = seat_num;
    tickets[seat_num - 1].bus_num = bus_num;
    tickets[seat_num - 1].price = price;
    tickets[seat_num - 1].is_booked = 1;

    printf("Ticket booked successfully. Your seat number is %d.\n", seat_num);
}

// Cancels a ticket by marking it as unbooked
void cancel_ticket(struct Ticket tickets[]) {
    int seat_num;

    printf("Enter the seat number: ");
    scanf("%d", &seat_num);

    // If the seat is not booked, display an error message and return
    if (!tickets[seat_num - 1].is_booked) {
        printf("Sorry, this seat is not booked.\n");
        return;
    }

        // Mark the ticket as unbooked
    tickets[seat_num - 1].name[0] = '\0';
    tickets[seat_num - 1].bus_num = 0;
    tickets[seat_num - 1].price = 0.0;
    tickets[seat_num - 1].is_booked = 0;

    printf("Ticket with seat number %d cancelled successfully.\n", seat_num);
}

// Displays all the booked tickets
void display_tickets(struct Ticket tickets[]) {
    printf("Seat No.  Name                   Bus No.  Price\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < MAX_TICKETS; i++) {
        if (tickets[i].is_booked) {
            printf("%-8d %-22s %-8d $%.2f\n", tickets[i].seat_num, tickets[i].name, tickets[i].bus_num, tickets[i].price);
        }
    }
}

int main() {
    struct Ticket tickets[MAX_TICKETS];
    int choice;

    init_tickets(tickets);

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                book_ticket(tickets);
                break;
            case 2:
                cancel_ticket(tickets);
                break;
            case 3:
                display_tickets(tickets);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}