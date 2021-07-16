#include <iostream> //보안제품개발 트랙 김수헌
#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h>
#include <netinet/in.h>
using namespace std;

//32bit 8개 숫자 하나당 4bit 2^4 = 16, 0 1 2 3 4 5 6 7 8 9 10 A B C D F

uint32_t binToHex(char* argv)
{
    FILE* file;
    uint32_t hex;

    //바이너리 파일 오픈
    if((file = fopen(argv, "rb")) == NULL)
    {
        printf("fopen Error : %s\n", argv);
        exit(-1);
    }

    //4 바이트만큼 읽음
    if(fread(&hex, 1, sizeof(uint32_t), file) == 0)
    {
        printf("fread Error\n");
        exit(-1);
    }


    return ntohl(hex);
}

int main(int argc, char* argv[])
{
    uint32_t hex1 = 0;
    uint32_t hex2 = 0;

    if(argc < 3) //인자값 오류
    {
        printf("argument Error\n");
        exit(-1);
    }

    hex1 = binToHex(argv[1]);
    hex2 = binToHex(argv[2]);

    //값 출력
    printf("%d(%04x) + %d(%04x) = %d(%04x)\n", hex1, hex1, hex2, hex2, hex1+hex2, hex1+hex2);

    return 0;
}
