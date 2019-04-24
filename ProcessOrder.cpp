// ProcessOrder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <../../stringToTimestamp.h>



void readCSV() {
	std::string line;
	std::ifstream stream("c200-e50-r5000.csv");
	while (stream) {
		std::getline(stream, line);

		size_t  index1 = line.find_first_of(',');
		size_t  index2 = line.find_first_of(',', index1 + 1u);
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
	//parseDate("2019-04-29 00:46:24");
	return 1;
}