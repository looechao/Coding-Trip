#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SQUARED1(x) x*x
#define SQUARED2(x) (x*x)
#define SQUARED3(x) (x)*(x)
#define SQUARED4(x) ((x)*(x))

/**×¢ÊÍ**/

int main(void) {
	double ans = 18.0 / SQUARED4(2 + 1);
	printf("%f", ans);
	return 0;
}