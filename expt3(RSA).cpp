/**RSA Algorithm**/

/* give p = 3, q = 5, plaintext = 'ABC' */
#include <bits/stdc++.h>

using namespace std;

vector<int> encrypt(string plain, int e, int n) {
    //calculate ASCII for every character and then do..
    vector<int> res;
    for(int i = 0 ; i < plain.length() ; i++) {
        int p = int(plain[i]);
        // cout << p << " ";
        //cout << e << " ";
        long long int c = pow(p, e);
        //cout << c << " ";
        c = c % n;
        //cout << c << " ";
        //cipher += to_string(c);
        res.push_back(c);
        //cout << cipher <<endl;
    }
    return res;
}

string decrypt(vector<int> res, int d, int n) {
    string plain = "";
    for(int i = 0 ; i < res.size() ; i++) {
        int c = res[i];
        long long int p = pow(c, d);
        p = p % n;
        plain += to_string(p);
        //cout << plain <<endl;
    }
    return plain;
}

int main()
{
    int p,q;
    cout << "Enter 2 prime nos(p & q):" ;
    cin >> p >> q;
    
    int n = p * q;
    int phi_n = (p - 1) * (q - 1); //phi_n = phi(p) * phi(q)
    
    int i,e,d;
    for(i = min(p, q) ; i < phi_n ; i++ ) {
        if( __gcd(i, phi_n) == 1 ) {
            e = i;
            break;
        }
    }
    
    //iterate i till we get d = ( phi_n * i + 1 )/e to get integer value
    //i =  1,2,3...
    for(i = 1 ; ; i++) {
        int val = ( (phi_n * i) + 1 ) / e;
        if(floor(val) == ceil(val)) {
            d = val;
            break;
        }
    }
    
    cout << "Public key:(" << e << "," << n << ")" <<  endl;
    cout << "Private key:(" << d << "," << n << ")" << endl;
    
    cout << "Enter plaintext:";
    string plain;
    cin >> plain;
    
    string cipher = "";
    vector<int> res = encrypt(plain, e, n);
    for(auto x : res)
        cipher += to_string(x);
    
    cout << "Encypted string:" << cipher << endl;
    
    string rev = decrypt(res, d, n);
    cout << "decrypted string:" << rev ;
    
    return 0;
}
