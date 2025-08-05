#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define CRC16_POLYNOMIAL 0x1021

uint16_t CRC16_table[256];

void calculate_CRC16_table() {
    uint16_t currCRC;
    for (uint8_t dividend = 0; dividend < 256; dividend++) {
        currCRC = (uint16_t) dividend << 8;

        for (int i = 0; i < 8; i++) {
            if ((currCRC & 0x8000) != 0) {
                currCRC =((currCRC << 1)) ^ CRC16_POLYNOMIAL;
            } else {
                currCRC = (currCRC << 1);
            }
        }

        CRC16_table[dividend] = currCRC;
    }
}

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

uint16_t crc16(unsigned char *bytes, size_t byte_count) {
    uint16_t crc = 0;

    for (int i = 0; i < byte_count; i++) {
        crc = CRC16_table[(crc >> 8) ^ (bytes[i])] ^ (crc << 8);
    }

    return crc;
}

int main() {
    // e.g: getting the crc of each byte in the input stream "Hello, World!"
    calculate_CRC16_table(); // expensive

    unsigned char data[] = "Hello, World!";
    uint16_t crc = crc16(data, strlen(data));

    printf("[Data]: %s\n", data);
    printf("[CRC-16]: %X | %d | ", crc, crc);
    print_binary(crc);
}