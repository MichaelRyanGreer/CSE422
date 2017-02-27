// Memory Allocator by Thomas Kelly and Michael Greer


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

#include "mem_1.h"

static char * heap_base; // points to the base of the heap
static char * heap_last; // points to the last byte of the heap
static char * heap_max;  // points to the maximum address of the heap

int Mem_Init(int size) {
	heap_base = (char *)sbrk(0);
	heap_last = heap_base;
	sbrk(size);
	heap_max = heap_base + size;

	size_t header = size-2; // take out the space of the header/footer blocks
	header = (header << 1) & ~(size_t(1));

	*((size_t*)heap_base) = header;
	*((size_t*)heap_max) = header;
	
}

void * Mem_Alloc(int size, int policy) {
	
}

int Mem_Free(void *ptr) {

}

void Mem_Dump() {

}

void coalesce(void * current) {

}
