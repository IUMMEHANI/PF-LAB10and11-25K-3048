#include <stdio.h>
#include <string.h>
typedef struct {
    char name[20];
    int age;
    char position[15];
} Player;
typedef struct {
    char name[20];
    char sport[20];
    Player players[10];  
    int playerCount;    
} Team;
void addPlayer(Team *T) {
    if (T->playerCount >= 10) {
        printf("No more players can be added.\n");
        return;
    }
    getchar(); 
    printf("Enter player name: ");
    fgets(T->players[T->playerCount].name, 20, stdin);
    T->players[T->playerCount].name[strcspn(T->players[T->playerCount].name, "\n")] = '\0';
    printf("Enter player's age: ");
    scanf("%d", &T->players[T->playerCount].age);
    getchar(); 
    printf("Enter player position: ");
    fgets(T->players[T->playerCount].position, 15, stdin);
    T->players[T->playerCount].position[strcspn(T->players[T->playerCount].position, "\n")] = '\0';
    T->playerCount++;
    printf("Player added successfully!\n");
}
void searchPlayer(Team *T) {
    char pos[15];
    int i;
    int found = 0;
    getchar(); 
    printf("Enter position to search: ");
    fgets(pos, 15, stdin);
    pos[strcspn(pos, "\n")] = '\0';
    for (i = 0; i < T->playerCount; i++) {
        if (strcmp(T->players[i].position, pos) == 0) {
            printf("\n--- Player Found ---\n");
            printf("Name: %s\n", T->players[i].name);
            printf("Age: %d\n", T->players[i].age);
            printf("Position: %s\n", T->players[i].position);
            found = 1;
        }
    }
    if (!found) {
        printf("No player found with this position.\n");
    }
}
void displayTeam(Team *T) {
	int i;
    printf("\nTeam Name: %s\n", T->name);
    printf("Sport: %s\n", T->sport);
    printf("Players (%d):\n", T->playerCount);

    for ( i = 0; i < T->playerCount; i++) {
        printf("%d. %s | Age: %d | Position: %s\n",
               i + 1,
               T->players[i].name,
               T->players[i].age,
               T->players[i].position);
    }
    printf("\n");
}
int main() {
    Team T = {
        "EAGLES",
        "Football",
        {
            {"Lionel Messi", 36, "Forward"},
            {"Cristiano Ronaldo", 38, "Forward"},
            {"Kylian Mbappe", 24, "Forward"},
            {"Sergio Ramos", 35, "Defender"},
            {"Manuel Neuer", 36, "Goalkeeper"},
            {"Kevin De Bruyne", 31, "Midfielder"}
        },
        6
    };
    int choice;
    do {
        printf("Welcome To Football World!\n");
        printf("1. Add a Player\n2. Search player by position\n3. Display team details\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addPlayer(&T);
                break;
            case 2:
                searchPlayer(&T);
                break;
            case 3:
                displayTeam(&T);
                break;
            case 4:
                printf("GOODBYE!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}

