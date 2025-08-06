cmake_minimum_required(VERSION 4.0.1)

project(crc_cli LANGUAGES C)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(cli src/main.c src/crc8.c src/crc16.c src/crc32.c include/checksum.h)