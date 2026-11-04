#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	
	FILE* f = fopen(argv[1], "r");

	if(!f) {
		perror("File opening failed!");
		return EXIT_FAILURE;
	}
	
	int c;
	while ((c = fgetc(f)) != EOF) 
		putchar(c);

		if (ferror(f)) 
			puts("I/O error when reading");
			
		else if (feof(f)) 
			puts("End of file reached successfully!");
		
	

	fclose(f);
	return EXIT_SUCCESS;
}

