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
        printf("originally crc is: ");
        print_binary(crc);
        crc <<= 8; // step 1: append n=8 bits to the data
        printf("\nafter appending %d its now: ", 8);
        print_binary(crc);
        while (crc >> 8 != 0b00000000 && max_iterations > 0) { // as long as actual input data isn't zeroed out
            printf("\noriginal data isn't zeroed out yet\n\n");
            printf("our offset is %d thus our divisor is: ", offset);
            print_binary(divisor << (7-offset));
            while (((crc >> (15-offset)) & 1) == 0) {
                printf("\nadding offset\n");
                offset += 1;
            } 

            max_iterations--;
            crc ^= (divisor << (7 - offset));
            printf("\ncurrent result: ");
            print_binary(crc);
            printf("\n");
        }
    }

    return crc;
}

int main() {
    unsigned int bytes[1] = {0b11000010};
    unsigned int crc = crc8(bytes, 1);
    printf("\n\n end result: ");
    print_binary(crc);
}