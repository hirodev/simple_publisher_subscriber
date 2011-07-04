#include <iostream>
#include "toaster.h"

using namespace std;

void Toaster::startToasting(){
  cout << "Toaster lever pulled" << endl;
}

void Toaster::cancelBurntToast(){
  cout << "Toaster done toasting" << endl;
}
