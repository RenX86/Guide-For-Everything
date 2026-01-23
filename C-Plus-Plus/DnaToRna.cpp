#include <iostream>
#include <string>
using namespace std;

string dnaToRna( const string& dna){
    string rna = dna;
    for (char& base : rna)
    {
        base = toupper(base);
        if (base == 'A') base = 'U';
        else if (base == 'G') base = 'C';
        else if (base == 'T') base = 'A';
        else if (base == 'C') base = 'G';
        else cout << "Error";
    }
    return rna;
}

int main(){
    string dnaSequence;

    cout << "Enter the DNA sequnce: ";
    cin >> dnaSequence;

    string rnaSequence = dnaToRna(dnaSequence);
    cout << "The corresponding Rna seq. is: "<< rnaSequence << endl;

    return 0;
}