#include <iostream> //보안제품개발 트랙 김수헌
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h>
#include <netinet/in.h>
using namespace std;

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

//32bit 8개 숫자 하나당 4bit 2^4 = 16, 0 1 2 3 4 5 6 7 8 9 10 A B C D F

int main(int argc, char *argv[])
{
    FILE* f1; //1000
    FILE* f2; //500

    uint32_t hex1 = 0;
    uint32_t hex2 = 0;

    if(argc < 3) //인자값 오류
    {
        printf("argument Error\n");
        exit(-1);
    }

    //바이너리 파일 오픈
    if((f1 = fopen(argv[1], "rb")) == NULL)
    {
        printf("fopen Error : %s\n", argv[1]);
        exit(-1);
    }

    if((f2 = fopen(argv[2], "rb")) == NULL)
    {
        printf("fopen Error : %s\n", argv[2]);
        exit(-1);
    }

    //4 바이트만큼 읽음
    if(fread(&hex1, sizeof(int), 1, f1) == 0)
    {
        printf("fread Error\n");
        exit(-1);
    }

    if(fread(&hex2, sizeof(int), 1, f2) == 0)
    {
        printf("fread Error\n");
        exit(-1);
    }

    //NBO TO HBO
    hex1 = ntohl(hex1);
    hex2 = ntohl(hex2);

    //값 출력
    printf("%08x\n", hex1+hex2);

    return 0;
}
