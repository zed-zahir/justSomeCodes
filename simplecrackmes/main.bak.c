//C(uiI
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <sys/ptrace.h>
 
#define caesar(x) rot(13, x)
#define decaesar(x) rot(13, x)
#define decrypt_rot(x, y) rot((26-x), y)
 
void rot(int c, char *str)
{

	int l = strlen(str);
	const char *alpha[2] = { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
 
	int i;
	for (i = 0; i < l; i++)
	{
		if (!isalpha(str[i]))
			continue;
 
		if (isupper(str[i]))
                        str[i] = alpha[1][((int)(tolower(str[i]) - 'a') + c) % 26];
                else
                        str[i] = alpha[0][((int)(tolower(str[i]) - 'a') + c) % 26];
	}
}
 

struct replace_info {
    int n;
    char *text;
};
 
int compare(const void *a, const void *b)
{
    struct replace_info *x = (struct replace_info *) a;
    struct replace_info *y = (struct replace_info *) b;
    return x->n - y->n;
}
 
void generic_fizz_buzz(int max, struct replace_info *info, int info_length)
{
    int i, it;
    int found_word;
 
    for (i = 1; i < max; ++i) {
        found_word = 0;
 
        /* Assume sorted order of values in the info array */
        for (it = 0; it < info_length; ++it) {
            if (0 == i % info[it].n) {
                printf("%s", info[it].text);
                found_word = 1;
            }
        }
 
        if (0 == found_word)
            printf("%d", i);
 
        printf("\n");
    }
}
 
int obfuscation(void)
{
    struct replace_info info[3] = {
        {5, "Buzz"},
        {7, "Baxx"},
        {3, "Fizz"}
    };
 
    /* Sort information array */
    qsort(info, 3, sizeof(struct replace_info), compare);
 
    /* Print output for generic FizzBuzz */
    generic_fizz_buzz(20, info, 3);
    return 0;
}

#define mat_elem(a, y, x, n) (a + ((y) * (n) + (x)))
 
void swap_row(double *a, double *b, int r1, int r2, int n)
{
	double tmp, *p1, *p2;
	int i;
 
	if (r1 == r2) return;
	for (i = 0; i < n; i++) {
		p1 = mat_elem(a, r1, i, n);
		p2 = mat_elem(a, r2, i, n);
		tmp = *p1, *p1 = *p2, *p2 = tmp;
	}
	tmp = b[r1], b[r1] = b[r2], b[r2] = tmp;
}
 
void gauss_eliminate(double *a, double *b, double *x, int n)
{
#define A(y, x) (*mat_elem(a, y, x, n))
	int i, j, col, row, max_row,dia;
	double max, tmp;
 
	for (dia = 0; dia < n; dia++) {
		max_row = dia, max = A(dia, dia);
 
		for (row = dia + 1; row < n; row++)
			if ((tmp = fabs(A(row, dia))) > max)
				max_row = row, max = tmp;
 
		swap_row(a, b, dia, max_row, n);
 
		for (row = dia + 1; row < n; row++) {
			tmp = A(row, dia) / A(dia, dia);
			for (col = dia+1; col < n; col++)
				A(row, col) -= tmp * A(dia, col);
			A(row, dia) = 0;
			b[row] -= tmp * b[dia];
		}
	}
	for (row = n - 1; row >= 0; row--) {
		tmp = b[row];
		for (j = n - 1; j > row; j--)
			tmp -= x[j] * A(row, j);
		x[row] = tmp / A(row, row);
	}
#undef A
}
 
int cryptSerial(void)
{
	double a[] = {
		1.00, 0.00, 0.00,  0.00,  0.00, 0.00,
		1.00, 0.63, 0.39,  0.25,  0.16, 0.10,
		1.00, 1.26, 1.58,  1.98,  2.49, 3.13,
		1.00, 1.88, 3.55,  6.70, 12.62, 23.80,
		1.00, 2.51, 6.32, 15.88, 39.90, 100.28,
		1.00, 3.14, 9.87, 31.01, 97.41, 306.02
	};
	double b[] = { -0.01, 0.61, 0.91, 0.99, 0.60, 0.02 };
	double x[6];
	int i;
 
	gauss_eliminate(a, b, x, 6);
 
	for (i = 0; i < 6; i++)
		printf("%g\n", x[i]);
 
	return 0;
}

int checkSerial()
{
  char is_open[100] = { 0 };
  int pass, door;
 
  /* do the 100 passes */
  for (pass = 0; pass < 100; ++pass)
    for (door = pass; door < 100; door += pass+1)
      is_open[door] = !is_open[door];
 
  /* output the result */
  for (door = 0; door < 100; ++door)
    printf("door #%d is %s.\n", door+1, (is_open[door]? "open" : "closed"));
 
  return 0;
}

int main( int argc, char **argv ) {
	printf("***********************\n");
	printf("**      rules:       **\n");
	printf("***********************\n");
	printf("\n");
	printf("* do not bruteforce\n");
	printf("* do not patch, find instead the serial.\n");
	printf("\n");
	char str[] = "This is a top secret text message!";
 

	unsigned char idtr[6];
	asm ("sidt %0" : "=m" (idtr));
	if(0xff==idtr[5]) {
		printf("VMware detected\n");
		exit(1);
	}


	caesar(str);
	decaesar(str);
 
	char letters[19] = "AHi23DEADBEEFCOFFEE";
	char input[19];
	char output[19];

	printf( "enter the passphrase: " );
	scanf( "%s", input );
	
	if (ptrace(PTRACE_TRACEME, 0) < 0) {
		printf("This process is being debugged!!!\n");
		exit(1);
	}

	output[0] = (int)letters[0] ^ 2; 
	output[1] = (int)letters[3] - 10; 
	output[2] = (int)letters[2] + 12; 
	output[3] = (int)letters[2];
	output[4] = (int)letters[1] + 1;
	for( int i = 5; i < 19; i++ )
		output[i] = (int)letters[i] - 0x01;

	if( !strcmp( output, input ) )
		printf( "you succeed!!\n" );
	else
		printf( "try again\n" );

	return 0;
}
