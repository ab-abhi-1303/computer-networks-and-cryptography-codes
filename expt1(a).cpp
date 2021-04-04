/**Ceaser cipher implementation**/
/*Input only CAPS string */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char,int> mp;
    int start = 65;
    int count = 0;
    while(count < 26) {
        mp[char(start)] = count;
        count++;
        start++;
    }
    
    string str;
    cout << "Enter Plain text:" ;
    cin >> str;
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << "encrypting now.."<<endl;
    string enc = "";
    for(int i = 0 ; i < str.length() ; i++) {
        int pos = (mp[str[i]] + n) % 26;
        for(auto x : mp)
            if(x.second == pos) {
                enc += x.first;
                break;
            }
    }
    
    cout << "encrypted string:" << enc << endl;
    cout << "decrypting now.." << endl;
    
    //we have enc with us
    string decr = "";
     for(int i = 0 ; i < enc.length() ; i++) {
        int pos = (mp[enc[i]] - n) % 26;
        if(pos < 0){
            pos = 26 - abs(pos);
        }
        for(auto x : mp)
            if(x.second == pos) {
                decr += x.first;
                break;
            }
    }

    cout << "Decypted string:" << decr << endl;

    return 0;
}

