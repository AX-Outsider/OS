#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

	int error;
	printf("Real ID: %d\n", getuid());
	printf("Effective ID: %d\n", geteuid());

	FILE* in = fopen("secret", "r");
	if (in == NULL) {
		perror("Can't open FILE");
	}

	error = fclose(in);
	if (error == EOF){
		perror("Can't close FILE");
	}

	seteuid(getuid());
	printf("Real ID: %d\n", getuid());
	printf("Effective ID: %d\n", geteuid());

	in = fopen("secret", "r");
	if (in == NULL) {
		perror("Can't open FILE");
	}

	error = fclose(in);
	if (error == EOF){
		perror("Can't close FILE");
	}

	return 0;
}
