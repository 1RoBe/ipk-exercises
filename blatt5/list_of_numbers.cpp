#include <iostream>
#include <vector> // vector
#include <cmath>
#include <algorithm>

using namespace std;

void showVector(vector<double> &vec);
pair<double,double> findMinMax(vector<double> &vec);
vector<double> reversed(vector<double> &vec);
void round_vector(vector<double> &vec);
void reverse_inplace(vector<double> &vec);

int main(int argc, char const *argv[]) {
  vector<double> v1;
  showVector(v1);
  vector<double> v2(19);
  showVector(v2);
  vector<double> v3={-15,0,1,2.36424,3,1.4,5,-6,7,8,9,10,11,12,0,-1.5};
  showVector(v3);

  cout << "Min / Max sind: "<< findMinMax(v3).first << " und " << findMinMax(v3).second<<endl;

  vector<double> v3_rev =reversed(v3);
  showVector(v3_rev);

  round_vector(v3);
  showVector(v3);

  vector<double> v4 = {1,-5,3.52,-4,56,8,-4};
  reverse_inplace(v4);
  showVector(v4);
  reverse_inplace(v2);
  showVector(v2);

  return 0;
}

void showVector(vector<double> &vec){
  cout<< "Beginn Vektor: "<<endl  ;

  for (int i = 0; i < vec.size(); i++) {
    cout<< vec[i];
    if (i < vec.size()-1) {
      cout<< ", ";
    }else{
      std::cout << "" << endl;
    }
  }
  cout<< "Ende Vektor"<< endl;
  cout << "" << endl;
}


//Aufgabe b
pair<double,double> findMinMax(vector<double> &vec){
  double min=0;
  double max=0;
  for(int i=0;i<vec.size();i++){
    if(vec[i]>max){
      max=vec[i];
    }//if
    else if(vec[i]<min){
      min=vec[i];
    }//else if

  }//for
  return make_pair(min, max);
}//findMinMax


//Aufgabe c
vector<double> reversed(vector<double> &vec){
  vector<double> reversed_vec(vec.size());
  for (int i = 0; i < vec.size(); i++) {
    reversed_vec[i] = vec[vec.size()-i-1];
  }
  return reversed_vec;
}


//Aufgabe d
void round_vector(vector<double> &vec){
  for(int i = 0; i < vec.size(); i++){
    vec[i]=round(vec[i]);
  }
}


//Aufgabe e
void reverse_inplace(vector<double> &vec){
  for (int i = 0; i < vec.size()/2-1; i++) {
    swap(vec[i], vec[vec.size()-i-1]);
  }
}
