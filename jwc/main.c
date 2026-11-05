/* TODO: 
 *	Finish flag parsing
 *	Ensure file open and read pattern
 *	Adjust count struct as needed
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

typedef struct {
	unsigned long bytes;
	unsigned long words;
	unsigned long lines;
}Count;

void countStream(FILE* stream, Count* counts) {
	int ch, in_word;
	in_word = 0;

	while ((ch = fgetc(stream)) != EOF) {
		counts->bytes++;

		if (ch == '\n') {
			counts->lines++;
		}

		if (isspace(ch)) {
			in_word = 0;
		} else if (!in_word) {
			in_word = 1;
			counts->words++;
		}
	}
}






int main(int argc, char* argv[]) {
	
	Count total = {0, 0, 0};
	int optind, optopt;







	while((opt = getopt(argc, argv, "l")) != -1) {

		switch (opt) {
			case 'l':
				break;
			default:
				fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
				exit(EXIT_FAILURE);
		}
	}



	exit(EXIT_SUCCESS);
}

