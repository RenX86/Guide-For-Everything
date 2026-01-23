#include <iostream>
#include <string>
using namespace std;

// Function to determine peptide type
string determinePeptideType(int peptideLength) {
    if (peptideLength >= 1 && peptideLength <= 8) {
        return "small peptide";
    } else if (peptideLength >= 9 && peptideLength <= 50) {
        return "poly peptide";
    } else {
        return "invalid peptide length";
    }
}

int main() {
    // Input two peptides as strings
    string peptide1, peptide2;
    
    cout << "Enter the first peptide sequence: ";
    cin >> peptide1;
    
    cout << "Enter the second peptide sequence: ";
    cin >> peptide2;

    // Calculate the lengths of the peptides
    int length1 = peptide1.length();
    int length2 = peptide2.length();

    // Output the type of each peptide
    cout << "First peptide is a " << determinePeptideType(length1) << endl;
    cout << "Second peptide is a " << determinePeptideType(length2) << endl;

    return 0;
}
