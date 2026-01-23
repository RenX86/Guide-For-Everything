#include <iostream>
#include <string>
using namespace std;

int main() {
    string dnaSequence;
    int purineCount = 0;
    int pyrimidineCount = 0;

    // Input: DNA sequence from the user
    cout << "Enter a DNA sequence: ";
    getline(cin, dnaSequence);

    // Process each character in the DNA sequence
    for (char nucleotide : dnaSequence) {
        // Convert to uppercase to handle both uppercase and lowercase inputs
        nucleotide = toupper(nucleotide);

        // Check if nucleotide is a purine (A or G)
        if (nucleotide == 'A' || nucleotide == 'G') {
            purineCount++;
        }
        // Check if nucleotide is a pyrimidine (C or T)
        else if (nucleotide == 'C' || nucleotide == 'T') {
            pyrimidineCount++;
        }
    }

    // Output the counts
    cout << "Number of purines (A and G): " << purineCount << endl;
    cout << "Number of pyrimidines (C and T): " << pyrimidineCount << endl;

    return 0;
}
