/*
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

//헥사데시멀로 변환해주는 코드
void dump(void* p, size_t n) {
    uint8_t* u8 = static_cast<uint8_t*>(p);
    size_t i = 0;
    while (true) {
        printf("%02X ", *u8++);
        if (++i >= n)
            break;
        if (i % 8 == 0)
            printf(" ");
        if (i % 16 == 0)
            printf("\n");
    }
    printf("\n");
}

void write_4660()
{
    uint16_t port = 4660; //0x1234
    printf("port number = %d\n", port);
    dump(&port, sizeof(port));
}

uint16_t my_ntohs(uint16_t n)
{
    uint16_t a1 = n & 0xFF00;
    a1 = a1 >> 8;
    //printf("%04x\n", a1);
    uint16_t a2 = n & 0x00FF;
    a2 = a2 << 8;
    //printf("%04x\n", a2);

    uint16_t a3 = a1 | a2; //a1 + a2
    //printf("%04x\n", a3);

    //return a3;

    //한줄로 표현 가능
    return (n & 0xFF00) >> 8 | (n & 0x00FF) << 8;
}

void write_0x1234()
{
    uint8_t network_buffer[] = { 0x12, 0x34 };
    uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
    //uint16_t n = *p;
    uint16_t n = my_ntohs(*p);
    printf("16 bit number = 0x%x\n", n);
}

uint32_t my_ntohl(uint32_t n)
{
    uint32_t a1 = (n & 0xFF000000) >> 24;
    //printf("%08x\n", a1);

    uint32_t a2 = (n & 0x00FF0000) >> 8;
    //printf("%08x\n", a2);

    uint32_t a3 = (n & 0x0000FF00) << 8;
    //printf("%08x\n", a3);

    uint32_t a4 = (n & 0x000000FF) << 24;
    //printf("%08x\n", a4);

    return a1 | a2 | a3 | a4;
}

void write_0x12345678()
{
    uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
    uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
    uint32_t n = my_ntohl(*p);
    printf("32 bit number = 0x%x\n", n);
}


int main()
{
    //write_4660();
    //write_0x1234();
    //write_0x12345678();

    return 0;
}
*/
