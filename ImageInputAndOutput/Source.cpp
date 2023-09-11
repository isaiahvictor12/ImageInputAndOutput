#include <stdio.h>
#include <iostream>

int main() {
    // Define the input and output file paths
    const char* inputFilePath = "unesco750-1.raw";
    const char* outputRawFilePath1 = "reverseIntensity.raw";
    const char* outputRawFilePath2 = "add20.raw";
    const char* outputRawFilePath3 = "add100.raw";


    // Open the input raw image file
    FILE* inputFile;
    if (fopen_s(&inputFile, inputFilePath, "rb") != 0) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Define image dimensions (adjust these according to your image)
    int height = 500;
    int width = 750;

    unsigned char image[500][750];
    fread(image, 1, height * width, inputFile);

    fclose(inputFile);

    unsigned char newImage[500][750];

    // Reverse intensity
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            newImage[y][x] = (unsigned char)255 - image[y][x];
        }
    }

    FILE* outputFile1;
    if (fopen_s(&outputFile1, outputRawFilePath1, "wb") != 0) {
        printf("Error: Unable to open output raw file.\n");
        return 1;
    }
    // Write the modified image data to the output raw file
    fwrite(newImage, 1, height * width, outputFile1);
    fclose(outputFile1);
    
    // Add 20
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            newImage[y][x] = image[y][x] + (unsigned char)20;
            if (newImage[y][x] > 255) {
                newImage[y][x] = 255;
            }
        }
    }
    FILE* outputFile2;
    if (fopen_s(&outputFile2, outputRawFilePath2, "wb") != 0) {
        printf("Error: Unable to open output raw file.\n");
        return 1;
    }
    // Write the modified image data to the output raw file
    fwrite(newImage, 1, height * width, outputFile2);
    fclose(outputFile2);

    // Add 100
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            newImage[y][x] = image[y][x] + (unsigned char)100;
            if (newImage[y][x] > 255) {
                newImage[y][x] = 255;
            }
        }
    }
    FILE* outputFile3;
    if (fopen_s(&outputFile3, outputRawFilePath3, "wb") != 0) {
        printf("Error: Unable to open output raw file.\n");
        return 1;
    }
    // Write the modified image data to the output raw file
    fwrite(newImage, 1, height * width, outputFile3);
    fclose(outputFile3);


    printf("Image processing and saving to a raw file complete.\n");

    return 0;
}
