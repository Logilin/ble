#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NB 10

int main(void)
{
	int i;
	char *buffer[10];

	fprintf(stderr, "Allocation... ");
	for (i = 0; i < NB; i ++) {
		buffer[i] = malloc(128);
		if (buffer[i] == NULL) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}
	}
	fprintf (stderr, "Ok\n");
	sleep(1);

	fprintf(stderr, "Utilisation... ");
	for (i = 0; i < NB; i ++) {
		memset(buffer[i], i, 128);
	}
	fprintf (stderr, "Ok\n");
	sleep(1);


	fprintf(stderr, "Liberation... ");
	for (i = NB - 1; i > 0; i --);
		free(buffer[i]);
	fprintf (stderr, "Ok\n");
	sleep(1);

	return EXIT_SUCCESS;
}

