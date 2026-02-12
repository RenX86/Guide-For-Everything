#include <iostream>
#include <string>

using namespace std;

void calculateBaseCount(const string& dnaSequence) {
    
    int baseCounts[4] = {0}; 

    for (char nucleotide : dnaSequence) {
        nucleotide = toupper(nucleotide);
        switch (nucleotide) {
            case 'A':
                ++baseCounts[0]; 
                break;
            case 'T':
                ++baseCounts[1]; 
                break;
            case 'C':
                ++baseCounts[2]; 
                break;
            case 'G':
                ++baseCounts[3];
                break;
            default:
                cout << "Invalid nucleotide found: " << nucleotide << endl;
                return;
        }
    }

    double totalBases = baseCounts[0] + baseCounts[1] + baseCounts[2] + baseCounts[3];
    if (totalBases == 0) {
        cout << "No valid bases found in the sequence." << endl;
        return;
    }

    double averageBaseCount = totalBases / 4.0;

    cout << "Number of A: " << baseCounts[0] << endl;
    cout << "Number of T: " << baseCounts[1] << endl;
    cout << "Number of C: " << baseCounts[2] << endl;
    cout << "Number of G: " << baseCounts[3] << endl;
    cout << "Average base count: " << averageBaseCount << endl;
}

int main() {
    string dnaSequence;

    cout << "Enter the DNA sequence: ";
    cin >> dnaSequence;

    calculateBaseCount(dnaSequence);

    return 0;
}