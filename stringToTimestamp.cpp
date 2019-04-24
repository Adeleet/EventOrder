#include<string>
#include<ctime>
#include <iostream>
time_t stringToTimestamp(std::string date) {
	/* Converts string to time_t number representing unix timestamp
	Parameter date should have the format: 'YYYY-mm-dd HH:mm:ss'
	*/
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));
	int hour = std::stoi(date.substr(11, 2));
	int minute = std::stoi(date.substr(14, 2));
	int second = std::stoi(date.substr(17, 2));

	struct tm t;
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day - 1;
	t.tm_hour = hour;
	t.tm_min = minute;
	t.tm_sec = second;
	time_t timestamp = mktime(&t);
	return timestamp;
}