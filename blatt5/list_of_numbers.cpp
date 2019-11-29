#include <iostream>
#include <vector> // vector
#include <cmath>

using namespace std;

void showVector(vector<double> &vec);
pair <double, double> findMinMax(vector<double> &vec);
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
  cout << "Min / Max are: "<< findMinMax(v3).first << " and " << findMinMax(v3).second<<endl;
  vector<double> v3_rev =reversed(v3);

  showVector(v3_rev);

  round_vector(v3_rev);
  showVector(v3_rev);




  vector<double> v4={0,1,2,3,4,5,6,7,8,9};
  reverse_inplace(v4);
  showVector(v4);

  return 0;
}//main


//Aufgabe a
void showVector(vector<double> &vec){
  cout << "Beginn Vector" << endl;
  for(int i=0; i<vec.size();i++){
    cout << vec[i] << endl;
  }//for
  cout << "Ende Vector" << endl<<endl;
}//showVector


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
  vector<double> reversed_vec;
  for(int i=1; i<=vec.size();++i){
    reversed_vec.push_back(vec[vec.size()-i]);

  }//for
  return reversed_vec;

}//reversed


//Aufgabe d


void round_vector(vector<double> &vec){
  for(int i = 0; i < vec.size(); i++){
    vec[i]=round(vec[i]);

  }//for i

}//round_vector

//aufgabe e
void reverse_inplace(vector<double> &vec){
  int length=vec.size()/2+1;

  for(int i=1; i<length; i++ ){
//    cout << "swap:" <<vec[i-1] << " " << vec[vec.size()-i] << endl;

    swap(vec[i-1],vec[vec.size()-i]);
  }//for


}//reverse_inplace