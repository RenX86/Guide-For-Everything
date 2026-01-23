#include <iostream>
using namespace std;

int main(){
    float hl;

    cout<<"Enter heamoglobin level: ";
    cin>>hl;

    if (hl <8) cout<<"Severe Anemia";
    else if (hl >=8 && hl <9.5) cout<<"Moderate anemmia";
    else if (hl >=9.6 && hl <13) cout<<"Mild anemia";
    else if (hl >13 && hl <=17) cout<<"Normal level";
    else cout<<"Enter valid input";
return 0;
}
