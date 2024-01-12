#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
  // tmp : 데이터 객체 생성
  Data* tmp = new Data(42);
  // tmpSerialize : tmp 데이터를 serialize()
  uintptr_t tmpSerialize = Serializer::serialize(tmp);
  // tmpDeserialize : tmpSerialize를 desrialize()
  Data* tmpDeserialize = Serializer::deserialize(tmpSerialize);

  std::cout << "------------------------------------" << std::endl;
  std::cout << "tmp value: " << tmp->getValue() << std::endl;
  std::cout << "tmpDeserialize value: " << tmpDeserialize->getValue()
            << std::endl;
  std::cout << "------------------------------------" << std::endl;
  std::cout << "tmp address: " << tmp << std::endl;
  std::cout << "tmpDeserialize address: " << tmpDeserialize << std::endl;
  std::cout << "tmpSerialize address: " << tmpSerialize << std::endl;

  delete tmp;
  return 0;
}