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
a.
#include <iostream>
#include <iomanip>  // for std::setw, std::fixed, std::setprecision
using namespace std;
void print_real( float number, int fieldspace, int precision){
cout << setw(fieldspace)
              << fixed
              << setprecision(precision)
              << number
              << endl;
    
}
int main() {
    float number = 123.45678;
    int fieldspace = 10;
    int precision = 3;

    return 0;
}
