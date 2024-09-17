#include <iostream>
using namespace std;

int main() {
  int input, sum = 0;

  input = 5;

  for (int i = 1; i <= input; i++) {
    sum += i;
  }

  cout << sum << endl;
}