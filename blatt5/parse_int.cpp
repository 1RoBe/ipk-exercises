#include <iostream>
#include <vector> // vector
#include <cmath>
#include <algorithm>

int parse_int(std::string number);


int main(int argc, char** argv) {
  std::string number = "-47218.555";
  parse_int(number);
  //std::getline(std::cin, number);
  return 0;
}


int parse_int(std::string number) {
  int size = number.size();
  int b;
  int zahl = 0;
  char a;
  int c = 1;
  std::vector<int> zahlV;
  for (int i = 0; i < size; i++) {
    a = number[i];

      switch (a) {
        case ' ':
        case '-': c = -1;
        case '+':

        case '0': b = 0;
          break;
        case '1': b = 1;
          break;
        case '2': b = 2;
          break;
        case '3': b = 3;
          break;
        case '4': b = 4;
          break;
        case '5': b = 5;
          break;
        case '6': b = 6;
          break;
        case '7': b = 7;
          break;
        case '8': b = 8;
          break;
        case '9': b = 9;
          break;
        default:
          std::cout<<"Fehler";
          zahl = zahl*i/size;
          i = size;
          break;
      }

    zahl = (zahl + b * pow(10, (size-i-1)));
  }
  zahl = c * zahl;
  std::cout<<zahl<<std::endl;
  return 0;
}
