#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

    FILE *fp;

    fp = fopen(argv[1], "r");


    
    if (argc != 2) {
        printf("%s not called with single filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }



    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int multiplier_function_sum = 0;
    int multiplier_arg_1 = 0, multiplier_arg_2 = 0;
    char multiplier_function_start_check[5];
    char comma_check,end_check;

    while ((multiplier_function_start_check[0] = getc(fp))!=EOF){

    if(multiplier_function_start_check[0] == 'm'){
        fscanf(fp, "%c", &multiplier_function_start_check[1]);
        if(multiplier_function_start_check[1] == 'u'){
            fscanf(fp, "%c", &multiplier_function_start_check[2]);
            if(multiplier_function_start_check[2] == 'l'){
                fscanf(fp, "%c", &multiplier_function_start_check[3]);
                if(multiplier_function_start_check[3] == '('){
                    fscanf(fp, "%d", &multiplier_arg_1);
                    if(multiplier_arg_1){
                        fscanf(fp, "%c", &comma_check);
                        if (comma_check == ',') {
                            fscanf(fp, "%d", &multiplier_arg_2);
                            if(multiplier_arg_2){
                                 fscanf(fp, "%c", &end_check);
                                 if(end_check == ')'){
                                     multiplier_function_sum += multiplier_arg_1 * multiplier_arg_2;
                                     multiplier_arg_1 = 0;
                                     multiplier_arg_2 = 0;
                                     continue;
                                 }
                                 else{
                                     continue;
                                 }

                            }
                            else{
                                continue;
                            }
                        }
                        else{
                            continue;
                        }
                        
                    }
                    else{
                        continue;
                    }
                }
                else{
                    continue;
                }
            }
            else {
                continue;
            }
        }
        else{
            continue;
        }
    }
    else {
        continue;
    }
    }
    printf("Sum of all multiplier functions: %d\n", multiplier_function_sum);
    fclose(fp);

    return 0;
}

