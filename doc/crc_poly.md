### CRC polynomial values

| Name | Value (hex) |
| :--- | ---: |
|**`CRC_8_POLYNOMIAL`**|`7`|
|**`CRC_16_POLYNOMIAL`**|`1021`|
|**`CRC_32_POLYNOMIAL`**|`4C11DB7`|

### Description

The mathematical background of CRC is setup with polynomial divisions of a certain order. Each polynomial is represented in the CRC calculation as a bit pattern where each bit defines if a certain order polynomial factor is one or zero. For the algorithms it is enough to know which bit pattern to use. These are defined in the `CRC_..._POLYNOMIAL`

### See Also

* [CRC start values](crc_start.md)