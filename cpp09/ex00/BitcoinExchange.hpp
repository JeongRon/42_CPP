#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

class BitcoinExchange {
 private:
  std::vector<std::pair<std::string, double> > data;

  void insertData();

 public:
  BitcoinExchange();
  BitcoinExchange(const char* file);
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);

  void fileParsingAndPrinting(const char* fileName);
};

#endif