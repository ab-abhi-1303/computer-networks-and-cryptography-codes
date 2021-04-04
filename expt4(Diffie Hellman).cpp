/**Diffie Hellman Algo**/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, alpha, Xa, Xb;
    cout << "Enter q, alpha, Xa, Xb:" ;
    cin >> q >> alpha >> Xa >> Xb ;
    
    int Ya, Yb;
    Ya = pow(alpha, Xa); 
    Ya %= q;
    Yb = pow(alpha, Xb);
    Yb %= q;
    
    cout << "Ya=" << Ya << endl;
    cout << "Yb=" << Yb << endl;
    
    //secret key calc start
    int Ka, Kb;
    Ka = pow(Yb, Xa);
    Ka %= q;
    Kb = pow(Ya, Xb);
    Kb %= q;

    cout << "Ka=" << Ka << endl;
    cout << "Kb=" << Kb << endl;

    if(Kb == Ka) {
        cout << "Ka = Kb successfull!" << endl;
    }
    else {
        cout << "Ka = Kb not successfull!" << endl;
    }
    
    return 0;
}
