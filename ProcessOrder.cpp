// ProcessOrder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>


void readCSV() {

	std::string line;
	std::ifstream stream("c200-e50-r5000.csv");
	while (stream) {
		std::getline(stream, line);

		int index1 = line.find_first_of(',');
		int index2 = line.find_first_of(',', index1 + 1);
		if (index1 < 0 || index2 < 0) {
			break;
		}
		std::string caseID = line.substr(0, index1);
		std::string eventID = line.substr(index1 + 1, index2 - index1 - 1);
		std::string timestamp = line.substr(index2 + 1);
	}




}


int main()
{
	readCSV();
}