#include <iostream>
#include <typeinfo>
auto message(auto input){
  return input;

}

int main(int argc, char** argv){
  std::cout << typeid(message(5
  ).name() << std::endl;
  return 0;
}
