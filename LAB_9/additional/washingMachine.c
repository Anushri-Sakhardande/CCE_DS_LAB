#include <stdio.h>
#include <stdlib.h>

typedef struct User {
    int userId;
    int bookingTime;
    struct User* prev;
    struct User* next;
}User;

User* queue = NULL;
int currentTime = 0;
int userIdCounter = 1;

// Function to create a new user 
User* createUser(int bookingTime) {
    User* user = (User*)malloc(sizeof(User));
    user->userId = userIdCounter++;
    user->bookingTime = bookingTime;
    user->prev = user->next = user;
    return user;
}

// Function to book a washing machine
void bookMachine(int bookingTime) {
    User* user = createUser(bookingTime);
    if (queue == NULL) {
        queue = user;
    } else {
        user->next = queue;
        user->prev = queue->prev;
        queue->prev->next = user;
        queue->prev = user;
    }
    printf("User %d booked the machine for %d minutes.\n", user->userId, bookingTime);
}

// Function to advance time and release the machine when booking time is up
void advanceTime() {
    if (queue == NULL) {
        printf("No users in the queue.\n");
        return;
    }

    currentTime++;
    if (queue->bookingTime == currentTime) {
        User* user = queue;
        queue = user->next;
        user->next->prev = user->prev;
        user->prev->next = user->next;
        printf("User %d finished and returned the machine.\n", user->userId);
        free(user);
    }
}

// Function to display the queue
void displayQueue() {
    if (queue == NULL) {
        printf("Queue is empty.\n");
    } else {
        User* current = queue;
        do {
            printf("User %d (%d minutes) -> ", current->userId, current->bookingTime);
            current = current->next;
        } while (current != queue);
        printf("\n");
    }
}

int main() {
    int choice, bookingTime;

    while (1) {
        printf("\nWashing Machine Rental System:\n");
        printf("1. Book a machine\n");
        printf("2. Advance time\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter booking time (in minutes): ");
                scanf("%d", &bookingTime);
                bookMachine(bookingTime);
                break;
            case 2:
                advanceTime();
                break;
            case 3:
                displayQueue();
              break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}