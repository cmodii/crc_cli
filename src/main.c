#include <stdio.h>
#include <string.h>
#include "../include/checksum.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("\033[31mIncorrect format.\033[0m Usage: \033[32m%s <crc8|crc16|crc32> \"input string\"\033[0m", argv[0]);
        return 1;
    }
    
    const char *mode = argv[1];
    const char *input = argv[2];
    unsigned int CRC, poly, start_value;
    
    if (!strcmp("crc8", mode)) {
        CRC = crc8(input, strlen(input));
        poly = CRC_8_POLYNOMIAL;
        start_value = CRC8_START_VALUE;
    } else if (!strcmp("crc16", mode)) {
        CRC = crc16(input, strlen(input));
        poly = CRC_16_POLYNOMIAL;
        start_value = CRC16_START_VALUE;
    } else if (!strcmp("crc32", mode)) {
        CRC = crc32(input, strlen(input));
        poly = CRC_32_POLYNOMIAL;
        start_value = CRC32_START_VALUE;
    } else {
        printf("\033[33mSpecify a correct mode: <crc8|crc16|crc32>\033[0m");
        return 1;
    }
    
    printf("\033[34m[Input stream]:\033[0m \033[32m%s\033[0m\n\033[34m[CRC]:\033[0m \033[32m0x%X\033[0m\n\033[34m[Polynomial]:\033[0m 0x%X\n\033[34m[CRC initial value]:\033[0m %X\n\n", input, CRC, poly, start_value);
    
    if (argc > 3) {
        printf("\033[33mNote: for space separated text use quotation marks. e.g: cli crc32 \"Sic Parvis Magna\"\033[0m\n", 33);
    }
    return 0;
}