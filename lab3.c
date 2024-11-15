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


