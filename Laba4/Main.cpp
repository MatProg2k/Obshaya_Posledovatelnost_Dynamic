#include <string>
#include <iostream>
#include <random>
#include <time.h>
#include <fstream>

#include "Task.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE,"rus");

	string string_1 = "ALDC";
	string string_2 = "LADCMI";

	cout << "Первая строка = " << string_1 << endl;
	cout << "Вторая строка = " << string_2 << endl;
	clock_t startRec = clock();
	cout << "Длина подпоследовательности = " << maxSubLenghtcsDin(string_1, string_1.length(), string_2, string_2.length()) << endl;
	clock_t stopRec = clock();
	std::cout << "Время выполнения: " << stopRec - startRec << std::endl;
	
	system("pause");
}