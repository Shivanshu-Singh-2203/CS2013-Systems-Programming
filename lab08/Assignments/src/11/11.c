#include <stdio.h>
//TODO: Add appropriate headers for dynamic memory allocation and string ops
#include<stdlib.h>
#include <string.h>

#define SIZE 50

//TODO: Define struct Student
typedef struct student {
	char name[80];
	int age;
	long roll;
	int marks;
} Student;

Student copyStudent(const Student s)
{
	Student temp;
	temp.age = s.age;
	temp.roll = s.roll + 100000;
	temp.marks = s.marks;
	return temp;
}

//TODO: Complete the function
// void print_details(//TODO: Add appropriate arguments)
void print_details(Student *s){
	printf("Name: %s\nAge: %d\nRoll: %ld\nMarks: %d\n", s->name, s->age, s->roll, s->marks);
}

int main()
{
	Student s;

	//Read data 
	scanf("%s", s.name);
	scanf("%d", &s.age);
	scanf("%ld", &s.roll);
	scanf("%d", &s.marks);

	//Do not add/modify anything about this line
	//TODO: Complete the code
	Student sh = copyStudent(s);;
	
	strcpy(sh.name, s.name);
		
	print_details(&sh);	
        //TODO DO NOT FORGET TO FREE ANY MEMORY ALLOCATED USING malloc() using
        // free()
	//Do not add/modify anything below this line
	return 0;
}

