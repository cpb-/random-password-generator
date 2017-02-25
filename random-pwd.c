/// \file random-pwd.c
///
/// \brief A very simple command line random password generator.
///
/// \author Christophe Blaess <christophe.blaess@logilin.fr>
///
/// \licence GPLv2
///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// The set of allowed characters:
char *char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

int main(int argc, char * argv[])
{
	struct timespec ts;
	int length = 8; // The password defaults to 8 characters.
	int i;

	// We accept only one parameter: the length of the password.
	if (argc > 1) {
		if (sscanf(argv[1], "%d", &length) != 1) {
			fprintf(stderr, "usage: %s [length]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	// Initialize the random generator seed with the current nanoseconds.
	if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
		perror("clock_gettime()");
		exit(EXIT_FAILURE);
	}
	srand(ts.tv_nsec);

	for (i = 0; i < length; i ++)
		fprintf(stdout, "%c", table[rand() % strlen(table)]);

	fprintf(stdout, "\n");

	return EXIT_SUCCESS;
}
