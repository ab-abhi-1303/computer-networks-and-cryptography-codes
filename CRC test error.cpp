/****************  CRC PROGRAM *************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //accept m(x) and g(x) 
    vector<int> mx = {1, 1, 0, 0, 1, 0};
    vector<int> gx = {1, 1, 0, 1};
    
    //append (gx ka length - 1 0's to mx)
    mx.insert( mx.begin() + mx.size() , gx.size() - 1 , 0 );
    
    int m = mx.size();
    int g = gx.size();
    
    int i = 0;
    int j;
    
    bool first_time = true;
    vector<int> curr;
    
    while( i < m or curr.size() == g ) { //2nd condition for last iteration 1 more time xor
        //xor g times
        
        j = 0;
        if(first_time == true) {
            while(j < g) {
                curr.push_back(gx[j] ^ mx[i]);
                j++;
                i++;
            }
        
            first_time = false;
        
        }
        else {
            while(j < g) {
                curr[j] = gx[j] ^ curr[j];
                j++;
            }
        }
        
     /*   cout << "Before curr embedded: ";
        for(auto y: curr) {
            cout << y << " ";
        }
        cout << endl;*/
        
        //delete prev zeros
        auto it = curr.begin() ;
        while(it != curr.end()) {
            if(*it == 1)
                break;
            else if(*it == 0) {
                curr.erase(it);
                it--;
            }
                
            it++;
        }
        
       /* cout << "After curr zeros deleted: ";
        for(auto y: curr) {
            cout << y << " ";
        }
        cout << endl;*/
      
       
        
        //now add that many digitts from mx that many zeros deleted
        //i.e (g - curr.size() )
        
        int counter = g - curr.size() ;
        while(i < mx.size() and counter--) {
            curr.push_back(mx[i]);
            i++;
        }
        
        /*cout <<"Current vector is: ";
        for(auto y: curr) {
            cout << y << " ";
        }
        cout << endl;*/
        
    }
    
    
    //now mx k last mein g - 1 bits ko krdo add
    int idx = curr.size() - 1;
    int k = m - 1;
    while(idx >= 0) {
        mx[k] = curr[idx];
        k--;
        idx--;
    }
    
     
     //check if mx is encoded or not
    cout << "Encoded mx is: ";
    for(auto x : mx) {
            cout << x << " ";
    } 
    
    
    //now same process for decrypting as well
    // do it now
    
     i = 0;
    
    //clear curr
    curr.clear();
    
    first_time = true;

    
    while( i < m or curr.size() == g ) { //2nd condition for last iteration 1 more time xor
        //xor g times
        
        j = 0;
        if(first_time == true) {
            while(j < g) {
                curr.push_back(gx[j] ^ mx[i]);
                j++;
                i++;
            }
        
            first_time = false;
        
        }
        else {
            while(j < g) {
                curr[j] = gx[j] ^ curr[j];
                j++;
            }
        }
        
        /*cout << "Before curr embedded: ";
        for(auto y: curr) {
            cout << y << " ";
        }
        cout << endl;*/
        
        //delete prev zeros
        auto it = curr.begin() ;
        while(it != curr.end()) {
            if(*it == 1)
                break;
            else if(*it == 0) {
                curr.erase(it);
                it--;
            }
                
            it++;
        }
        
        //cout << "After curr zeros deleted: ";
        for(auto y: curr) {
            cout << y << " ";
        }
        cout << endl;
      
       
        
        //now add that many digitts from mx that many zeros deleted
        //i.e (g - curr.size() )
        
        int counter = g - curr.size() ;
        while(i < mx.size() and counter--) {
            curr.push_back(mx[i]);
            i++;
        }
        
        //cout <<"Current vector is: ";
        /*for(auto y: curr) {
            cout << y << " ";
        }
        cout << endl;*/
        
    }
    
    string str1 = "Recieve message";
    string str2 = "Discard message";
    
    for(auto y : curr) {
        if(y != 0) {
            cout << str2 << endl;
            return 0;
        }
        
    }
    
    cout << str1 << endl;

    return 0;
}

