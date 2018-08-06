/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the MIT License. *
 * http://www.opensource.org/licenses/MIT                                 *
 *                                                                        *
 **************************************************************************
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "GeneralHashFunctions.h"

void foo()
{
  /* unsigned char x = 128; */
  /* char y = 128; */
  /* signed char z = 128; */
  /* char w = 127; */
  /* char str[] = {w + 1, 0}; */
  /* printf("%x %x %x %x\n", x, y, z, w + 1); */
}

typedef unsigned long ulong;

void testWithLen(const unsigned char *key, size_t len, ulong expected64)
{
  printf("Key:                           %s\n", key             );
  /* /\* printf(" 1. RS-Hash Function Value:    %x\n", RSHash   (key,len)); *\/ */
  /* /\* printf(" 2. JS-Hash Function Value:    %x\n", JSHash   (key,len)); *\/ */
  unsigned h1 = PJWHash  (key,len);
  assert (h1 == HashPJW (key));
  unsigned long h2 = PJWHash64(key,len);
  assert (h2 == HashPJW64(key));

  printf(" 3. PJW-Hash Function Value:   %x\n", h1);
  printf(" 4. PJW64-Hash Function Value: %lx\n", h2);

  assert (h2 == expected64);
  /* /\* printf(" 5. ELF-Hash Function Value:   %x\n", ELFHash  (key,len)); *\/ */
  /* /\* printf(" 6. BKDR-Hash Function Value:  %x\n", BKDRHash (key,len)); *\/ */
  /* /\* printf(" 7. SDBM-Hash Function Value:  %x\n", SDBMHash (key,len)); *\/ */
  /* /\* printf(" 8. DJB-Hash Function Value:   %x\n", DJBHash  (key,len)); *\/ */
  /* /\* printf(" 9. DEK-Hash Function Value:   %x\n", DEKHash  (key,len)); *\/ */
  /* /\* printf("10. BP-Hash Function Value:    %x\n", BPHash   (key,len)); *\/ */
  /* /\* printf("11. FNV-Hash Function Value:   %x\n", FNVHash  (key,len)); *\/ */
  /* /\* printf("12. AP-Hash Function Value:    %x\n", APHash   (key,len)); *\/ */
}

void test(const unsigned char *key, ulong expected64)
{
  int len = strlen((const char *) key);
  testWithLen(key, len, expected64);
}

int main(int argc, char* argv[])
{
  const char* key = "abcdefghijklmnopqrstuvwxyz1234567890";
  foo();

  printf("General Purpose Hash Function Algorithms Test\n");
  printf("By Arash Partow - 2002          \n"                 );
  test((const unsigned char *)key, 0x34545c16020230L);
  /* char w = 127; */
  /* char str[] = {w + 1, 0}; */
  test((const unsigned char []) {0}, 0);
  test((const unsigned char []) {0, 0}, 0);
  test((const unsigned char []) {1, 0}, 1);
  test((const unsigned char []) {127, 0}, 127);
  test((const unsigned char []) {-128, 0}, 128);
  test((const unsigned char []) {1, 1, 0}, 0x101L);
  test((const unsigned char []) {1, 1, 1, 0}, 0x10101L);
  test((const unsigned char []) {1, 1, 1, 1, 0}, 0x1010101l);
  test((const unsigned char []) {1, 1, 1, 1, 1, 0}, 0x101010101L);
  test((const unsigned char []) {2, 2, 2, 2, 2, 0}, 0x202020202L);
  test((const unsigned char []) {1, 1, 1, 1, 1, 1, 0}, 0x10101010101L);
  test((const unsigned char []) {1, 1, 1, 1, 1, 1, 1, 0}, 0x1010101010101L);
  test((const unsigned char []) {1, 1, 1, 1, 1, 1, 1, 1, 0}, 0x1010101010001L);

  // Translating Scala
  // testHash(0X1010101L, Array.fill(1024)(1))
  unsigned char inp[1025];
  inp[1024] = 0;
  for (int i = 0; i < 1024; i++) {
    inp[i] = 1;
  }
  test(inp, 0x1010101L);

  // Translating Scala
  // testHash(0xaafefeaaab54ffL, Array.tabulate(1024)(_.toByte))
  unsigned char inp2[1025];
  inp2[1024] = 0;
  for (int i = 0; i < 1024; i++) {
    inp[i] = (unsigned char)i;
  }
  testWithLen(inp, 1024, 0xaafefeaaab54ffL);

  return 0;
}
