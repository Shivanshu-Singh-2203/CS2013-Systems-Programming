#include <stdio.h>

// Define structures Rectangle and Point
//TODO: Complete the code


struct point {
	float x ;
	float y ;
};

typedef struct point Point;

struct rectangle {
	float height;
	float length;
	Point bottom;
};

typedef struct rectangle Rectangle;


Point FindCenter(const Rectangle r){
	float y_displacement = r.height/2;
	float x_displacement = r.length/2;
	Point ce;
	ce.x = r.bottom.x + x_displacement;
	ce.y= r.bottom.y  + y_displacement;
	return ce;
}


int main()
{
	Point corner_bl, center;
	float height, width;

	scanf("%f %f", &corner_bl.x, &corner_bl.y);
	scanf("%f %f", &height, &width);
	
	Rectangle r = {height, width, corner_bl};
	center = FindCenter(r);

	printf("%0.4f %0.4f\n", center.x, center.y);


	//TODO: Complete the code
	//Do not add/modify anything below this line
	return 0;
}

