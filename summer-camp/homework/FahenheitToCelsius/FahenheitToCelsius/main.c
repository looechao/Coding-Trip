#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SCALE_FACTOR (5.0/9.0)    //小心被默认定义成整型
#define FREEZING_POINT 32


/**注释**/

int main(void) {
	int fahrenheit;
	printf("Enter Fahrenheit temprature:");
	scanf("%d", &fahrenheit);
	
	float celsius = SCALE_FACTOR * (fahrenheit - FREEZING_POINT);
	printf("Celsius eqeuivalent:%.1f\n", celsius);
	return 0;
}