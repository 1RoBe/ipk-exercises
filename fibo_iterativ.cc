#include <iostream>
#include <cmath>


using namespace std;
int fiboIter(int numerOfElements);

int main(int argc, char** argv){
  int elementNr;
  cout << "Welches Elemtent soll berechnet werden" << endl;
  cin >> elementNr;
  cout <<fiboIter(elementNr) <<endl;

}


int fiboIter(int elementNr){
  int f1=0;
  int f2=1;
  int f_neu;
  if (elementNr==0){
    return 0;
  }
  else if (elementNr==1){
    return 0;
  }
  if (elementNr==2){
    return 1;
  }
  else if (elementNr<0){
    return -1;
  }
  for(int i=0; i<elementNr-1; i++){
    f_neu=f1+f2;
    f1=f2;
    f2=f_neu;

  }//for
  return f1;

}
