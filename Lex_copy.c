#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include <string.h>

#define Max 300

// Define a structure for the List

void printArrayInOrder(FILE *outputFile, char **array, int n);
int compareStrings(const void *a, const void *b);

int main(int argc, char *argv[]) {
  // Check the number of command line arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
    return 1;
  }

  // Open input file
  FILE *inputFile = fopen(argv[1], "r");
  if (inputFile == NULL) {
    fprintf(stderr, "Error opening input file");
    return 1;
  }

  // Count the number of lines in the input file
  int n = 0;
  char buffer[Max];
  while (fgets(buffer, Max, inputFile) != NULL) {
    n++;
  }

  // Allocate memory for the string array
  char **array = (char **)calloc(n, sizeof(char *));

  // Read lines from the input file and store them in the array
  for (int i = 0; i < n; i++) {
    array[i] = (char *)calloc(Max, sizeof(char));
  }

  // Rewind the input file to the beginning
  rewind(inputFile);

  // Read lines and store them in the array
  for (int i = 0; i < n; i++) {
    fgets(buffer, Max, inputFile);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
    strcpy(array[i], buffer);
  }

  // Sort the array in reverse alphabetical order
  qsort(array, n, sizeof(char *), compareStrings);

  // Open output file
  FILE *outputFile = fopen(argv[2], "w");
  if (outputFile == NULL) {
    fprintf(stderr, "Error opening output file");
    return 1;
  }

  // Print the sorted array to the output file
  printArrayInOrder(outputFile, array, n);

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);

  // Free allocated memory
  for (int i = 0; i < n; i++) {
    free(array[i]);
  }
  free(array);

  return 0;
}

// Comparison function for qsort (reverse alphabetical order)
int compareStrings(const void *a, const void *b) {
  return strcmp(*(const char **)b, *(const char **)a);
}

// Print the array to the output file
void printArrayInOrder(FILE *outputFile, char **array, int n) {
  for (int i = 0; i < n; i++) {
    fprintf(outputFile, "%s\n", array[i]);
  }
}
