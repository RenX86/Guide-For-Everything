#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string dnasequence;
    int a_count = 0, t_count = 0, c_count = 0 , g_count = 0;

    cout << "Enter the dna sequnce: ";
    cin >> dnasequence;

    for (char base : dnasequence)
    {
        base = toupper(base);
        switch (base)
        {
        case 'A':
            a_count++;
            break;
        
        case 'T':
            t_count++;
            break;

        case 'G':
            g_count++;
            break;
        
        case 'C':
            c_count++;
            break;
        default:
            cout << "Inavild Base character found";
            break;
        }
    }
    double total_base_count = a_count + t_count + g_count + c_count;
    double average_base = total_base_count / 4;

    cout << "Total base count: " << total_base_count << endl;
    cout << "A count: " << a_count << endl;
    cout << "C count: " << c_count << endl;
    cout << "G count: " << g_count << endl;
    cout << "T count: " << t_count << endl;
    cout << "Average base count: " << average_base << endl;
    
return  0 ;
}

