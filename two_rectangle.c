#include <stdio.h>

//定义矩形 
typedef struct  
{
	double x_min;
	double x_max;
	double y_min;
	double y_max; 
} rectangle_def;

//读取矩形参数 
int get_rectangle(rectangle_def *my_region) 
{
	int result = 0;
	while (1) 
	{
		printf("Please input coordinates of the rectangle: x_min x_max y_min y_max\n");
		result = scanf("%lf %lf %lf %lf", 
						&(my_region->x_min), &(my_region->x_max), &(my_region->y_min), &(my_region->y_max));
		if (4 != result)
		{
			printf("Illegal input format!\n");
			printf("Input format: x_min x_max y_min y_max\n");
			continue;
		}		
		else if (my_region->x_min > my_region->x_max || my_region->y_min > my_region->y_max)
		{
			printf("Illegal coordinates\n");
			printf("Input format: x_min x_max y_min y_max\n");
			continue;
		}
		else
			break;
	};
	
	return 0;
}

//判断是否由交集：1有交集，非1无交集 
int intersect(rectangle_def *region1, rectangle_def *region2)
{
	if (region1->x_max < region2->x_min || 
		region2->x_max < region1->x_min ||
		region1->y_max < region2->y_min ||
		region1->y_max < region2->y_min)
		return 0;
	else
		return 1;
}

int get_area(rectangle_def *region1, rectangle_def *region2, double *area)
{
	double x_min = 0.0, x_max = 0.0, y_min = 0.0, y_max = 0.0;
	x_min = region1->x_min > region2->x_min ? region1->x_min : region2->x_min;
	x_max = region1->x_max > region2->x_max ? region2->x_max : region1->x_max;
	y_min = region1->y_min > region2->y_min ? region1->y_min : region2->y_min;
	y_max = region1->y_max > region2->y_max ? region2->y_max : region1->y_max;
	
	*area = (x_max - x_min) * (y_max - y_min);
	
	return 0;
}


int main(void)
{
	int result = 0;
	double area = 0.0;
	rectangle_def	region1 = { 0 };
	rectangle_def	region2 = { 0 };
	
	printf("This program is used to calculate the intersect area of two rectangles！\n");
	
	printf("Information of rectangle1...\n");
	result = get_rectangle(&region1);
	if (0 != result) 
	{
		printf("Get rectangle1 failed!\n");
		return 1;
	}
	printf("rectangle1's coordinates: x_min=%lf, x_max=%lf, y_min=%lf, y_max=%lf\n",
			region1.x_min, region1.x_max, region1.y_min, region1.y_max);
			
	printf("Information of rectangle1...\n");	
	result = get_rectangle(&region2);
	if (0 != result)
	{
		printf("Get rectangle2 failed!\n");
		return 1;
	}
	printf("rectangle1's coordinates: x_min=%lf, x_max=%lf, y_min=%lf, y_max=%lf\n",
			region1.x_min, region1.x_max, region1.y_min, region1.y_max);			
	
	result = intersect(&region1, &region2);
	if (1 != result)
	{
		printf("region1 and region2 have no intersection! So the intersection area=0\n");
		return 0;
	}
	
	result = get_area(&region1, &region2, &area);
	if (0 != result)
	{
		printf("An error has occured when calculating the area!\n");
		return 1;
	} 
	
	printf("The intersection area is %lf\n", area);
	
	return 0;
}
