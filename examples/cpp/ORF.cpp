#include <iostream>
using namespace std;

int main() {
    // Initialize the array with ORF lengths of various genes (example values in base pairs)
    int orf_lengths[] = {345, 678, 1023, 512, 890, 760, 945, 1110, 490};
    int num_genes = sizeof(orf_lengths) / sizeof(orf_lengths[0]);  // Calculate the number of genes

    // Display ORF lengths
    cout << "Open Reading Frame (ORF) lengths of various genes:" << endl;
    for (int i = 0; i < num_genes; ++i) {
        cout << "Gene " << i + 1 << ": " << orf_lengths[i] << " base pairs" << endl;
    }

    return 0;
}
