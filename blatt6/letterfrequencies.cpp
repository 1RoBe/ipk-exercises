#include <iostream>
#include <vector> // vector
#include <cmath>
#include <algorithm>
#include <map>

std::map<char,int> get_frequencies();
//void print_frequencies(const std::map<char,int>& frequencies);

int main(int argc, char** argv) {
  const std::map<char, int> frequencies=get_frequencies();
  //print_frequencies(const std::map<char,int>& frequencies);
  return 0;
}

std::map<char,int> get_frequencies() {
  std::map<char, int> lettList;
  while (true) {
    unsigned char c;
    // read in character
    std::cin >> c;
    // abort if input closed
    if (not std::cin)
      break;

    lettList[c]++;
  }
  std::cout << "it worked" << '\n';
  return get_frequencies();
}
/*
void print_frequencies(const std::map<char,int>& frequencies) {
   std::map<char , int >::iterator itr;
   for(itr=lettList.begin();itr!=lettList.end();itr++)

    cout<<itr->first<<" - "<<itr->second<<endl;
}
*/
