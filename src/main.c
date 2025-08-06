#include <stdio.h>
#include <string.h>
#include "../include/checksum.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Incorrect format. Usage: %s <crc8|crc16|crc32> ""input string""");
        return 1;
    }

    if (argc > 3) {
        printf("Note: for space separated text use quotation marks: ""input stream""\n");
    }
    
    const char *mode = argv[1];
    const char *input = argv[2];
    unsigned int CRC; unsigned int poly; unsigned int start_value;

    if (strcmp("crc8", mode)) {
        CRC = crc8(input, strlen(input));
        poly = CRC_8_POLYNOMIAL;
        start_value = CRC8_START_VALUE;
    } else if (strcmp("crc16", mode)) {
        CRC = crc16(input, strlen(input));
        poly = CRC_16_POLYNOMIAL;
        start_value = CRC16_START_VALUE;
    } else if (strcmp("crc32", mode)) {
        CRC = crc32(input, strlen(input));
        poly = CRC_32_POLYNOMIAL;
        start_value = CRC32_START_VALUE;
    } else {
        printf("Specify a correct mode: <crc8|crc16|crc32>");
        return 1;
    }

    printf("[Input stream]: %s\n[CRC]: 0x%X\n[Polynomial]: 0x%X\n[CRC initial value]: %X", input, CRC, poly, start_value);
    return 0;
}