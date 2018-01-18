#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

std::vector<double> worker(double a[3], double b[3][3]) 
{
	std::vector<double> c;

	for (int i = 0; i < 3; i++) {
		c.push_back(0.0);

		for (int j = 0; j < 3; j++) {
			c.at(i) += a[j] * b[j][i];
		}
	}

	return c;
}

int main(std::vector<double> &row, double a[3], double b[3][3]) 
{
	std::cout << "Working and baking!" << std::endl;
	//for (int i = 0; i < 3; i++) {
	//	row.push_back(0.0);
	//
	//	for (int j = 0; j < 3; j++) {
	//		row.at(i) += a[j] * b[j][i];
	//	}
	//}
}
