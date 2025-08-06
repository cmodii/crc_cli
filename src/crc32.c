#include "../include/checksum.h"
#include <stdint.h>

const uint32_t crc_lookup_tab32[256];

/*
void calculate_CRC32_table() {
    unsigned int currCRC;
    for (unsigned int dividend = 0; dividend < 256; dividend++) {
        currCRC = (unsigned int) dividend << 24;

        for (int i = 0; i < 8; i++) {
            if ((currCRC & 0x80000000) != 0) {
                currCRC = (unsigned int) ((currCRC << 1) & 0xFFFFFFFF) ^ CRC_32_POLYNOMIAL;
            } else {
                currCRC = (currCRC << 1) & 0xFFFFFFFF;
            }
        }

        crc_lookup_tab32[dividend] = currCRC;
    }
}
*/

uint32_t crc32(const unsigned char *input_str, size_t byte_num) {
    uint32_t crc = CRC32_START_VALUE;

    for (size_t i = 0; i < byte_num; i++) {
        crc = crc_lookup_tab32[(crc >> 24) ^ *(input_str+i)] ^ (crc << 8);
    }

    return crc;
}

uint32_t update_crc32(unsigned char crc, unsigned char new_val) {
    return crc_lookup_tab32[(crc >> 24) ^ new_val] ^ (crc << 8);
}