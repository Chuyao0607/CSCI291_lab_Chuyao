#include <stdio.h>
#include <stdbool.h>  // Include standard input/output and boolean library

// Function prototypes
bool isValid(const int arr[], int length, int pos);  // Check if the position is valid
void remove_element(int arr[], int *length, int pos);  // Remove element from the array at position
void insert_element(int arr[], int *length, int pos, int value);  // Insert element at the given position

int main() {
    int arr[5] = {10, 20, 30, 40, 50};  // Initialize array with 5 values, and extra space
    int length = 5;  // Length of the array is initially 5
   
    // Modify array to {10, 10, 20, 40, 50}
    remove_element(arr, &length, 2);  // Remove element at index 2 (value 30)
    insert_element(arr, &length, 1, 10);  // Insert element 10 at index 1

    // Display the modified array
    printf("Array after first modification: ");
    for (int i = 0; i < length; i++) {  // Loop to print each element in the modified array
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Re-initialize the array back to {10, 20, 30, 40, 50}
    arr[0] = 10; arr[1] = 20; arr[2] = 30; arr[3] = 40; arr[4] = 50;
    length = 5;

    // Modify array to {20, 30, 80, 40, 50}
    remove_element(arr, &length, 0);  // Remove element at index 0 (value 10)
    insert_element(arr, &length, 2, 80);  // Insert element 80 at index 2

    // Display the modified array
    printf("Array after second modification: ");
    for (int i = 0; i < length; i++) {  // Loop to print each element in the modified array
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;  // End of the main function
}

// Function to check if the position is valid
bool isValid(const int arr[], int length, int pos) {
    if(pos >= 0 && pos < length){  // Check if position is within bounds
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
    printf("\n");
}

// Function to insert a new element at a given position
void insert_element(int arr[], int *length, int pos, int value) {
    if (pos < 0 || pos > *length) {  // Check if position is valid (between 0 and length)
        printf("Error: Invalid position\n");  // Print error message if position is invalid
        return;  // Exit the function
    }

    // Shift elements to the right to create space for the new element
    for (int i = *length; i > pos; i--) {  // Loop through elements from the end
        arr[i] = arr[i - 1];  // Shift each element to the right
    }

    arr[pos] = value;  // Insert the new value at the specified position
    (*length)++;  // Increase the array length by 1
    printf("\n");
}

