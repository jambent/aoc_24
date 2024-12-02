#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main (int argc, char *argv[]) {

    FILE *fp;
    char *line;
    line = calloc(256,sizeof(char));

    
    int good_report_count = 0;


    fp = fopen(argv[1], "r");

    if (argc != 2) {
        printf("%s not called with single filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }


    while ((fgets(line, 256, fp))!= NULL) {
        
        long int *line_number_array;
        line_number_array = calloc(256,sizeof(long int));

        line[strcspn(line, "\n")] = '\0';
  
        char *endptr;
        long int num;
        int token_count = 0;
        char *token = strtok(line, " ");


        while (token != NULL) {
            num = strtol(token, &endptr, 10);
            line_number_array[token_count] = num;
            token_count++;
            token = strtok(NULL, " ");
        }
       
        int report_good = 1;
        
        if (token_count < 2) {
            report_good = 0;
        }
        else if ((line_number_array[1] - line_number_array[0]) > 0){
            
            for (int i = 1; i < token_count; i++) {
                if (((line_number_array[i] - line_number_array[i-1]) <= 0) || ((line_number_array[i] - line_number_array[i-1]) > 3)) {
                    report_good = 0;
                    break;
                }
            }
        
        }
        else if ((line_number_array[1] - line_number_array[0]) < 0){
            for (int i = 1; i < token_count; i++) {
                if (((line_number_array[i] - line_number_array[i-1]) >= 0) || (abs(line_number_array[i] - line_number_array[i-1]) > 3))
                {
                    report_good = 0;
                    break;
                }
            }
        }
        else {
            report_good = 0;
        }

        good_report_count += report_good;

        free(line_number_array);
        

    }

    free(line);
   
    fclose(fp);
    
    printf("Number of good reports: %d\n", good_report_count);
    return 0;
}
