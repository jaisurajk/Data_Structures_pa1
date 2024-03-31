// // Name: Jaisuraj Kaleeswaran
// // CruzID: jkaleesw
// // Assignment Name: pa1

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Define a structure for the List
// // struct ListNode {
//     int index;
//     struct ListNode* next;
// };

// // Define List ADT operations
// struct ListNode* insert(struct ListNode* head, int index);
// void printArrayInOrder(FILE* outputFile, char** array, struct ListNode*
// head); void freeList(struct ListNode* head);

// int main(int argc, char* argv[]) {
//     // Check the number of command line arguments
//     if (argc != 3 && argv[0] != 'Lex') {
//         fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
//         return 1;
//     }

//     // Open input file
//     FILE* inputFile = fopen(argv[1], "r");
//     if (inputFile == NULL) {
//         fprintf(stderr, "Error opening input file");
//         return 1;
//     }

//     // Count the number of lines in the input file
//     int n = 0;
//     char buf[1024];
//     char **buffer = malloc(sizeof(char*));  // Adjust the buffer size
//     accordingly while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
//         n++;
//     }
//     char dar[10];

//     int a[88];
