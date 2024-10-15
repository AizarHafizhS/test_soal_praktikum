#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string get_payslip(string name, int gross_salary, int tax_percent, int installment, int insurance) {
  // Get tax amount
  int tax_amount = 0;
  tax_amount = (double(tax_percent) / 100) * gross_salary;

  // Get net salary
  int net_salary = 0;
  net_salary = gross_salary - tax_amount - installment - insurance;

  // Create table
  string title, name_string, gross_string, tax_string, installment_string, insurance_string, net_salary_string;
  string table = "";

  title = "Payslip for Employees\n---------------------\n";
  name_string = "Name: " + name + "\n";
  gross_string = "Gross Salary: Rp" + to_string(gross_salary) + "\n";
  tax_string = "Tax (" + to_string(tax_percent) + "%): Rp" + to_string(tax_amount) + "\n";
  installment_string = "Installment: Rp" + to_string(installment) + "\n";
  insurance_string = "Insurance: Rp" + to_string(insurance) + "\n";
  net_salary_string = "Net Salary: Rp" + to_string(net_salary);

  table += title + name_string + gross_string + tax_string + installment_string + insurance_string + net_salary_string;
  return table;
}

int main() {
  ifstream testFile("test.txt");
  string name;
  int gross_salary, tax_percent, installment, insurance;
  string expected_output;

  if (!testFile) {
    cerr << "Error: Could not open test.txt" << endl;
    return 1;
  }

  int test_num = 1;
  while (testFile >> name >> gross_salary >> tax_percent >> installment >> insurance && getline(testFile >> ws, expected_output)) {
    // Generate the output using the test data
    string output = get_payslip(name, gross_salary, tax_percent, installment, insurance);

    cout << expected_output << endl;

    // // Check if the generated output matches the expected output
    // if (output == expected_output) {
    //   cout << "Test " << test_num << " passed!" << endl;
    //   cout << "Expected output: \n"
    //        << expected_output << endl;
    // } else {
    //   cout << "Test " << test_num << " failed. Expected: \n\""
    //        << expected_output << "\", Got: \n\"" << output << "\"" << endl;
    // }
    // test_num++;
  }

  testFile.close();
  return 0;
}