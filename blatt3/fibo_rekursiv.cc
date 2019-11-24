#include <iostream>
#include <cmath>


using namespace std;
int fiboRekursiv(int n);

int main(int argc, char** argv){
  int elementNr;
  cout << "Welches Elemtent soll berechnet werden" << endl;
  cin >> elementNr;
  cout <<fiboRekursiv(elementNr) <<endl;

}


int fiboRekursiv(int n){

  if(n==1){
    return 0;
  }
  else if(n==2|| n==3){
    return 1;
  }
  else if (n<=0){
    return -1;
  }
  else{
    return fiboRekursiv(n-1)+fiboRekursiv(n-2);
  }

}
