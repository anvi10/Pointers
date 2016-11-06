
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char ** argv) {
	int c;
	int lines=0;

	printf("Program that counts lines.\n");
    	// Add your implementation here
	if (argc < 2) {
		printf("Usage: toascii hamlet\n");
		exit(1);
	}
	char * fileName = argv[1];
	FILE * fd = fopen(fileName, "r");

	if (fd == NULL) {
		printf( "Could not open file %s\n ", fileName );
		exit(1);
	}

	while((c=fgetc(fd))  != -1) {
			if (c == '\n')
			lines++;
		c++;
	}

	printf("Total lines: %d\n", lines);
	exit(0);
	fclose(fd);
}
