#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define CRC8_POLYNOMIAL 0x7

uint8_t CRC8_table[256];

void calculate_CRC8_table() {
    uint8_t currCRC;
    for (uint8_t dividend = 0; dividend < 255; dividend++) {
        currCRC = dividend;

        for (int i = 0; i < 8; i++) {
            if ((currCRC & 0x80) != 0) {
                currCRC = ((currCRC << 1)) ^ CRC8_POLYNOMIAL;
            } else {
                currCRC = (currCRC) << 1;
            }
        }

        CRC8_table[dividend] = currCRC;
    }
}

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

uint8_t crc8(unsigned char *bytes, size_t byte_count) {
    uint8_t crc = 0;

    printf("%lld", byte_count);
    for (int i = 0; i < byte_count; i++) {
        crc = CRC8_table[*(bytes+i) ^ (crc)];
    }

    return crc;
}

int main() {
    // e.g: getting the crc of each byte in the input stream "Hello, World!"
    calculate_CRC8_table(); // expensive

    unsigned char data[] = "Hello, World!";
    uint8_t crc = crc8(data, sizeof(data));

    printf("[Data]: %s\n", data);
    printf("[CRC-8]: %X | %d | ", crc, crc);
    print_binary((unsigned int) crc);
}