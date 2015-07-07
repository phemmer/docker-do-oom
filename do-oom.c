#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define malloc_size 1024 * 1024
#define print_interval 100
#define num_chunks 20 * 1024
 
int main() {
	char *chunks[num_chunks];
	char *chunk;
	int i;
 
	for (i = 0; i < num_chunks; i++) {
		chunk = (char *) malloc(malloc_size);
		if (chunk == NULL) {
			printf("malloc failed\n");
			return;
		}
		chunks[i] = chunk;
	}

	printf("mallocs complete\n");

	for (i = 0; i < num_chunks; i++) {
		if (i % print_interval == 0) {
			printf("Used %lld bytes\n", i * malloc_size);
		}
		memset(chunks[i], 'x', malloc_size);
	}

	printf("memsets complete\n");
}
