#include <stdio.h>

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

// simple function to handle a single byte of data
unsigned int crc8(unsigned int byte) {
    const unsigned int polynomial = 0x7;
    unsigned int crc = byte;

    for (int i = 0; i < 8; i++) { // iterate through each bit (byte+appended 8 bits)
        if ((crc & 0x80) != 0) {
           crc = (unsigned int) (crc << 1 & 0xFF) ^ polynomial;
        } else {
            crc = (unsigned int) crc << 1 & 0xFF; // register must be fixed on 8 bits
        }
    }

    return crc;
}

unsigned int verify_crc(unsigned int byte) {
    return crc8(((byte << 4) | crc8(byte))); // invalid for now
}

int main() {
    // e.g: getting the crc of each byte in the input stream "Hello"
    char bytes[5] = {'H', 'e', 'l', 'l', 'o'};
    for (int i = 0; i < 5; i++) {
        unsigned int byte_crc = crc8((unsigned int) bytes[i]);
        printf("[%c] CRC-8 => %X | ", bytes[i], byte_crc);
        print_binary(byte_crc);
        printf("\n");
    }
}