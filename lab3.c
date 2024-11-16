#include <stdio.h>
#include <stdbool.h>

#define SIZE 6 // Maximum array size for 1D array

// Function prototypes
bool isValid(const int arr[], int length, int pos);  // Check if the position is valid
void remove_element(int arr[], int *length, int pos);  // Remove element from the array at position
void insert_element(int arr[], int *length, int pos, int value);  // Insert element at the given position
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]);
void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat_transp[nCols][nRows]);
bool found_duplicate(int arr[], int length);
int main() {
    int arr[SIZE] = {10, 20, 30, 40, 50, 60};  // Initialize array with 5 values, and extra space
    int length = SIZE;  // Length of the array is initially 5

    // Modify array to {10, 10, 20, 40, 50,60}
    remove_element(arr, &length, 2);  // Remove element at index 2 (value 30)
    insert_element(arr, &length, 1, 10);  // Insert element 10 at index 1

    // Display the modified array
    printf("Array after first modification: ");
    for (int i = 0; i < length; i++) {  // Loop to print each element in the modified array
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Re-initialize the array back to {10, 20, 30, 40, 50}
    arr[0] = 10; arr[1] = 20; arr[2] = 30; arr[3] = 40; arr[4] = 50; arr[5] = 60;
    length = 6;

    // Modify array to {20, 30, 80, 40, 50}
    remove_element(arr, &length, 0);  // Remove element at index 0 (value 10)
    insert_element(arr, &length, 2, 80);  // Insert element 80 at index 2

    // Display the modified array
    printf("Array after second modification: ");
    for (int i = 0; i < length; i++) {  // Loop to print each element in the modified array
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Set the dimensions for the 2D array
    int nRows = 2;
    int nCols = 3;
    int arr2d[nRows][nCols];

    // Fill arr2d with the data 20 80 50 in the first row, 30 40 60 in the second row
    arr2d[0][0] = 20; arr2d[0][1] = 80; arr2d[0][2] = 50;
    arr2d[1][0] = 30; arr2d[1][1] = 40; arr2d[1][2] = 60;

    // Display the 2D array
    printf("2D array after reshaping:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }

    int mat_transp[nCols][nRows];
    trans_matrix(nRows, nCols, arr2d, mat_transp);

    if (found_duplicate(arr, length)) {
        printf("There is at least one duplicate value in the array.\n");
    } else {
        printf("No duplicates found in the array.\n");
    }
    return 0;  // End of the main function
}

// Function to check if the position is valid
bool isValid(const int arr[], int length, int pos) {
    if (pos >= 0 && pos < length) {  // Check if position is within bounds
        return true;  // Position is valid
    }
    return false;  // Position is invalid
}

// Function to remove an element at a given position
void remove_element(int arr[], int *length, int pos) {
    if (!isValid(arr, *length, pos)) {  // Check if position is valid
        printf("Error: Invalid position\n");  // Print error message if position is invalid
        return;  // Exit the function
    }

    // Shift elements left to fill the gap
    for (int i = pos; i < *length - 1; i++) {  // Loop through elements from position
        arr[i] = arr[i + 1];  // Shift each element to the left to fill the deleted element
    }
    (*length)--;  // Decrease the array length by 1
}

// Function to insert a new element at a given position
void insert_element(int arr[], int *length, int pos, int value) {
    if (!isValid(arr, *length + 1, pos)) {  // Check if position is valid for insertion
        printf("Error: Invalid position\n");  // Print error message if position is invalid
        return;  // Exit the function
    }

    // Shift elements to the right to create space for the new element
    for (int i = *length; i > pos; i--) {  // Loop through elements from the end
        arr[i] = arr[i - 1];  // Shift each element to the right
    }

    arr[pos] = value;  // Insert the new value at the specified position
    (*length)++;  // Increase the array length by 1
}

// Function to reshape a 1D array into a 2D array
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[][nCols]) {
    // Check if the 1D array length matches the 2D array dimensions
    if (length != nRows * nCols) {
        puts("Error: Array size does not match the specified dimensions.");
        return;
    }

    // Fill arr2d column by column
    int index = 0;
    for (int j = 0; j < nCols; j++) {      // Iterate over columns first
        for (int i = 0; i < nRows; i++) {  // Then rows to fill column by column
            arr2d[i][j] = arr[index++];
        }
    }

    // Print the reshaped array for verification
    printf("Reshaped 2D array:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }
}

void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat_transp[nCols][nRows]) {
    // Transpose the matrix
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            mat_transp[j][i] = mat[i][j];  // Transpose element by switching row and column indices
        }
    }
    
    // Print the transposed matrix (for verification)
    printf("Transposed Matrix:\n");
    for (int i = 0; i < nCols; i++) {
        for (int j = 0; j < nRows; j++) {
            printf("%d ", mat_transp[i][j]);
        }
        printf("\n");
    }
}
bool found_duplicate(int arr[], int length) {
    // Iterate through each element in the array
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {  // If a duplicate is found
                return true;  // Return true if duplicate is found
            }
        }
    }
    return false;  // Return false if no duplicates were found
}

