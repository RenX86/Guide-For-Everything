#include <iostream>
using namespace std;

int main() {
    char aa;

    // Prompt user for input
    cout << "Enter the starting letter of the amino acid: ";
    cin >> aa;

    // Convert input to lowercase for uniformity
    aa = tolower(aa);

    cout << "Amino acid names starting with '" << aa << "' are: \n";

    // Use if-else logic to check the starting letter and print corresponding amino acids
    if (aa == 'a') {
        cout << "alanine\n";
        cout << "arginine\n";
        cout << "asparagine\n";
        cout << "aspartic acid\n";
    } else if (aa == 'c') {
        cout << "cysteine\n";
    } else if (aa == 'g') {
        cout << "glutamine\n";
        cout << "glutamic acid\n";
        cout << "glycine\n";
    } else if (aa == 'h') {
        cout << "histidine\n";
    } else if (aa == 'i') {
        cout << "isoleucine\n";
    } else if (aa == 'l') {
        cout << "leucine\n";
        cout << "lysine\n";
    } else if (aa == 'm') {
        cout << "methionine\n";
    } else if (aa == 'p') {
        cout << "phenylalanine\n";
        cout << "proline\n";
    } else if (aa == 's') {
        cout << "serine\n";
    } else if (aa == 't') {
        cout << "threonine\n";
        cout << "tryptophan\n";
        cout << "tyrosine\n";
    } else if (aa == 'v') {
        cout << "valine\n";
    } else {
        cout << "Wrong input or no amino acids found for the letter '" << aa << "'\n";
    }

    return 0;
}
