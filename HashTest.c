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

#include "GeneralHashFunctions.h"


int main(int argc, char* argv[])
{
   char* key = "abcdefghijklmnopqrstuvwxyz1234567890";

   printf("General Purpose Hash Function Algorithms Test\n");
   printf("By Arash Partow - 2002          \n"                 );
   printf("Key:                           %s\n", key             );
   printf(" 1. RS-Hash Function Value:    %x\n", RSHash   (key,36));
   printf(" 2. JS-Hash Function Value:    %x\n", JSHash   (key,36));
   printf(" 3. PJW-Hash Function Value:   %x\n", PJWHash  (key,36));
   printf(" 3. PJW-Hash Function Value again:   %x\n", HashPJW (key));
   printf(" 4. PJW64-Hash Function Value: %lx\n",PJWHash64(key,36));
   printf(" 4. PJW64-Hash Function Value again:   %lx\n", HashPJW64(key));
   printf(" 5. ELF-Hash Function Value:   %x\n", ELFHash  (key,36));
   printf(" 6. BKDR-Hash Function Value:  %x\n", BKDRHash (key,36));
   printf(" 7. SDBM-Hash Function Value:  %x\n", SDBMHash (key,36));
   printf(" 8. DJB-Hash Function Value:   %x\n", DJBHash  (key,36));
   printf(" 9. DEK-Hash Function Value:   %x\n", DEKHash  (key,36));
   printf("10. BP-Hash Function Value:    %x\n", BPHash   (key,36));
   printf("11. FNV-Hash Function Value:   %x\n", FNVHash  (key,36));
   printf("12. AP-Hash Function Value:    %x\n", APHash   (key,36));

   return 1;
}
