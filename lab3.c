#include <stdio.h>
#include <stdbool.h>

bool isValid(const int arr[], int length, int pos);
void remove_element(int arr[], int length, int pos); 


int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int length = 5;
   
    // Display the original array
    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // "Remove" elements at index 1 and 2 by replacing them with preceding values
    remove_element(arr, length, 2);  // Replaces element at index 1 with index 0
    remove_element(arr, length, 1);  // Replaces element at index 2 with index 1
    // Display the final array
    printf("Final array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

bool isValid(const int arr[], int length, int pos) {
    if(pos >= 0 && pos < length){
        return true;
    }
    return false;

}
// Function to "remove" element by setting arr[pos] to arr[pos - 1]
void remove_element(int arr[], int length, int pos) {
   if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position\n");
        return;
    }

    // Replace arr[pos] with arr[pos - 1]
    arr[pos] = arr[pos - 1];

    // Display the array after replacement
    printf("Array after replacement at index %d: ", pos);
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

