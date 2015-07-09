/* Alternate version of 'binsearch' function */
#include <stdio.h>

int binsearch2(int x, int v[], int n);
int binsearch(int x, int v[], int n);

int main()
{
	int vec[10] = {1, 2, 3, 4, 5, 6, 7};

	printf("%d\n", binsearch2(8, vec, 10));
	printf("%d", binsearch(8, vec, 10));
	return 0;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	mid = (low + high)/2;
	while(low <= high && v[mid] != x) // Forces the loop to iterate until 
	{											 // it finds (or not) the correct value
		mid = (low + high)/2;			  
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if(x == v[mid])
		return mid; 
	return -1;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else	/* Found match */
			return mid;
	}
	return -1; /* No match */
}
