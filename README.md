# add-nbo
Add Some Number by Network Byte Order

---

## Byte Order

10 진수 / 16 진수 / 2 진수

NBO(network byte order) : 네트워크 레벨에서 숫자를 표현하는 순서

HBO(host byte order) : 호스트에 레벨에서 숫자를 표현하는 순서

---

## Unit

nibble : Byte의 절반의 의미로 4 bit, 16가지의 경우의 수를 가진다  2^4
byte : 관례상 8 bit, 256가지의 경우의 수를 가진다 2^8

---

## Endian

LE(little-endian) : HBO와 NBO가 다름. EX) Intel

BE(big-endian) : HBO와 NBO가 같음. EX) AMD

---

## #include <netinet/in.h>

Function : `uint16_t ntohs(uint16_t netshort);` / Size : 2 byte / Conversion : NBO to HBO

Function : `uint16_t htons(uint16_t hostshort);` / Size : 2 byte / Conversion : HBO to NBO

Function : `uint32_t ntohl(uint32_t netlong);` / Size : 4 byte / Conversion : NBO to HBO

Function : `uint32_t htonl(uint32_t hostlong);` / Size : 4 byte / Conversion : HBO to NBO

---

