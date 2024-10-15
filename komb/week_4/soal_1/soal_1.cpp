#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int loop_sum(int range_number) {
  int sum = 0; // variable untuk menyimpan hasil penjumlahan

  // Mulai loop dari 1 - range_number
  for (int number = 1; number <= range_number; number++) {
    // Jumlahkan angka
    sum += number;
  }
}

int main() {
  // int input = 0; // variabel untuk menyimpan input
  // int sum = 0; // variable untuk menyimpan hasil penjumlahan

  // input = 5;

  // for (int i = 1; i <= input; i++) {
  //   sum += i;
  // }

  // cout << sum << endl;
  ifstream testFile("test.txt");
  int input;
  string expected_output;

  if (!testFile) {
    cerr << "Error: Could not open test.txt" << endl;
    return 1;
  }

  int test_num = 1;
  while (testFile >> input && getline(testFile >> ws, expected_output)) {
    int output = loop_sum(input);
    if (to_string(output) == expected_output) {
      cout << "Test " << test_num << " passed!" << endl;
    } else {
      cout << "Test " << test_num << " failed. Expected: \""
           << expected_output << "\", Got: \"" << output << "\"" << std::endl;
    }
    test_num++;
  }

  testFile.close();
  return 0;
}