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
question2:
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int width;
    int height;
    int maxGrayValue;
    unsigned char *pixels;
} Image;


int readPGMText(const char *filename, int *width, int *height, int *maxGrayValue, unsigned char **pixels) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }


    char format[3];
    if (fscanf(file, "%s", format) != 1 || (format[0] != 'P' || format[1] != '2')) {
        printf("Invalid PGM file format\n");
        fclose(file);
        return -1;
    }


    char c;
    while ((c = fgetc(file)) == '#') {
        while ((c = fgetc(file)) != '\n' && c != EOF);
    }

 
    fseek(file, -1, SEEK_CUR); 
    fscanf(file, "%d %d %d", width, height, maxGrayValue);

 
    *pixels = (unsigned char *)malloc((*width) * (*height) * sizeof(unsigned char));
    if (*pixels == NULL) {
        printf("Memory allocation failed for pixel data.\n");
        fclose(file);
        return -1;
    }

 
    for (int i = 0; i < *width * *height; i++) {
        fscanf(file, "%hhu", &((*pixels)[i]));
    }

    fclose(file);
    return 0;
}


int writePGMText(const char *filename, int width, int height, int maxGrayValue, unsigned char *pixels) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    fprintf(file, "P2\n");
    fprintf(file, "# Created by stego_lsb\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", maxGrayValue);


    for (int i = 0; i < width * height; i++) {
        fprintf(file, "%d ", pixels[i]);
    }

    fclose(file);
    return 0;
}


int writePGMBinary(const char *filename, int width, int height, int maxGrayValue, unsigned char *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    fprintf(file, "P5\n");
    fprintf(file, "# Created by stego_lsb\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", maxGrayValue);


    fwrite(pixels, sizeof(unsigned char), width * height, file);

    fclose(file);
    return 0;
}


void embedLSB(int width, int height, unsigned char *coverPixels, unsigned char *secretPixels, unsigned char *stegoPixels) {
    for (int i = 0; i < width * height; i++) {
       
        stegoPixels[i] = (coverPixels[i] & 0xF0) | (secretPixels[i] >> 4);
    }
}


void extractLSB(int width, int height, unsigned char *stegoPixels, unsigned char *outputPixels) {
    for (int i = 0; i < width * height; i++) {
        
        outputPixels[i] = (stegoPixels[i] & 0x0F) << 4;
    }
}

int main() {
    int width = 512, height = 512;
    int maxGrayValue;
    unsigned char *coverPixels, *secretPixels, *stegoPixels, *outputPixels;
    stegoPixels = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    outputPixels = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (readPGMText("baboon.pgm", &width, &height, &maxGrayValue, &coverPixels) != 0) {
        return -1;
    }

    if (readPGMText("farm.pgm", &width, &height, &maxGrayValue, &secretPixels) != 0) {
        return -1;
    }

    if (!stegoPixels || !outputPixels) {
        printf("Memory allocation failed for stego or output images.\n");
        return -1;
    }

  
    embedLSB(width, height, coverPixels, secretPixels, stegoPixels);
    extractLSB(width, height, stegoPixels, outputPixels);

 
    writePGMBinary("stego_image_bin.pgm", width, height, maxGrayValue, stegoPixels);
    writePGMText("extracted_secret.pgm", width, height, maxGrayValue, outputPixels);
    free(coverPixels);
    free(secretPixels);
    free(stegoPixels);
    free(outputPixels);

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
