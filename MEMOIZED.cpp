
/* *************************** CUT-ROD RECURSIVE ALGORITHM IMPLEMENTATION *************************** */

#include<iostream>
using namespace std;

int COUNT = 0;


int memoized_Cut_Rod_Aux(int p[], int n, int r[])
{
	int q = 0;
	int min_Value = INT_MIN;

	if (r[n] >= 0)
	{
		return r[n];
	}
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		COUNT++;

		for (int i = 0; i < n; ++i)
		{
			int q = p[i] + memoized_Cut_Rod_Aux(p, n - i - 1, r);

			if (q < min_Value)
			{
				min_Value = q;
			}
			r[i] = min_Value;
		}

	}
	return min_Value;

}

int memorized_Cut_Rod(int p[], int n)
{
	int *r = new int[n + 1];

	for (int i = 0; i < n + 1; i++)
	{
		r[i] = INT_MIN;
	}
	//return memoized_Cut_Rod_Aux(p, n, r);
	return memoized_Cut_Rod_Aux(p, n, r);
}



int main()
{
	//int length[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int price[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

	int num;

	cout << "Enter value of num: ";
	cin >> num;

	cout << endl;
	cout << "Profit you may get is: " << memorized_Cut_Rod(price, num) << endl;
	cout << "Number of function calls are: " << COUNT << endl << endl;

	system("pause");
	return 0;
}
