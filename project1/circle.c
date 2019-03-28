//Name: circle.c
//Purpose: Finding the dimensions of a circle in a square given only the radius
//Author: Chris Diewtragulchai

#include <stdio.h>
#define PI 3.14f

int main(void)
{
	int radius, diameter, square_perimeter, square_area;
	float circumference, circle_area, area_difference;
	
    printf("This program computes values related to an inscribed circle.\n");
	printf("Enter the value of the radius:	");
	scanf("%d",	&radius);
	
	diameter = radius * 2;
	printf("The diameter of the circle is: %d\n", diameter);

	circumference = 2 * PI * radius;
	printf("The circumference of the circles is: %.03f\n", circumference);

	circle_area = PI * (radius * radius);
	printf("The area of the circle is: %.03f\n", circle_area);

	square_perimeter = diameter * 4;
	printf("The perimeter of the square is: %d\n", square_perimeter);

	square_area = diameter * diameter;
	printf("The area of the square is: %d\n", square_area);	

	area_difference = square_area - circle_area;
	printf("The difference between the area of the square and the circle is: %.03f\n", area_difference);

	return 0;
} 