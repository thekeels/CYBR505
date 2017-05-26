#include <stdio.h>
int main(void)
{
	int StudentId, CourseId, LabId;
	StudentId = 1234567;
	CourseId = 505;
	LabId = 2;
	printf("Name:\t\t\tthekeels\n");
	printf("Email:\t\t\tthekeels@email.com\n");
	printf("Student Id:\t\t%009d\n", StudentId);
	printf("Instructor Name:\tSahar Mosleh\n");
	printf("Course:\t\t\tCYBR %d\n", CourseId);
	printf("Lab #:\t\t\t%d", LabId);
	getchar();
	return 0;
}