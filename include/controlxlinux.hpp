#include <stdint.h>
#include <filesystem>
#include <iostream>
#include <fstream>

// In the future, I need to decompile this and make it into a class/struct
uint8_t header_data[] = {
    0x80, 0x0F, 0x00, 0x00, 0x00, 0x2E, 0x80, 0x4A, 0x4C, 0x49, 0x4E, 0x55, 0x58,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x80, 0x13, 0x35, 0x30, 0x46, 0x80, 0x13, 0x35,
    0x31, 0x30, 0x80, 0x2E, 0x00, 0x06, 0x31, 0x2E, 0x30, 0x20, 0x20, 0x20, 0x80,
    0x2E, 0x00, 0x00, 0x80, 0x88, 0x11, 0x80, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00,
    0xFE, 0x0F, 0xDC, 0xDE};