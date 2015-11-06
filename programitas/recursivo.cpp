#include <iostream>
using namespace std;

int i = 0;

void recursiva(){
  cout << i << endl;
  ++i;
  recursiva();
}

int main(){
  recursiva();
  return 0;
}
