#ifndef CRC_CHECKSUM_H
#define CRC_CHECKSUM_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define CRC_8_POLYNOMIAL 0x7
#define CRC_16_POLYNOMIAL 0x1021
#define CRC_32_POLYNOMIAL 0x4C11DB7

#define CRC8_START_VALUE 0x0
#define CRC16_START_VALUE 0x0000
#define CRC32_START_VALUE 0x00000000

uint8_t crc8(const unsigned char *input_str, size_t bytes_num);
uint16_t crc16(const unsigned char *input_str, size_t bytes_num);
uint32_t crc32(const unsigned char *input_str, size_t bytes_num);
uint8_t update_crc8(unsigned char crc, unsigned char new_val);
uint16_t update_crc16(unsigned char crc, unsigned char new_val);
uint32_t update_crc32(unsigned char crc, unsigned char new_val);

extern uint8_t crc_lookup_tab8[];
extern uint16_t crc_lookup_tab16[];
extern uint32_t crc_lookup_tab32[];

#endif