question1：
#include <stdio.h>
#include <stdlib.h>


FILE* qn;  
FILE* flt; 

int is_valid_float(const char* str) {
    char* endptr;
    strtof(str, &endptr);  
    return *endptr == '\0'; 
}


void process_file(const char* input_file, const char* output_file) {
    
    qn = fopen(input_file, "r");
    
    flt = fopen(output_file, "w");

    
    if (qn == NULL) {
        printf("Error: Unable to open input file %s.\n", input_file);
        return;
    }
    
    if (flt == NULL) {
        printf("Error: Unable to open output file %s.\n", output_file);
        fclose(qn);
        return;
    }

    char buffer[256];  
    int invalid_count = 0;  
    
    
    while (fscanf(qn, "%s", buffer) != EOF) {
        if (is_valid_float(buffer)) {
            fprintf(flt, "%s\n", buffer);  
        } else {
            invalid_count++;  
            printf("Invalid float value: %s\n", buffer);  
        }
    }

    
    printf("Number of invalid float values: %d\n", invalid_count);

   
    fclose(qn);
    fclose(flt);
}

int main() {
    const char* input_file = "question1text.txt";   
    const char* output_file = "float.txt";  

    process_file(input_file, output_file);  
    
    return 0;
}
question3：
#include <iostream>
#include <iomanip>  // for std::setw, std::fixed, std::setprecision
using namespace std;

// Template function for printing a number in fixed-point format with specified field width and precision
template <typename T>
void print_real(T number, int fieldspace, int precision) {
    cout << setw(fieldspace)      // Set the field width
         << fixed                 // Use fixed-point notation
         << setprecision(precision)  // Set the number of decimal places
         << number
         << endl;  // Print the number with a newline
}

// Template function to update the values of m1 and m2
template <typename T>
void update_scale(T& m1, T& m2, T m3 = 10) {
    T original_m1 = m1;
    T original_m2 = m2;
    m1 = (original_m1 + original_m2) * m3;  // Update m1
    m2 = (original_m1 - original_m2) * m3;  // Update m2
}

int main() {
    float m1, m2;

    // Get input values for m1 and m2
    cout << "Enter your m1 value: ";
    cin >> m1;
    cout << "Enter your m2 value: ";
    cin >> m2;

    float number = 123.45678;
    int fieldspace = 10;
    int precision = 3;
    float m3 = 10;

    // Print the number in fixed-point notation
    print_real(number, fieldspace, precision);

    // Print m1 and m2 before the update
    cout << "Before update_scale:" << endl;
    cout << "m1 = " << m1 << ", m2 = " << m2 << endl;

    // Update m1 and m2 using the update_scale function
    update_scale(m1, m2, m3);

    // Print m1 and m2 after the update
    cout << "After update_scale:" << endl;
    cout << "m1 = " << m1 << ", m2 = " << m2 << endl;

    return 0;
}
