#include <stdio.h>
#include <string.h>
#define CR8_POLYNOMIAL 0x7

unsigned int CRC8_table[256];

void calculate_CRC8_table() {
    unsigned int currCRC;
    for (unsigned int dividend = 0; dividend < 256; dividend++) {
        currCRC = dividend;

        for (int i = 0; i < 8; i++) {
            if ((currCRC & 0x80) != 0) {
                currCRC = (unsigned int) ((currCRC << 1) & 0xFF) ^ CR8_POLYNOMIAL;
            } else {
                currCRC = (currCRC & 0xFF) << 1;
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

unsigned int crc8(char *bytes) {
    unsigned int crc = 0;

    for (int i = 0; i < strlen(bytes); i++) {
        unsigned int data = ((unsigned int) bytes[i]) ^ (crc & 0xFF);
        crc = CRC8_table[data];
    }

    return crc;
}

int main() {
    // e.g: getting the crc of each byte in the input stream "Hello, World!"
    calculate_CRC8_table(); // expensive

    for (int i = 0; i < 256; i++) {
        printf("[%X] ", CRC8_table[i]);
        if (i % 16 == 0 && i > 1) {printf("\n");}
    }
    printf("\n");

    char data[] = "Hello, World!";
    unsigned int crc = crc8(data);

    printf("[Data]: %s\n", data);
    printf("[CRC]: %X | ", crc);
    print_binary(crc);
}