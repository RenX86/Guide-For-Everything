#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char complemet(char nucleotide){
    switch (nucleotide)
    {
    case 'A': return 'T';
    case 'G': return 'C';
    case 'C': return 'G';
    case 'T': return 'A';  
    default: return 'N';
    }
}

string getReverseComplemet(const string& sequence) {
    string reverseComp = sequence;

    reverse(reverseComp.begin(), reverseComp.end());

    for ( char& nucleotide : reverseComp)
    {
        nucleotide = complemet(nucleotide);
    }
    return reverseComp;
}

int main (){
    string dnaSequence;
    cout << "Enter the DNA sequnce: ";
    cin >> dnaSequence;
    
    transform(dnaSequence.begin(), dnaSequence.end(), dnaSequence.begin(), ::toupper);

    string reverseComp = getReverseComplemet(dnaSequence);

    cout << "Reverse complement: "<< reverseComp << endl;

    return 0;
}