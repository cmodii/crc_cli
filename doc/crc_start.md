### CRC start values

| Name | Value (hex) |
| :--- | ---: |
|**`CRC_START_8`**|`00`|
|**`CRC_START_16`**|`0000`|
|**`CRC_START_32`**|`FFFFFFFF`|

### Description

Before the calculation of the CRC value of a byte blob can start, the value of the CRC must first be initialized. The value to use depends on the CRC algorithm.

### See Also

* [CRC polynomials](crc_poly.md)