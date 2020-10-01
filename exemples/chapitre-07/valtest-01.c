#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *buffer = NULL;

	if (argc < 2) {
		fprintf(stderr, "usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(strlen(argv[1]));
	if (buffer == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	strcpy(buffer, argv[1]);

	fprintf(stdout, "---> %s\n", buffer);

	free(buffer);
	buffer = NULL;

	return 0;
}

