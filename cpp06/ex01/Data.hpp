#ifndef DATA_HPP
#define DATA_HPP

class Data {
 private:
  int value;

 public:
  Data(int val);
  /* OCF */
  Data();
  ~Data();
  Data(Data const& other);
  Data& operator=(Data const& other);

  /* Getter*/
  int getValue();
};

#endif