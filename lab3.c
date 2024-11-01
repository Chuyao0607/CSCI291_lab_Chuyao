#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 24
#define nRows 8
#define nCols 3

bool isValid(const int arr[], int length, int pos);
void remove_element(int arr[], int length, int pos); 
void insert_element(int arr[], int length, int pos, int value);

bool isValid(const int arr[], int length, int pos) {
    if(pos >= 0 && pos < length){
        return true;
    }
    return false;

}

void remove_element(int arr[], int length, int pos) { 
    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position\n");
        return;
    }
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
}
void insert_element(int arr[], int length, int pos, int value){
   if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position\n");
        return;
    } 
    for(int i=pos; i< length +1;i++){
        arr[i]=arr[i + 1];
    }

}
int main() {
    int arr[SIZE] = {0}; 
    int length = sizeof(arr) / sizeof(arr[0]);
    int pos; 
    
    printf("Enter a number for pos: ");
    scanf("%d", &pos);

    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position\n");
        return 1;
    }
    void remove_element(int arr[], int length, int pos); 
    void insert_element(int arr[], int length, int pos, int value);
    for(int i=0;i<length;i++){
    int arr[i];
    printf("\n");
}
    return 0;
}
