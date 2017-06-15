#pragma once
#include <string>
#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

enum Orientation { TOP, LEFT, LEFTTOP };

int maxSubLenghtcsDin(string first, int lenght_1, string second, int lenght_2)
{
	int *resultMatric = new int[(lenght_1 + 1)*(lenght_2 + 1)];
	int *orientation = new int[(lenght_1 + 1)*(lenght_2 + 1)];

	for (int i = 0; i < (lenght_1 + 1)*(lenght_2 + 1); i++)
	{
		resultMatric[i] = 0;
	}

	for (int i = 0; i < (lenght_1 + 1)*(lenght_2 + 1); i++)
	{
		orientation[i] = TOP;
	}

	for (int i = 1; i < lenght_1 + 1; i++)
	{
		for (int j = 1; j < lenght_2 + 1; j++)
		{
			if (first[i - 1] == second[j - 1])
			{
				resultMatric[i * (lenght_2 + 1) + j] = resultMatric[(i - 1) * (lenght_2 + 1) + (j - 1)] + 1;
				orientation[i * (lenght_2 + 1) + j] = LEFTTOP;
			}
			else if (resultMatric[(i - 1) * (lenght_2 + 1) + j] >= resultMatric[i * (lenght_2 + 1) + (j - 1)])
			{
				resultMatric[i * (lenght_2 + 1) + j] = resultMatric[(i - 1) * (lenght_2 + 1) + j];
				orientation[i * (lenght_2 + 1) + j] = TOP;
			}
			else
			{
				resultMatric[i * (lenght_2 + 1) + j] = resultMatric[i * (lenght_2 + 1) + (j - 1)];
				orientation[i * (lenght_2 + 1) + j] = LEFT;
			}
		}
	}

	cout << "Result: " << resultMatric[lenght_1 * (lenght_2 + 1) + lenght_2] << endl;

	cout << "Weight of substring:" << endl << endl;
	for (int i = 1; i < lenght_1 + 1; i++)
	{
		for (int j = 1; j < lenght_2 + 1; j++)
		{
			cout << resultMatric[i * (lenght_2 + 1) + j] << " ";
		}
		cout << endl;
	}

	cout << "Orientation of substring:" << endl << endl;
	for (int i = 1; i < lenght_1 + 1; i++)
	{
		for (int j = 1; j < lenght_2 + 1; j++)
		{
			if (orientation[i * (lenght_2 + 1) + j] == TOP)
			{
				cout << "T" << " ";
			}
			else if (orientation[i * (lenght_2 + 1) + j] == LEFT)
			{
				cout << "L" << " ";
			}
			else if (orientation[i * (lenght_2 + 1) + j] == LEFTTOP)
			{
				cout << "N" << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	return resultMatric[lenght_1 * (lenght_2 + 1) + lenght_2];
}