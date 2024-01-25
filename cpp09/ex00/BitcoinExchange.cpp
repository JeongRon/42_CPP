#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { insertData(); }

BitcoinExchange::BitcoinExchange(const char* fileName) {
  insertData();
  fileParsingAndPrinting(fileName);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  this->data = other.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    this->data = other.data;
  }
  return *this;
}

void BitcoinExchange::insertData() {
  std::ifstream inputData("data.csv");
  if (!inputData.is_open()) throw std::runtime_error("ERROR: Data File Open");

  bool first_flag = true;
  std::string line;
  while (std::getline(inputData, line)) {
    if (first_flag == false) {
      std::string date = line.substr(0, 10);
      std::string exchangeRateString = line.substr(11);
      double exchangeRate = strtod(exchangeRateString.c_str(), NULL);
      data.push_back(std::pair<std::string, double>(date, exchangeRate));
    } else {
      if (line.compare("date,exchange_rate") == 0) first_flag = false;
    }
  }
  inputData.close();
  //   // TEST
  //   for (std::size_t i = 0; i < data.size(); ++i) {
  //     std::cout << data[i].first << "," << data[i].second << std::endl;
  //   }
}

void BitcoinExchange::fileParsingAndPrinting(const char* fileName) {
  std::ifstream inputFile(fileName);
  if (!inputFile.is_open()) throw std::runtime_error("ERROR: Input File Open");

  bool first_flag = true;
  std::string line;
  while (std::getline(inputFile, line)) {
    if (first_flag == false) {
      // CODE
    } else {
      if (line.compare("date | value") == 0) first_flag = false;
    }
  }
  // file data parsing
  // 한줄씩 line -> data|value ->
  // 형식 체크 (0000-00-00|double)
  // -> date : Month, day
  // -> value : positive, int range
  // 형식 맞으면, 계산 출력
  // data의 날짜랑 맞는 요소 or 가까운 요소 찾기

  inputFile.close();
}