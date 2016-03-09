/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder,2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int toint(char *str, int i, int j)
{
	int d, sum=0,n;
	if ((j - i) == 1)
		n = 100;
	else
		n = 10000;
	for (; i <= j; i++)
	{
		d = str[i] - 48;
		sum += d*(n / 10);
		n = n / 10;
	}
	return sum;
}
int isleap(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return 0;
			else
				return 1;
		}
		else
			return 0;
	}
	else
		return 1;

}

int isOlder(char *dob1, char *dob2) {
	int date1, date2, month1, month2, year1, year2;
	date1 = toint(dob1, 0, 1);
	date2 = toint(dob2, 0, 1);
	month1 = toint(dob1, 3, 4);
	month2= toint(dob2, 3, 4);
	year1 = toint(dob1, 6, 9);
	year2= toint(dob2, 6, 9);
	if (date1 <= 0 || date2 <= 0 || date2 > 31 || date1 > 31)
		return -1;
	if (month1 <= 0 || month2 <= 0 || month1 > 12 || month2 > 12)
		return -1;
	if (month1 == 2 || month2 == 2)
	{
		if (date1 == 29)
		{
			if (isleap(year1))
				return -1;
		}
		else if (date2 == 29)
		{
			if (isleap(year2))
				return -1;
		}
	}
	if (year1 > year2)
		return 2;
	else if (year1 < year2)
		return 1;
	else
	{
		if (month1 < month2)
			return 1;
		else if (month1>month2)
			return 2;
		else if (month1 == month2)
		{
			if (date1 < date2)
				return 1;
			else if (date1>date2)
				return 2;
			else
				return 0;
		}
	}
}

	

	
