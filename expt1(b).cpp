/**playfair cipher implementation**/
/*Input only CAPS string */
#include <bits/stdc++.h>
using namespace std;

//our matrix for implementation
char mat[5][5];

void fillMatrix(string key, set<char> set){
    int i,j;
    int k = 0;
    
    //to store unique characters of key
    vector<char> stringCharacters;
    
    for(i = 0 ; i < 5 ; i++) {
        for(j = 0 ; j < 5 and k < key.length() ; j++) {
            auto it = find( stringCharacters.begin(), stringCharacters.end(), key[k] );
            if(it == stringCharacters.end())
                mat[i][j] = key[k];
            stringCharacters.push_back(key[k]);
            k++;
        }
    }
    i = key.length() / 5 ;
    j = key.length() % 5;
    cout << "i now:" << i << " j now:" << j << endl;
    bool first = true;
    //we have copyset jisme hain values
    int start = 65;
    for(i = key.length() / 5 ; i < 5 ; i++ ) {
        if(first == true)
            j = key.length() % 5;
        else
            j = 0;
        for( ; j < 5 ; j++ ) {
            //j hai toh skip
            if(start == 74) {
                start++;
                j--;
                continue;
            }
            if( set.find(char(start)) == set.end() ) {
                mat[i][j] = char(start);
            }
            else
                j--;
            start++;
        }
        first = false;
    }
}

//gives (i,j) of a particular character in the matrix
pair<int, int> giveIndexOfCharacter(char ch) {
    if(ch == 'J')
        ch = 'I';
    int i,j;
    for(i = 0 ; i < 5 ; i++)
        for(j = 0 ; j < 5 ; j++)
            if(mat[i][j] == ch)
                return make_pair(i,j);
}

void printMatrix() {
    int i,j;
    for(i = 0 ; i < 5 ; i++) {
        for(j = 0 ; j < 5 ; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

string performEncryption(string plain) {
    vector<pair<char,char>> v;
    if(plain.length() % 2 == 0) {
        //even size no problem in making pairs
        for(int c = 0 ; c < plain.length() ; c = c + 2) {
            v.push_back({plain[c], plain[c + 1]});
        }
    }
    else {
        //odd size attach Z as  extra for last character
         for(int c = 0 ; c < plain.length() - 1 ; c = c + 2) {
            v.push_back({plain[c], plain[c + 1]});
        }
        v.push_back({plain[plain.length() - 1],char(90)});
    }
    
    //check v while display
    cout <<"Vector of pairs of plaintext is:"<< endl;
    for(auto x : v) {
        cout << x.first << " " << x.second << endl;
    }
    
    //we have vector ofpairs ready
    string enc = "";
    
    for(auto x : v) {
        pair<int, int> p1;
        pair<int, int> p2;
        p1 = giveIndexOfCharacter(x.first);
        p2 = giveIndexOfCharacter(x.second);
        
        int x1,y1,x2,y2;
        x1 = p1.first;
        y1 = p1.second;
        x2 = p2.first;
        y2 = p2.second;
        
        //check if same row
        if(x1 == x2) {
            enc += mat[x1][(y1 + 1) % 5];
            enc += mat[x2][(y2 + 1) % 5];
        }
        //if same column
        else if(y1 == y2) {
            enc += mat[(x1 + 1) % 5][y1];
            enc += mat[(x2 + 1) % 5][y2];
        }
        //if form a square
        else {
            enc += mat[x1][y2];
            enc += mat[x2][y1];
        }
    }
    return enc;
}

string performDecyption(string enc, vector<int> positionsOfJ) {
    vector<pair<char,char>> v2;
     //is baar toh even hi hona hai size
    for(int c = 0 ; c < enc.length() ; c = c + 2) {
            v2.push_back({enc[c], enc[c + 1]});
    }
    
    //check v2 while display
    cout <<"Vector of pairs of enc is:"<< endl;
    for(auto x : v2) {
        cout << x.first << " " << x.second << endl;
    }
    
    //now start decryption
    string desc = "";
    for(auto x : v2) {
        pair<int, int> p1;
        pair<int, int> p2;
        p1 = giveIndexOfCharacter(x.first);
        p2 = giveIndexOfCharacter(x.second);
       
        int x1,y1,x2,y2;
        x1 = p1.first;
        y1 = p1.second;
        x2 = p2.first;
        y2 = p2.second;
        
        //check if same row
        if(x1 == x2) {
            int new_y1 = (y1 - 1);
            if(new_y1 < 0)
                new_y1 = 4;
            int new_y2 = (y2 - 1);
            if(new_y2 < 0)
                new_y2 = 4;
            desc += mat[x1][new_y1];
            desc += mat[x2][new_y2];
        }
        //if same column
        else if(y1 == y2) {
            int new_x1 = x1 - 1;
            if(new_x1 < 0)
                new_x1 = 4;
            int new_x2 = x2 - 1;
            if(new_x2 < 0)
                new_x2 = 4;
            desc += mat[new_x1][y1];
            desc += mat[new_x2][y2];
        }
        //if form a square
        else {
            desc += mat[x1][y2];
            desc += mat[x2][y1];
        }
    }
    
    //now again replace I with J usingprev made positionsOfJ array 
    for(int ind = 0 ; ind < positionsOfJ.size() ; ind++) 
        desc[positionsOfJ[ind]] = 'J';
        
    return desc;
}

//main
int main()
{
    cout << "Enter key:" ;
    string key;
    cin >> key;
    set<char> set;
    
    for(auto x: key)
        set.insert(x);
    
    int k = 0;
    int i , j;
 
    fillMatrix(key, set);
    
    //print matrix to check
    printMatrix();
    
    cout << "Enter plaintext:";
    string plain;
    cin >> plain;
    
    //for explicitly handling plaintexts like JAIPUR
    vector<int> positionsOfJ;
    for(int ind = 0 ; ind < plain.length() ; ind++) 
        if(plain[ind] == 'J')
            positionsOfJ.push_back(ind);
    
    string encyptedString = performEncryption(plain);
    cout << "Encypted string is:" << encyptedString << endl;
    
    string decryptedString = performDecyption(encyptedString, positionsOfJ);
    if(decryptedString.length() > plain.length()) {
        //VIDYALANKAR mein extra Z lagana padta hai na 
        decryptedString.pop_back();
    }
    cout << "Descypted string is:" << decryptedString << endl;
    
    return 0;
}

