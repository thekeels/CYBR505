#include<stdio.h>
int Lab3(void)
{
	float l, h, w, area;
	l = 2;
	h = 3.5;
	w = 6;
	area = l*h*w;
	printf("The area of cube with length of %.1f height of %.1f and width of %.1f is %.1f", l, h, w, area);
	getchar();
	return 0;
}