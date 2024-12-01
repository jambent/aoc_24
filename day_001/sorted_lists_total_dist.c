#include <stdio.h>
#include <stdlib.h>

// Read test input text file using command line argument,
// e.g., ./day_001/sorted_lists_total_dist ./day_001/day_1_input.txt
int main (int argc, char *argv[]) {

    FILE *fp;
    int end_of_file_check;
    int line_count = 1;

    fp = fopen(argv[1], "r");

    if (argc != 2) {
        printf("%s not called with single filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Count number of lines in file
    while ((end_of_file_check = getc(fp))!= EOF) {
        if (end_of_file_check == '\n') {
            line_count++;
        }
    }

    // Create two arrays to store the two lists, and populate them after rewinding file pointer
    int list_one_array[line_count], list_two_array[line_count];
    int array_population_index = 0;

    rewind(fp);

    while ((end_of_file_check = getc(fp))!= EOF) {
        fscanf(fp, "%d %d", &list_one_array[array_population_index], &list_two_array[array_population_index]);
        array_population_index++;
    }

    printf("Last array elements: %d %d\n", list_one_array[line_count-1], list_two_array[line_count-1]);

    fclose(fp);
    
    return 0;
}