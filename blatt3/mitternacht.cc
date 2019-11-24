#include <iostream>
#include <cmath>
using namespace std;

void showZeros(double a, double b, double c);


int main (int argc, char** argv){
  double a, b, c;

  cout << "a= "<< endl;
  cin >> a;
  cout << "b= "<< endl;
  cin >> b;
  cout << "c= "<< endl;
  cin >> c;
  showZeros(a,b,c);
}


void showZeros(double a, double b, double c){
  // ax^2 +bx +c
  //if two zeros
  if( pow(b,2)>4*a*c){
    double firstZero = (-b+sqrt(pow(b,2) -4*a*c))/(2*a);
    double secondZero = (-b-sqrt(pow(b,2) -4*a*c))/(2*a);
    cout<< "x1=" << firstZero << ", x2= " << secondZero << endl;


  }//if >0

  //if one zero

  if( pow(b,2)==4*a*c){
    double zero = (-b+sqrt(pow(b,2) -4*a*c))/(2*a);
    cout<< "x=" << zero << endl;

  }//if =0


  if( pow(b,2)<4*a*c){

    cout<< "komplexe Zahl"  << endl;

  }//if =0

}
