#include <stdio.h>
#include "incbin.h"

INCBIN(array, "array.bin", .data, 16);

int main(void) {
	int i;
	unsigned int sum;

	printf("address = %p\n", ((char*)&array));
	printf("array size = %d\n", SIZEOF(array));

	for(sum = 0, i = 0; i<SIZEOF(array); i++) {
		sum += ARRAYOF(array)[i];
	}
	printf("sum = %d\n", sum);

}
