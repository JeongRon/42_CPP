#include <fstream>
#include <iostream>
#include <string>

// line에서 s1문자열을 s2문자열로 바꿔서 리턴해주는 함수
std::string ft_replace(std::string line, std::string s1, std::string s2) {
  int pos = 0;
  std::string replaceLine = "";

  size_t index;
  while (true) {
    index = line.find(s1, pos);
    if (index != std::string::npos) {
      replaceLine += line.substr(pos, index - pos);
      replaceLine += s2;
      pos = index + s1.length();
    } else {
      replaceLine += line.substr(pos, line.length() - pos);
      break;
    }
  }
  return replaceLine;
}

// ./replace [filename] [s1] [s2]
int main(int ac, char **av) {
  if (ac != 4)
    std::cout << "ERROR: Please Input Three Parameters" << std::endl;
  else {
    // infile check
    std::ifstream infile(av[1]);
    if (!infile.is_open()) {
      std::cout << "ERROR: InFile Open" << std::endl;
      return (0);
    }
    // outfile check
    std::string name = av[1];
    std::string replace = ".replace";
    std::ofstream outfile(name.append(replace));
    if (!outfile.is_open()) {
      std::cout << "ERROR: OutFile Open" << std::endl;
      return (0);
    }
    // infile read -> getline()
    // outfile write -> ft_replace() + "\n"
    std::string line;
    int newLineFlag = 0;
    while (std::getline(infile, line)) {
      if (newLineFlag == 0)
        newLineFlag = 1;
      else
        outfile << "\n";
      outfile << ft_replace(line, av[2], av[3]);
    }
    // infile, outfile close
    infile.close();
    outfile.close();
  }
  return (0);
}
