#include "../include/checksum.h"
#include "unity/unity.h"

void valid_crc8(void) {
    const char* input_str = "Hello, World!";
    uint8_t crc_result = crc8(input_str, strlen(input_str));

    TEST_ASSERT_EQUAL_HEX8(0x87, crc_result);
}

void valid_crc16(void) {
    const char* input_str = "Don't bite more than you can chew";
    uint16_t crc_result = crc16(input_str, strlen(input_str));

    TEST_ASSERT_EQUAL_HEX16(0x3BE1, crc_result);
}

void valid_crc32(void) {
    const char* input_str = "Sic Parvis Magna";
    uint16_t crc_result = crc16(input_str, strlen(input_str));

    TEST_ASSERT_EQUAL_HEX32(0x1CA2CA8A, crc_result);
}

void crc_verification_on_reciever(void) {
    const char* input_str = "Fell";
    const char* appended_iput = {'F','e', 'l', 'l', (unsigned char) crc8(input_str, strlen(input_str))};
    uint8_t crc_check_result = crc8(appended_iput, strlen(appended_iput));

    TEST_ASSRT_EQUAL_HEX8(0x0, crc_check_result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(valid_crc8);
    RUN_TEST(valid_crc16);
    RUN_TEST(valid_crc32);
    RUN_TEST(crc_verification_on_reciever);

    return UNITY_END();
}