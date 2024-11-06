#include <stdio.h>
#include <stdbool.h>  // Include standard input/output and boolean library

// Function prototypes
bool isValid(const int arr[], int length, int pos);  // Check if the position is valid
void remove_element(int arr[], int *length, int pos);  // Remove element from the array at position
void insert_element(int arr[], int *length, int pos, int value);  // Insert element at the given position

int main() {
    int arr[10] = {10, 20, 30, 40, 50};  // Initialize array with 5 values, and extra space
    int length = 5;  // Length of the array is initially 5
   
    // show original array
    printf("Original array: ");  // Print the original array
    for (int i = 0; i < length; i++) {  // Loop to print each element in the array
        printf("%d ", arr[i]);
    }
    printf("\n");

    // delate elements
    remove_element(arr, &length, 2);  // delate element of index2 in array
    remove_element(arr, &length, 1);  // delate element of index1 in array

    //Display the deleted array
    printf("Array after deletion: ");  // Print array after deletion
    for (int i = 0; i < length; i++) {  // Loop to print each element in the modified array
        printf("%d ", arr[i]);
    }
    printf("\n");

    // insert new elements
    insert_element(arr, &length, 0, 20);  // insert element 20 in index 0
    insert_element(arr, &length, 1, 30);  // insert element 30 in index 1
    insert_element(arr, &length, 2, 80);  // insert element 80 in index 2

     
// Display the inserted array
    printf("Array after insertion: ");  // Print array after insertion
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
        arr[i] = arr[i + 1];  // Shift each element to the left
    }

    (*length)--;  // Decrease the array length by 1

    printf("Array after removal at index %d: ", pos);  // Print the array after removal
    for (int i = 0; i < *length; i++) {  // Loop to print the modified array
        printf("%d ", arr[i]);
    }
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

    printf("Array after insertion at index %d: ", pos);  // Print the array after insertion
    for (int i = 0; i < *length; i++) {  // Loop to print the modified array
        printf("%d ", arr[i]);
    }
    printf("\n");
}

