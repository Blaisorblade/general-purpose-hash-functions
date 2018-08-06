#
# General Hash Function Algorithms
# By Arash Partow - 2000
#
# URL: http://www.partow.net/programming/hashfunctions/index.html
#
# Copyright Notice:
# Free use of this library is permitted under the
# guidelines and in accordance with the MIT License.
# http://www.opensource.org/licenses/MIT
#


COMPILER      = -cc
OPTIONS       = -std=c99 -pedantic -Wall -o
OPTIONS_LIBS  = -std=c99 -pedantic -Wall -c


all: GeneralHashFunctions.o HashTest

GeneralHashFunctions.o: GeneralHashFunctions.c GeneralHashFunctions.h
	$(COMPILER) $(OPTIONS_LIBS) GeneralHashFunctions.c

HashTest: GeneralHashFunctions.c HashTest.c
	$(COMPILER) $(OPTIONS) HashTest HashTest.c GeneralHashFunctions.o

clean:
	rm -f core *.o *.bak *stackdump *#

#
# The End !
#