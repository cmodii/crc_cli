#include "../include/checksum.h"
#include "unity/unity.h"
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void valid_crc8(void) {
    const char* input_str = "Hello, World!";
    uint8_t crc_result = crc8(input_str, strlen(input_str));

    TEST_ASSERT_EQUAL_HEX8(0x87, crc_result);
}

void valid_crc16(void) {
    const unsigned char* input_str = "Don't bite more than you can chew";
    uint16_t crc_result = crc16(input_str, strlen(input_str));

    TEST_ASSERT_EQUAL_HEX16(0x3BE1, crc_result);
}

void valid_crc32(void) {
    const unsigned char* input_str = "Sic Parvis Magna";
    uint32_t crc_result = crc32(input_str, strlen(input_str));

    TEST_ASSERT_EQUAL_HEX32(0x1CA2CA8A, crc_result);
}

void crc_verification_on_reciever(void) {
    const unsigned char* input_str = "Fell";
    unsigned char appended_input[5];

    // appending the CRC8 byte of "Fell" to input_str to verify whether data is corrupted or not
    // when transmissioned by seeing if appended_input's CRC8 evaluates to 0x0
    memcpy(appended_input, input_str, strlen(input_str));
    appended_input[4] = crc8((const unsigned char*)input_str, strlen(input_str));

    uint8_t crc_check_result = crc8((const unsigned char*)appended_input, strlen(input_str)+1);

    TEST_ASSERT_EQUAL_HEX8(0x0, crc_check_result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(valid_crc8);
    RUN_TEST(valid_crc16);
    RUN_TEST(valid_crc32);
    RUN_TEST(crc_verification_on_reciever);

    return UNITY_END();
}