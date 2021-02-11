#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

	if(argc < 2) {
		printf("usage: %s <keyfile>\n", argv[0]);
		exit(1);
	}

/* declare array */
int frequency[26];
int ch;
FILE* txt_file = fopen (argv[1], "rt");
char freq[26];
/* init the freq table: */
for (ch = 0; ch < 26; ch++)
    frequency[ch] = 0;
 
while (1) {
    ch = fgetc(txt_file);
    if (ch == EOF) break; /* end of file or read error.  EOF is typically -1 */
 
    /* assuming ASCII; "letters" means "a to z" */
    if ('a' <= ch && ch <= 'z')      /* lower case */
        frequency[ch-'a']++;
    else if ('A' <= ch && ch <= 'Z') /* upper case */
        frequency[ch-'A']++;
}

	printf("the generated key is: ");
	for(int i = 0; i < 26; i++) {
		printf("%d", frequency[i]);
		freq[i] = frequency[i] + '0';
	}
	freq[26] = '\0';
	printf("\n");

	if( !strcmp(freq, "01234567890123456789012345")) {
		printf("you succeed!!\n");
	} else {
		printf("you failed!!\n");
	}
}
