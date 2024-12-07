#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char *argv[]) {

    FILE *fp;
    char *new_line, *line_001, *line_002, *line_003, *line_004, *line_005, *line_006, *line_007;
    new_line = malloc(256*sizeof(char));
    line_001 = malloc(256*sizeof(char));
    line_002 = malloc(256*sizeof(char));
    line_003 = malloc(256*sizeof(char));
    line_004 = malloc(256*sizeof(char));
    line_005 = malloc(256*sizeof(char));
    line_006 = malloc(256*sizeof(char));
    line_007 = malloc(256*sizeof(char));
    int window_line_width = 0, line_count = 0, line_num = 0, xmas_count = 0;
    char end_of_file_check, *char_pointer;

    fp = fopen(argv[1], "r");


    
    if (argc != 2) {
        printf("%s not called with single filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }



    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((end_of_file_check = getc(fp))!= EOF) {
        if (end_of_file_check == '\n') {
            line_count++;
        }
    }
    line_count++; //Account for last line that ends with EOF

    rewind(fp);

    while (line_num < line_count) {

        if((char_pointer = fgets(new_line, 256, fp)) != NULL){
            line_num++;
            if (window_line_width == 0){
                window_line_width = 1;
            }
            else if (window_line_width < 7){
                window_line_width++;
            }
            
            switch(window_line_width){
                case 7:
                    memcpy(line_001, line_002, 256);
                    memcpy(line_002, line_003, 256);
                    memcpy(line_003, line_004, 256);
                    memcpy(line_004, line_005, 256);
                    memcpy(line_005, line_006, 256);
                    memcpy(line_006, line_007, 256);
                    memcpy(line_007, new_line, 256);
                    break;
                case 6:
                    memcpy(line_002, line_003, 256);
                    memcpy(line_003, line_004, 256);
                    memcpy(line_004, line_005, 256);
                    memcpy(line_005, line_006, 256);                  
                    memcpy(line_006, line_007, 256);
                    memcpy(line_007, new_line, 256);
                    break;
            
                case 5:
                    memcpy(line_003, line_004, 256);
                    memcpy(line_004, line_005, 256);
                    memcpy(line_005, line_006, 256);                  
                    memcpy(line_006, line_007, 256);
                    memcpy(line_007, new_line, 256);
                    break;

                case 4:
                    memcpy(line_004, line_005, 256);
                    memcpy(line_005, line_006, 256);                  
                    memcpy(line_006, line_007, 256);
                    memcpy(line_007, new_line, 256);
                    break;
                
                case 3:
                    memcpy(line_005, line_006, 256);                  
                    memcpy(line_006, line_007, 256);
                    memcpy(line_007, new_line, 256);
                    break;

                case 2:
                    memcpy(line_006, line_007, 256);
                    memcpy(line_007, new_line, 256);
                    break;

                case 1:
                    memcpy(line_007, new_line, 256);
                    break;
            }

            for (int i = 0; i < 256 - 3; i++) {
                // Count both "XMAS" and "SAMX", horizontally
                if(line_007[i] == 'X' && line_007[i+1] == 'M' && line_007[i+2] == 'A' && line_007[i+3] == 'S') {
                    xmas_count++;
                }
                if (line_007[i] == 'S' && line_007[i+1] == 'A' && line_007[i+2] == 'M' && line_007[i+3] == 'X'){
                    xmas_count++;
                }
                
                if(window_line_width >= 4){
                    // Count both "XMAS" and "SAMX", vertically
                    if(line_007[i] == 'X' && line_006[i] == 'M' && line_005[i] == 'A' && line_004[i] == 'S') {
                        xmas_count++;
                    }
                    if(line_007[i] == 'S' && line_006[i] == 'A' && line_005[i] == 'M' && line_004[i] == 'X') {
                        xmas_count++;
                    }
                    // Count both "XMAS" and "SAMX", left-up diagonally
                    if(i >=3){
                        if(line_007[i] == 'X' && line_006[i-1] == 'M' && line_005[i-2] == 'A' && line_004[i-3] == 'S') {
                            xmas_count++;
                        }
                        if(line_007[i] == 'S' && line_006[i-1] == 'A' && line_005[i-2] == 'M' && line_004[i-3] == 'X') {
                            xmas_count++;
                        }
                    }
                    // Count both "XMAS" and "SAMX", right-up diagonally
                    if (i <= 256-4){
                        
                        if(line_007[i] == 'X' && line_006[i+1] == 'M' && line_005[i+2] == 'A' && line_004[i+3] == 'S') {
                            xmas_count++;
                        }
                        if(line_007[i] == 'S' && line_006[i+1] == 'A' && line_005[i+2] == 'M' && line_004[i+3] == 'X') {
                            xmas_count++;
                        }
                    }
                }

            }
        }

    }



    fclose(fp);

    free(new_line);
    free(line_001);
    free(line_002);
    free(line_003);
    free(line_004);
    free(line_005);
    free(line_006);
    free(line_007);
    

    printf("Number of XMAS occurrences: %d\n", xmas_count);
    return 0;

}