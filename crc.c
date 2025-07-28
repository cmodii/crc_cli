#include <stdio.h>

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

unsigned int crc8(unsigned int* bytes, int n) {
    int max_iterations = 10;
    unsigned int crc = *bytes;
    const unsigned int divisor = 0b100011101;
    unsigned int offset = 0;

    for (int i = 0; i < n; i++) {
        crc <<= 8; // step 1: append n=8 bits to the data
        while (crc >> 8 != 0b00000000 && max_iterations > 0) { // as long as actual input data isn't zeroed out
            while (((crc >> (15-offset)) & 1) == 0) {
                offset += 1;
            } 

            max_iterations--;
            crc ^= (divisor << (7 - offset));
        }
    }

    return crc;
}

int main() {
    unsigned int bytes[1] = {0b11000010};
    unsigned int crc = crc8(bytes, 1);
    print_binary(crc);
}