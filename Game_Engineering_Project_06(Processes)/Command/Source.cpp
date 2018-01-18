#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>

void coordinator() 
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	CreateProcess("Worker/x64/Release/Game_Engineering_Project.exe", NULL, NULL, NULL, false, 0, NULL, NULL, &si, &pi);

	////matrices
	//double a[3][3] = { 3, 1, 2, 
	//				   6, 5, 1, 
	//				   4, 0, 1 };
	//
	//double b[3][3] = { 5, 3, 2, 
	//				   0, 8, 3,
	//				   4, 1, 2 };
	//
	//double c[3][3];
	//
	//std::vector<double> row;
	//
	////std::string 
	//
	//for (int i = 0; i < 3; i++) 
	//{
	//	CreateProcess("C:/Users/pixir/Desktop/College Stuff/GamesEngineering2/Game_Engineering_Project_06(Processes)/Worker/x64/Release/Game_Engineering_Project.exe", a, NULL, NULL, false, 0, NULL, NULL, &si, &pi);
	//	//row = worker(a[i], b);
	//	
	//	for (int j = 0; j < 3; j++) {
	//		c[i][j] = row.at(j);
	//
	//		std::cout << c[i][j] << " ";
	//	}
	//
	//	std::cout << std::endl;
	//
	//	row.clear();
	//}
}

int main() 
{
	coordinator();

	system("PAUSE");

	return 0;
}