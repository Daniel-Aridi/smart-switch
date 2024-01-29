#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include "esp_system.h"
#include "esp_random.h"

int compareStrings(const uint8_t* str1, const uint8_t* str2, int length);

void generate_random_array(uint8_t *array, int length); 
#endif