#include "BitcointExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>


//skip spaces
static std::string trim(const std::string &s) {
	size_t a = s.find_first_not_of(" \t\r\n");
	if (a == std::string::npos) return "";
	size_t b = s.find_last_not_of(" \t\r\n");
	return s.substr(a, b - a + 1);
}

static bool isDigits(const std::string &s) {
	for (size_t i = 0; i < s.size(); ++i)
		if (!std::isdigit(s[i])) return false;
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	std::string y = date.substr(0,4);
	std::string m = date.substr(5,2);
	std::string d = date.substr(8,2);
	if (!isDigits(y) || !isDigits(m) || !isDigits(d)) return false;
	std::istringstream sy(y);
	std::istringstream sm(m);
	std::istringstream sd(d);
	int yi = 0;
	int mi = 0;
	int di = 0;
	sy >> yi;
	sm >> mi;
	sd >> di;
	if (!sy || !sm || !sd) return false;
	if (mi < 1 || mi > 12) return false;
	if (di < 1 || di > 31) return false;
	return true;
}


//parse database
void BitcoinExchange::loadDatabase(const std::string& dbFile) {
	std::ifstream ifs(dbFile.c_str());
	if (!ifs) {
		std::cerr << "Error: could not open database." << std::endl;
		return;
	}
	std::string line;
	// skip header
	if (!std::getline(ifs, line)) return;
	while (std::getline(ifs, line)) {
		if (line.empty()) continue;
		std::istringstream ss(line);
		std::string date, rateStr;
		if (!std::getline(ss, date, ',')) continue;
		if (!std::getline(ss, rateStr)) continue;
		date = trim(date);
		rateStr = trim(rateStr);
		try {
			std::istringstream rateStream(rateStr);
			double rate = 0.0;
			char extra = '\0';
			rateStream >> rate;
			if (!rateStream || rateStream >> extra) continue;
			data[date] = rate;
		} catch (...) {
			continue;
		}
	}
}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
	loadDatabase(dbFile);
}

bool BitcoinExchange::getRateForDate(const std::string& date, double &rate) const {
	if (!isValidDate(date)) return false;
	std::map<std::string,double>::const_iterator it = data.find(date);
	if (it != data.end()) {
		rate = it->second;
		return true;
	}
	// find closest lower date
	it = data.lower_bound(date);
	if (it == data.begin()) {
		// no lower date
		return false;
	}
	if (it == data.end() || it->first > date) {
		--it;
	}
	rate = it->second;
	return true;
}

