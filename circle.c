#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
   //Declare the variables to store radius, area, diameter
   double radius, area, diameter;

   //Request the user to enter the radius of the circle
   printf("Enter the radius of the circle:");
   scanf("%lf", &radius);

   //Calculates the area and diameter of the circle
    area = 3.142 * radius * radius;
    diameter = 2 * radius;

   //Displays the area and diameter of the circle
   printf("The area of the circle is: %lf\n", area);
   printf("The diameter of the circle is: %lf\n", diameter);

return 0;


}