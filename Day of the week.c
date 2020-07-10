#define _CRT_SECURE_NO_WARNINGS //Visual Studio에서 오류발생시 무시하는 매크로
#include <stdio.h>;
int isLeap(int year);
int main()
{
	int year, month, day, term;
	int DOM[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char DOW[7][10] = { "MON", "TUS", "WED", "THU", "FRI", "SAT", "SUN" };
	while (1)
	{
		term = 0;
		scanf_s("%d %d %d", &year, &month, &day);
		for (int i = 1900; i < year; i++)
		{
			if (isLeap(i))
				term += 366;
			else
				term += 365;
		}
		for (int j = 1; j < month; j++)
		{
			if (isLeap(year))
			{
				DOM[1] = 29;
				term += DOM[j - 1];
			}
			else
			{
				DOM[1] = 28;
				term += DOM[j - 1];
			}
		}
		term += day - 1;
		printf("%s\n", DOW[term % 7]);
	}
	return 0;
}
int isLeap(int year) //윤년
{
	int num = 0;
	if (year % 400 == 0)
		num = 1;
	else if (year % 100 == 0)
		num = 0;
	else if (year % 4 == 0)
		num = 1;
	return num;
}