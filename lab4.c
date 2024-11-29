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

// Function to read a PGM image in text format and determine its dimensions dynamically.
int readPGMText(const char *filename, unsigned char **pixels, int *width, int *height) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    // Use a char pointer for the format instead of an array
    char *format = (char *)malloc(3 * sizeof(char));
    if (!format) {
        printf("Memory allocation failed for format.\n");
        fclose(file);
        return -1;
    }

    if (fscanf(file, "%2s", format) != 1 || (format[0] != 'P' || format[1] != '2')) {
        printf("Invalid PGM file format\n");
        free(format);
        fclose(file);
        return -1;
    }

    // Skip comments
    char c;
    while ((c = fgetc(file)) == '#') {
        while ((c = fgetc(file)) != '\n' && c != EOF);
    }
    fseek(file, -1, SEEK_CUR);

    // Read image dimensions
    if (fscanf(file, "%d %d", width, height) != 2) {
        printf("Failed to read image dimensions\n");
        free(format);
        fclose(file);
        return -1;
    }

    int maxGrayValue;
    if (fscanf(file, "%d", &maxGrayValue) != 1 || maxGrayValue != 255) {
        printf("Invalid or unsupported max gray value\n");
        free(format);
        fclose(file);
        return -1;
    }

    // Allocate memory for pixels
    *pixels = (unsigned char *)malloc((*width) * (*height) * sizeof(unsigned char));
    if (!*pixels) {
        printf("Memory allocation failed for pixels.\n");
        free(format);
        fclose(file);
        return -1;
    }

    // Read pixel data
    unsigned char *ptr = *pixels;
    for (int i = 0; i < (*width) * (*height); i++, ptr++) {
        int pixelValue;
        if (fscanf(file, "%d", &pixelValue) != 1) {
            printf("Error reading pixel data\n");
            free(*pixels);
            free(format);
            fclose(file);
            return -1;
        }
        *ptr = (unsigned char)pixelValue;
    }

    free(format);
    fclose(file);
    return 0;
}

// Function to write a PGM image in text format.
int writePGMText(const char *filename, unsigned char *pixels, int width, int height) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    fprintf(file, "P2\n");
    fprintf(file, "# Created by embedLSB\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n");

    unsigned char *ptr = pixels;
    for (int i = 0; i < width * height; i++, ptr++) {
        fprintf(file, "%d ", *ptr);
        if ((i + 1) % width == 0) fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}

// Function to write a PGM image in binary format.
int writePGMBinary(const char *filename, unsigned char *pixels, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    fprintf(file, "P5\n");
    fprintf(file, "# Created by embedLSB\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "255\n");

    fwrite(pixels, sizeof(unsigned char), width * height, file);

    fclose(file);
    return 0;
}

// Function to hide a secret image using the 4-bit LSB steganography algorithm.
void embedLSB(unsigned char *coverPixels, unsigned char *secretPixels, int width, int height) {
    unsigned char *coverPtr = coverPixels;
    unsigned char *secretPtr = secretPixels;
    for (int i = 0; i < width * height; i++, coverPtr++, secretPtr++) {
        *coverPtr = (*coverPtr & 0xF0) | (*secretPtr >> 4);
    }
}

// Function to extract the secret image using 4-bit LSB steganography algorithm.
void extractLSB(unsigned char *coverPixels, unsigned char *outputPixels, int width, int height) {
    unsigned char *coverPtr = coverPixels;
    unsigned char *outputPtr = outputPixels;
    for (int i = 0; i < width * height; i++, coverPtr++, outputPtr++) {
        *outputPtr = (*coverPtr & 0x0F) << 4;
    }
}

int main() {
    char cover_image[] = "baboon.pgm";
    char secret_image[] = "farm.pgm";
    char stego_image[] = "stego_image_bin.pgm";
    char extracted_secret[] = "extracted_secret.pgm";

    unsigned char *coverPixels, *secretPixels, *outputPixels;
    int coverWidth, coverHeight, secretWidth, secretHeight;

    // Read the cover image file
    if (readPGMText(cover_image, &coverPixels, &coverWidth, &coverHeight) != 0) {
        return -1;
    }

    // Read the secret image file
    if (readPGMText(secret_image, &secretPixels, &secretWidth, &secretHeight) != 0) {
        free(coverPixels);
        return -1;
    }

    // Check if dimensions match
    if (coverWidth != secretWidth || coverHeight != secretHeight) {
        printf("Image dimensions do not match!\n");
        free(coverPixels);
        free(secretPixels);
        return -1;
    }

    // Embed the secret image into the cover image
    embedLSB(coverPixels, secretPixels, coverWidth, coverHeight);

    // Save the stego image in binary format
    if (writePGMBinary(stego_image, coverPixels, coverWidth, coverHeight) != 0) {
        free(coverPixels);
        free(secretPixels);
        return -1;
    }

    // Allocate memory for the extracted secret image
    outputPixels = (unsigned char *)malloc(secretWidth * secretHeight * sizeof(unsigned char));
    if (!outputPixels) {
        printf("Memory allocation failed for outputPixels.\n");
        free(coverPixels);
        free(secretPixels);
        return -1;
    }

    // Extract the secret image from the stego image
    extractLSB(coverPixels, outputPixels, coverWidth, coverHeight);

    // Save the extracted secret image in text format
    if (writePGMText(extracted_secret, outputPixels, secretWidth, secretHeight) != 0) {
        free(coverPixels);
        free(secretPixels);
        free(outputPixels);
        return -1;
    }

    // Free allocated memory
    free(coverPixels);
    free(secretPixels);
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
