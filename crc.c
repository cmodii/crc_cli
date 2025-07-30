#include <stdio.h>
#include <string.h>

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

unsigned int crc8(char *bytes) {
    const unsigned int polynomial = 0x7;
    unsigned int crc = 0;

    for (int j = 0; j < strlen(bytes); j++) {
        crc ^= (unsigned int) *(bytes+j); // XOR with current byte

        for (int i = 0; i < 8; i++) {
            if ((crc & 0x80) != 0) { // is MSB set?
                crc = (unsigned int) (crc << 1) ^ polynomial; // XOR with divisor
            } else {
                crc = (unsigned int) crc << 1; // otherwise push incoming stream
            }
        }
    }

    crc &= 0xFF; // register must be fixed on 8 bits
    return crc;
}

int main() {
    // e.g: getting the crc of each byte in the input stream "Hello"
    char data[] = "Hello, World!";
    unsigned int crc = crc8(data);

    printf("[Data]: %s\n", data);
    printf("[CRC]: %X |", crc);
    print_binary(crc);
}