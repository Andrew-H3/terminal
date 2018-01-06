#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *result;
	char command[80];
	char lines[80];
	char username[20];
	char *shellType;
	shellType = getenv("SHELL");
	result = popen("whoami", "r");
	fgets(lines, 80, result);
	sscanf(lines, "%s", username);
	printf("Running on top of %s as %s\n", shellType, username);
	while(1){
	printf("%s>", username);
	fgets(command, 80, stdin);
	if (strncmp(command, "exit", 4) == 0) {return 0;}
	result = popen(command, "r");
	while(fgets(lines, 80, result)){
		printf("%s", lines);
	}
	pclose(result);
}
	return 0;
}
