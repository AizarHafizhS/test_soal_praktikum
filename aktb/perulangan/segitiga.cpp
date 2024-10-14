#include <iostream>
using namespace std;

void triangle(int row_input) {
  // iterate tiap barisnya
  for (int baris = 0; baris < row_input; baris++) {
    // Tentukan isi tiap baris
    for (int inside = row_input; inside > 0; inside--) {
      if (inside > baris) {
        // No stars, just space
        cout << "._.";
      }
    }
    cout << endl;
  }
}

int main() {
  triangle(5);
}