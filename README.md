
# CRC Command Line Interface

## About

A small command-line tool for calculating CRC values (up to CRC-32) for a given input.

The **CRC (Cyclic Redundancy Check)** algorithm is utilized to detect errors or corruption during data transmission. It is reliable since the receiver can verify data integrity using only the data itself and a generator polynomial known to both sender and receiver.

If you want to get a good (but not necessarily explicit) understanding of CRCs then refer to [sunshine2k's article](https://www.sunshine2k.de/articles/coding/crc/understanding_crc.html).

---

## Installation & Usage

This project requires [CMake](https://cmake.org/download/) and [Ninja](https://ninja-build.org/) to build.

1. **Clone the repository:**
   ```sh
   gh repo clone cmodii/crc_cli
   ```

2. **Create a build directory and build the project:**
   ```sh
   mkdir build
   cd build
   cmake ..
   ninja
   ```

3. **Run the tool:**
   ```sh
   cli <mode> <input string>
   ```

---

### Supported modes

| Mode   | Polynomial (hex) |
|--------|------------------|
| crc32  | 0x4C11DB7        |
| crc16  | 0xA001           |
| crc8   | 0x7              |

> [!TIP] 
> You can modify the polynomial values in the [checksum header file](include/checksum.h) and the lookup tables for each CRC in their respective source files: [crc8](src/crc8.c), [crc16](src/crc16.c), [crc32](src/crc32.c).


---

## Example

Running the command:

```sh
cli crc16 "CRC CLI in action"
```

Produces:

<img width="734" height="139" alt="image" src="https://github.com/user-attachments/assets/d3c958d6-31be-4973-89fc-79d19355d13e" />

---
