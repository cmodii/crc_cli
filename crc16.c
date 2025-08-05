#include <stdio.h>
#include <string.h>
#define CRC16_POLYNOMIAL 0x1021

unsigned int CRC16_table[256];

void calculate_CRC16_table() {
    unsigned int currCRC;
    for (unsigned int dividend = 0; dividend < 256; dividend++) {
        currCRC = (unsigned int) dividend << 8;

        for (int i = 0; i < 8; i++) {
            if ((currCRC & 0x8000) != 0) {
                currCRC = (unsigned int) ((currCRC << 1) & 0xFFFF) ^ CRC16_POLYNOMIAL;
            } else {
                currCRC = (currCRC << 1) & 0xFFFF;
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

unsigned int crc16(unsigned char *bytes, size_t byte_count) {
    unsigned int crc = 0;

    for (int i = 0; i < byte_count; i++) {
        unsigned int pos = (unsigned int) (crc >> 8) ^ (bytes[i]);
        crc = (CRC16_table[pos] ^ (crc << 8 & 0xFFFF));
    }

    return crc;
}

int main() {
    // e.g: getting the crc of each byte in the input stream "Hello, World!"
    calculate_CRC16_table(); // expensive

    unsigned char data[] = "Hello, World!";
    unsigned int crc = crc16(data, strlen(data));

    printf("[Data]: %s\n", data);
    printf("[CRC-16]: %X | %d | ", crc, crc);
    print_binary(crc);
}