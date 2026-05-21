#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange(const std::string& dbFile);
	bool getRateForDate(const std::string& date, double &rate) const;
	static bool isValidDate(const std::string& date);
private:
	std::map<std::string, double> data;
	void loadDatabase(const std::string& dbFile);
};

#endif

