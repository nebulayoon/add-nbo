#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t add(uint32_t first, uint32_t second){
    return htonl(first) + htonl(second);
}

void result_print(uint32_t first, uint32_t second){
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", htonl(first), htonl(first), htonl(second), htonl(second), add(first, second), add(first, second));
}

int main(int argc, char *argv[]){

    if(argc < 3){
        printf("add-nbo <file1> <file2>\n");
        return -1;
    }

    FILE* first_file_ptr = fopen(argv[1], "rb");
    if(first_file_ptr == NULL){
        printf("%s not found\n", argv[1]);
        return -1;
    }
    FILE* second_file_ptr = fopen(argv[2], "rb");
    if(first_file_ptr == NULL){
        printf("%s not found\n", argv[2]);
        return -1;
    }

    uint32_t first_file_data = 0;
    uint32_t second_file_data = 0;

    fread(&first_file_data, sizeof(uint32_t), 1, first_file_ptr);
    fread(&second_file_data, sizeof(uint32_t), 1, second_file_ptr);
    
    result_print(first_file_data, second_file_data);

    fclose(first_file_ptr);
    fclose(second_file_ptr);

    return 0;
}