question 2
#include <stdio.h>
#define SIZE 8

int initial_balance = 100;

void withdraw(int tob[], int transaction[], int size);

int main() {
    int transaction[SIZE] = {-5000, 2000, 1000, -400, -50, -200, 300, 0};  
    int tob[SIZE] = {0};  
    withdraw(tob, transaction, SIZE);
    return 0;
}

void withdraw(int tob[], int transaction[], int size) {
    printf("Transactions to be processed:\n");

  
    for (int i = 0; i < size; i++) {
        printf("Transaction of %d: ", transaction[i]);

        if ((initial_balance + transaction[i]) < 0) {
            printf("Invalid! Transaction would cause overdraft.\n");
            tob[i] = transaction[i];  // Store the invalid transaction
        } else {
            initial_balance += transaction[i];
            printf("Processed. New balance: %d\n", initial_balance);
        }
    }

   
    printf("\nInvalid transactions:\n");
    for (int i = 0; i < size; i++) {
        if (tob[i] != 0) {
            printf("Transaction of %d was invalid.\n", tob[i]);
        }
    }
}

question3
#include<stdio.h>
#define SQUAD_SIZE 30
#define NUM_TEAMS 7
void display_menu();
void enroll_club(player_t r1,char club_name);
void add_player(player_t r1 ,age_t,int name,int kit_number,int age,char position,int  year,int month,int day);
void search_update();
void display_club_statistics();
void handle_error(); 

typedef struct 
{
    char name;
    int kit_number;
    char club_name;
    char position;
}player_t; 
player_t r1;

typedef struct{
        int year;
        int month;
        int day;
    }age_t;
age_t r1;


    
int main(void){
    display_menu(); 
   
    return 0;
}
void display_menu(){
    int option;
    printf("1.enroll club 2.add player 3.seaech update 4.display club statistics 5.hanedle error\n");
    printf("enter your option: ");
    scanf("%d",&option);
    switch(option){
        case 1:
        void enroll_club(player_t r1,char club_name);
        break;
        case 2:
        void add_player(player_t r1,age_t r1,int name,int kit_number,int age,char position,int year, int month,int day);
        break;
        case 3:
        void search_update();
        break;
        case 4:
        void display_club_statistics();
        break;
        case 5:
        void handle_error(); 
        break;
        default:
        puts("you enter a wrong digit!")
        continue;
    }
}
void enroll_club(player_t r1,char club_name){
    char club_name;
    printf("enter your club name: ");
    scanf("%7s",&club_name);
    r1.club_name;
    printf("the club is %7s\n",club_name);
    
}
void add_player(player_t r1,age_t r1,int name,int kit_number,int age,char position,int year,int month,int day){
    puts("enrro_club(player_t r1)");
    char name;
    printf("enter player's name: ");
    scanf("%s",&name);
    r1.name;
    int kit_number;
    printf("enter player's kit number: ");
    scanf("%d",&kit_number);
    r1.kit_number;
    printf("enter player's birthday(year month day)> ");
    int year,month,day;
    scanf("%d%d%d",&year,&month,&day);
    r1.year;
    r1.month;
    r1.day;
    char position;
    printf("enter player's position: ");
    scanf("%s",&position);
    r1.position;
    printf("the player' name:%s kit number:%d birthday:%d/%d/%d the position:%s ",name,kit_number,year,month,day,position);
    

    


}
void search_update(){
    
}
void display_club_statistics(){
    
}

void handle_error(){
    
}
question 3
#include <stdio.h>
#include <string.h>

#define SQUAD_SIZE 30
#define NUM_TEAMS 7

typedef struct {
    char name[25];
    int kit_number;
    char club_name[20];
    char position[20];
    struct {
        int year;
        int month;
        int day;
    } age;
} player_t;

typedef struct {
    char team_name[20];
    player_t players[SQUAD_SIZE];
    int player_count;
} team_t;

team_t tm[NUM_TEAMS];
int team_count = 0;

void display_menu();
void enroll_club();
void add_player();
void search_update();
void display_club_statistics();
void handle_error(const char *message);

int main(void) {
    while (1) {
        display_menu();
        int option;
       
        scanf("%d", &option);

        switch (option) {
            case 1:
                enroll_club();
                break;
            case 2:
                add_player();
                break;
            case 3:
                search_update();
                break;
            case 4:
                display_club_statistics();
                break;
            case 5:
                handle_error("An error occurred.");
                break;
            default:
                puts("Invalid input. Program will terminate.");
                return 0;
        }
    }
    return 0;
}

