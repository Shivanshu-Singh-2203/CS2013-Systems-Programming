#include <stdio.h>

struct point{
	float x;
	float y;
};

typedef struct point Point; 
struct rectangle {
	float height;
	float breadth;
	Point leftcorner;
};

typedef struct rectangle Rectangle;

int main(){
	Rectangle r;
	Point center;
	scanf("%f %f %f %f", &r.leftcorner.x , &r.leftcorner.y, &r.height, &r.breadth);
	center.x = r.leftcorner.x + r.breadth/2;
	center.y = r.leftcorner.y + r.height/2;
	printf("%.4f %.4f\n", center.x, center.y);

	return 0;	
}
