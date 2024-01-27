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

  std::string line;
  std::getline(inputData, line);
  while (std::getline(inputData, line)) {
    std::string date = line.substr(0, 10);
    std::string exchangeRateString = line.substr(11);
    double exchangeRate = strtod(exchangeRateString.c_str(), NULL);
    data.push_back(std::pair<std::string, double>(date, exchangeRate));
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

  std::string line;
  std::getline(inputFile, line);
  while (std::getline(inputFile, line)) {
    if (line.length() < 14)
      std::cerr << "Error: bad input => " << line << std::endl;
    else {
      std::string date = line.substr(0, 10);
      std::string partition = line.substr(10, 3);
      std::string valueString = line.substr(13);
      // char* endptr;
      // strtod(valueString.c_str(), &endptr);

      // TEST CODE
      // std::cout << "date : " << date << std::endl;
      // std::cout << "partition : " << partition << std::endl;
      // std::cout << "valueString : " << valueString << std::endl;
      // if (!endptr)
      //   std::cout << "value : Not a Number" << std::endl;
      // else
      //   std::cout << "value : " << value << std::endl;

      if (validateDate(date) == false) {
        std::cerr << "Error: invalid Date " << date << std::endl;
        continue;
      }
      if (validatePartition(partition) == false) {
        std::cerr << "Error: invalid Partition " << date << std::endl;
        continue;
      }
      double value = validateValue(valueString);
      if (value == -1) {
        continue;
      }
      printResult(date, value);
    }
    // std::cout << "-----------------------" << std::endl;
  }
  inputFile.close();
}

bool BitcoinExchange::validateDate(std::string& date) {
  for (size_t i = 0; i < date.length(); i++) {
    if (i == 4 || i == 7) {
      if (date[i] != '-') return false;
    } else {
      if (!('0' <= date[i] && date[i] <= '9')) return false;
    }
  }
  int year = atoi(date.substr(0, 4).c_str());
  int month = atoi(date.substr(5, 2).c_str());
  int day = atoi(date.substr(8, 2).c_str());

  bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  if (!(1 <= month && month <= 12)) return false;

  int maxDay = 31;
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    maxDay = 30;
  } else if (month == 2) {
    maxDay = isLeapYear ? 29 : 28;
  }
  if (!(1 <= day && day <= maxDay)) return false;

  return true;
}

bool BitcoinExchange::validatePartition(std::string& partition) {
  if (partition[0] == ' ' && partition[1] == '|' && partition[2] == ' ')
    return true;
  return false;
}

double BitcoinExchange::validateValue(std::string& valueString) {
  char* endptr;
  double num = strtod(valueString.c_str(), &endptr);
  if (*endptr != '\0') {
    std::cerr << "Error: invalid value." << std::endl;
    return -1;
  }
  if (num < 0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return -1;
  }
  if (num > 1000) {
    std::cerr << "Error: too large a number." << std::endl;
    return -1;
  }
  return num;
  // // TEST CODE
  // std::cout << "num: " << num << std::endl;
  // std::cout << "endptr: " << endptr << std::endl;
}

void BitcoinExchange::printResult(std::string& date, double value) {
  double result = 0.0;
  std::vector<std::pair<std::string, double> >::iterator it;
  for (it = data.begin(); it != data.end(); ++it) {
    if (it->first == date) {
      result = it->second * value;
      std::cout << it->first << " => " << value << " = " << result << std::endl;
      return;
    }
  }
}