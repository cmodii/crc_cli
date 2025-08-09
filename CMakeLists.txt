cmake_minimum_required(VERSION 3.10)
project(crc_cli LANGUAGES C)

# -- Main --
add_library(crc STATIC
    src/crc8.c
    src/crc16.c
    src/crc32.c
)

target_include_directories(crc PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_executable(cli src/main.c)
target_link_libraries(cli PRIVATE crc)

# -- Testing --
add_library(unity
    tests/unity/unity.c
)

target_include_directories(unity PUBLIC unity)
add_executable(test_checksum
    tests/test_checksum.c    
)

target_include_directories(test_checksum PRIVATE include)
target_link_libraries(test_checksum PRIVATE crc unity)

enable_testing()
add_test(NAME checksum_tests COMMAND test_checksum)