#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[userCount].username);

    printf("Enter password: ");
    scanf("%s", users[userCount].password);

    userCount++;
    printf("User registered successfully.\n");
}

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful.\n");
            return 1;  
        }
    }

    printf("Invalid username or password. Please try again.\n");
    return 0;  
}

int main() {
    int choice;

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