void display_menu() {
    printf("1. Enroll club\n");
    printf("2. Add player\n");
    printf("3. Search and update attributes\n");
    printf("4. Display club statistics\n");
    printf("5. Exit\n");
    printf("Enter your option: ");
}

void enroll_club() {
    if (team_count >= NUM_TEAMS) {
        handle_error("Maximum number of clubs reached!");
        return;
    }
    printf("Enter club name: ");
    scanf(" %[^\n]", tm[team_count].team_name);
    tm[team_count].player_count = 0;
    team_count++;
    printf("Club enrolled successfully!\n");
}

void add_player() {
    int option;
    printf("Enter a team (1-%d): ", team_count);
    scanf("%d", &option);
    if (option < 1 || option > team_count) {
        handle_error("Invalid team number.");
        return;
    }

    team_t *selected_team = &tm[option - 1];
    player_t new_player;
    printf("Enter your name: ");
    scanf(" %[^\n]", new_player.name);
    printf("Enter your kit number: ");
    scanf("%d", &new_player.kit_number);
    printf("Enter your birthday (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &new_player.age.day, &new_player.age.month, &new_player.age.year);
    
    printf("Enter your position: ");
    scanf(" %[^\n]", new_player.position);

    // Check for duplicates
    for (int i = 0; i < selected_team->player_count; i++) {
        if (strcmp(selected_team->players[i].name, new_player.name) == 0 ||
            selected_team->players[i].kit_number == new_player.kit_number) {
            handle_error("Duplicate player name or kit number found!");
            return;
        }
    }
    selected_team->players[selected_team->player_count++] = new_player;
    printf("Player added successfully!\n");
}

void search_update() {
    int method;
    printf("Please choose a method to search (1. Name / 2. Kit number): ");
    scanf("%d", &method);
    switch (method) {
        case 1: {
            char entered_name[25];
            printf("Enter name: ");
            scanf(" %[^\n]", entered_name);
            int found = 0;
            for (int i = 0; i < team_count; i++) {
                for (int j = 0; j < tm[i].player_count; j++) {
                    if (strcmp(tm[i].players[j].name, entered_name) == 0) {
                        printf("Player found: %s\n", tm[i].players[j].name);
                        printf("Enter new club: ");
                        scanf(" %[^\n]", tm[i].players[j].club_name);
                        printf("Enter new kit number: ");
                        scanf("%d", &tm[i].players[j].kit_number);
                        printf("Enter new position: ");
                        scanf(" %[^\n]", tm[i].players[j].position);
                        printf("Enter new birthday (DD/MM/YYYY): ");
                        scanf("%d/%d/%d", &tm[i].players[j].age.day, &tm[i].players[j].age.month, &tm[i].players[j].age.year);
                        printf("Player updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
            if (!found) {
                printf("Player not found.\n");
            }
            break;
        }
        case 2: {
            int entered_kit_number;
            printf("Enter kit number: ");
            scanf("%d", &entered_kit_number);
            int found = 0;
            for (int i = 0; i < team_count; i++) {
                for (int j = 0; j < tm[i].player_count; j++) {
                    if (tm[i].players[j].kit_number == entered_kit_number) {
                        printf("Player found: %s\n", tm[i].players[j].name);
                        printf("Enter new club: ");
                        scanf(" %[^\n]", tm[i].players[j].club_name);
                        printf("Enter new name: ");
                        scanf(" %[^\n]", tm[i].players[j].name);
                        printf("Enter new position: ");
                        scanf(" %[^\n]", tm[i].players[j].position);
                        printf("Enter new birthday (DD/MM/YYYY): ");
                        scanf("%d/%d/%d", &tm[i].players[j].age.day, &tm[i].players[j].age.month, &tm[i].players[j].age.year);
                        printf("Player updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
            if (!found) {
                printf("Player not found.\n");
            }
            break;
        }
        default:
            printf("Invalid option. Try again.\n");
            break;
    }
}

void display_club_statistics() {
    for (int i = 0; i < team_count; i++) {
        printf("Team: %s\n", tm[i].team_name);
        for (int j = 0; j < tm[i].player_count; j++) {
            printf("Name: %s, Kit Number: %d, Position: %s, Birthday: %d/%d/%d\n",
                   tm[i].players[j].name, tm[i].players[j].kit_number, tm[i].players[j].position,
                   tm[i].players[j].age.day, tm[i].players[j].age.month, tm[i].players[j].age.year);
        }
    }
}

void handle_error(const char *message) {
    printf("Error: %s\n", message);
}
