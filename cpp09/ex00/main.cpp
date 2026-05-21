#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include "BitcointExchange.hpp"

static std::string trim(const std::string &s) {
	size_t a = s.find_first_not_of(" \t\r\n");
	if (a == std::string::npos) return "";
	size_t b = s.find_last_not_of(" \t\r\n");
	return s.substr(a, b - a + 1);
}

static bool isNumber(const std::string &s, double &out) {
	std::string t = s;
	if (t.empty()) return false;
	try {
		std::istringstream iss(t);
		char extra = '\0';
		iss >> out;
		if (!iss || iss >> extra) return false;
	} catch (...) {
		return false;
	}
	return true;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::ifstream ifs(argv[1]);
	if (!ifs) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange db("data.csv");

	std::string line;
	bool first = true;
	while (std::getline(ifs, line)) {
		if (line.empty()) continue;
		// skip header
		if (first) {
			first = false;
			std::string low = line;
			for (size_t i = 0; i < low.size(); ++i)
				low[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(low[i])));
			if (low.find("date") != std::string::npos && low.find("value") != std::string::npos)
				continue;
		}
		// Expect format: date | value
		size_t bar = line.find('|');
		if (bar == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, bar));
		std::string valueStr = trim(line.substr(bar + 1));

		double value;
		if (!BitcoinExchange::isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!isNumber(valueStr, value)) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate;
		if (!db.getRateForDate(date, rate)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		double result = value * rate;
		std::cout << date << " => " << valueStr << " = " << result << std::endl;
	}

	return 0;
}
