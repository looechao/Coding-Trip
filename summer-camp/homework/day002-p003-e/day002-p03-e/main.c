#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**×¢ÊÍ**/

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else return gcd(b, a % b);
}

int main(void) {
	int numerator1,denominator1;
	printf("Enter first fraction:");
	scanf("%d/%d", &numerator1, &denominator1);

	int numerator2,denominator2;
	printf("Enter second fraction:");
	scanf("%d/%d", &numerator2, &denominator2);

	int resualt_numerator = numerator1 * denominator2+numerator2*denominator1;
	int resualt_denominator = denominator1 * denominator2;
	
	int divisor = gcd(resualt_numerator, resualt_denominator);
	resualt_denominator/=divisor;
	resualt_numerator/=divisor;
	if (resualt_denominator == 1) {
		printf("%d", resualt_numerator);
	}else
		printf("%d/%d", resualt_numerator, resualt_denominator);
	return 0;
}