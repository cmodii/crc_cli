#include <stdio.h>
#include <string.h>

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

// simple function to handle a single byte of data
unsigned int crc8(char *bytes) {
    const unsigned int polynomial = 0x7;
    unsigned int crc = 0;

    for (int j = 0; j < strlen(bytes); j++) {
        crc ^= (unsigned int) *(bytes+j);

        for (int i = 0; i < 8; i++) { // iterate through each bit (byte+appended 8 bits)
            if ((crc & 0x80) != 0) {
                crc = (unsigned int) (crc << 1 & 0xFF) ^ polynomial;
            } else {
                crc = (unsigned int) crc << 1 & 0xFF; // register must be fixed on 8 bits
            }
        }
    }

    return crc;
}

int main() {
    // e.g: getting the crc of each byte in the input stream "Hello"
    char data[] = "Hello World";
    unsigned int crc = crc8(data);

    printf("[Data]: %s\n", data);
    printf("[CRC]: %X |", crc);
    print_binary(crc);
}