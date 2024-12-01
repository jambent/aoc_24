#include <stdio.h>

int main (void) {
    //Selection sort algorithm
    int array_for_sorting[5] = {1, 4, 0, 2, 3};
    int *target_value, *lowest_value, temp;

    for (int i = 0; i < 4; i++){
        target_value = &array_for_sorting[i];
        lowest_value = &array_for_sorting[i];
        for (int j = i + 1; j < 5; j++){
            if (array_for_sorting[j] < *lowest_value){
                lowest_value = &array_for_sorting[j];
            }
        }
        if (*lowest_value < *target_value){
            temp = *target_value;
            *target_value = *lowest_value;
            *lowest_value = temp;
        }
    }
    
    printf("Sorted array: %d, %d, %d, %d, %d\n", 
        array_for_sorting[0], array_for_sorting[1], array_for_sorting[2], 
        array_for_sorting[3], array_for_sorting[4]);

    return 0;
}