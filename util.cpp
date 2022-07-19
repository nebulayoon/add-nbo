#include "util.h"

uint32_t add(uint32_t first, uint32_t second){
    return htonl(first) + htonl(second);
}

void result_print(uint32_t first, uint32_t second){
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", htonl(first), htonl(first), htonl(second), htonl(second), add(first, second), add(first, second));
}