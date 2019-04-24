// ProcessOrder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <../../stringToTimestamp.h>
#include<ctime>
#include <vector>

void readCSV(std::string path) {
	std::string line;
	std::ifstream stream(path);
	std::vector<int> caseIDs;
	std::vector<int> eventIDs;
	std::vector<int> timestamps;

	bool headersParsed = false;
	while (stream) {
		std::getline(stream, line);

		size_t  index1 = line.find_first_of(',');
		size_t  index2 = line.find_first_of(',', index1 + 1);
		if (index1 < 0 || index2 < 0) {
			break;
		}
		std::string caseIDStr = line.substr(0, index1);
		std::string eventIDStr = line.substr(index1 + 1, index2 - index1 - 1);
		std::string timestampStr = line.substr(index2 + 1);
		if (headersParsed && line.size() > 0) {
			caseIDs.push_back(std::stoi(caseIDStr));
			eventIDs.push_back(std::stoi(eventIDStr));
			time_t timestamp = stringToTimestamp(timestampStr);
			timestamps.push_back(timestamp);
		}
		headersParsed = true;

	}
}

int main()
{
	std::string path = "c200-e50-r5000.csv";
	readCSV(path);
	return 0;
}