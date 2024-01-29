
#include "utils.h"


int compareStrings(const uint8_t* str1, const uint8_t* str2, int length) {
    
    for (int i = 0; i < length; ++i) {
        if (str1[i] != str2[i]) {
            return 0;  // Strings are not equal
        }
    }
    return 1;  // Strings are equal
}

void generate_random_array(uint8_t *array, int length){

    for(int i = 0; i < length; i++){

        array[i] = esp_random() & 0xff;
    }
}
