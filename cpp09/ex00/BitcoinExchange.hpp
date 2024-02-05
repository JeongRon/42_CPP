#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>

class BitcoinExchange {
 private:
  std::map<std::string, double> data;

  void insertData();

  bool validateDate(std::string& date);
  bool validatePartition(std::string& partition);
  double validateValue(std::string& valueString);
  void printResult(std::string& date, double& value, std::string& line);

 public:
  BitcoinExchange();
  BitcoinExchange(const char* file);
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);

  void fileParsingAndPrinting(const char* fileName);
};

#endif