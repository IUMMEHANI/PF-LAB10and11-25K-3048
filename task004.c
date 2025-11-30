#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char genre[15];
    char director[20];
    int release_year;
    float rating;
} Movie;
Movie m[10];   
int movieCount = 6;   
void addmovie() {
    if (movieCount >= 10) {
        printf("Cannot add more movies. Theatre database is full.\n");
        return;
    }
    printf("\nEnter movie details:\n");
    getchar(); 
    printf("Enter movie name: ");
    fgets(m[movieCount].name, 20, stdin);
    m[movieCount].name[strcspn(m[movieCount].name, "\n")] = '\0';
    printf("Enter genre: ");
    fgets(m[movieCount].genre, 15, stdin);
    m[movieCount].genre[strcspn(m[movieCount].genre, "\n")] = '\0';
    printf("Enter director name: ");
    fgets(m[movieCount].director, 20, stdin);
    m[movieCount].director[strcspn(m[movieCount].director, "\n")] = '\0';
    printf("Enter release year: ");
    scanf("%d", &m[movieCount].release_year);
    printf("Enter rating: ");
    scanf("%f", &m[movieCount].rating);
    movieCount++;
    printf("Movie added successfully!\n\n");
}
void search() {
    char target[15];
    int found = 0;
    int i;
    printf("\nEnter genre to search: ");
    scanf("%s", target);
    for (i = 0; i < movieCount; i++) {
        if (strcmp(target, m[i].genre) == 0) {
            printf("\n--- Movie Found ---\n");
            printf("Name: %s\n", m[i].name);
            printf("Genre: %s\n", m[i].genre);
            printf("Director: %s\n", m[i].director);
            printf("Release Year: %d\n", m[i].release_year);
            printf("Rating: %.2f\n", m[i].rating);
            found = 1;
        }
    }
    if (!found)
        printf("No movie found with this genre.\n\n");
}
void allmovies() {
	int i;
    printf("\n-------- ALL MOVIES --------\n\n");
    for ( i = 0; i < movieCount; i++) {
        printf("Movie #%d\n", i + 1);
        printf("Name: %s\n", m[i].name);
        printf("Genre: %s\n", m[i].genre);
        printf("Director: %s\n", m[i].director);
        printf("Release Year: %d\n", m[i].release_year);
        printf("Rating: %.2f\n\n", m[i].rating);
    }
}
int main() {
    strcpy(m[0].name, "Inception");
    strcpy(m[0].genre, "Sci-Fi");
    strcpy(m[0].director, "Nolan");
    m[0].release_year = 2010;
    m[0].rating = 8.8;
    strcpy(m[1].name, "The Conjuring");
    strcpy(m[1].genre, "Horror");
    strcpy(m[1].director, "James Wan");
    m[1].release_year = 2013;
    m[1].rating = 7.5;
    strcpy(m[2].name, "La La Land");
    strcpy(m[2].genre, "Musical");
    strcpy(m[2].director, "Damien");
    m[2].release_year = 2016;
    m[2].rating = 8.0;
    strcpy(m[3].name, "Endgame");
    strcpy(m[3].genre, "Action");
    strcpy(m[3].director, "Russo");
    m[3].release_year = 2019;
    m[3].rating = 8.4;
    strcpy(m[4].name, "Titanic");
    strcpy(m[4].genre, "Romance");
    strcpy(m[4].director, "Cameron");
    m[4].release_year = 1997;
    m[4].rating = 7.8;
    strcpy(m[5].name, "Godfather");
    strcpy(m[5].genre, "Crime");
    strcpy(m[5].director, "Coppola");
    m[5].release_year = 1972;
    m[5].rating = 9.2;
    int choice = 0;
    do {
        printf("\n----- MOVIE DATABASE -----\n");
        printf("1. Add Movie\n");
        printf("2. Search by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addmovie(); break;
            case 2: search(); break;
            case 3: allmovies(); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 4);
    return 0;
}

