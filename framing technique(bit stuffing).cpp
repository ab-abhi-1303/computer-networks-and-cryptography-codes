/************BIT STUFFING*********/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> arr;
    cout << "Enter size of Input array i.e bit count";
    cin >> n;
    int i,x,j;
    for(i = 0 ; i < n ; i++){
        cin >> x;
        arr.push_back(x);
    }

    //now start check for 5 consecutive 1's
    for(i = 0; i < arr.size() ;) {
        if(arr[i] == 1) {
            //loop and check if 5 1's togrther .if yes, insert a zero
            int count = 0;
            for(j = i ; j < arr.size() and count < 5 ; j++) {
                if(arr[j] == 1) {
                    count++;
                }
                else
                    break;
            }
            
            if(count == 5) {
                //insert a zero
                auto it = arr.begin();
                advance(it, j);
                arr.insert(it, 0);
            }
            
            i = j;
        }
        else 
            i++;
    }
    
    cout << "After stuffing:";
    cout << "0 1 1 1 1 1 1 0 ";
    for(auto ele : arr) {
        cout << ele << " ";
    }
    cout << "0 1 1 1 1 1 1 0";
    cout <<endl;
    
    //now zero has been inserted after every 5 1's
    //now remove them also
    for(i = 0; i < arr.size() ;) {
        if(arr[i] == 1) {
            //loop and check if 5 1's togrther .if yes, remove a zero
            int count = 0;
            for(j = i ; j < arr.size() and count < 5 ; j++) {
                if(arr[j] == 1) {
                    count++;
                }
                else
                    break;
            }
            
            if(count == 5) {
                //insert a zero
                auto it = arr.begin();
                //advance(it, 8);
                advance(it, j);
                arr.erase(it); //zero will be removed
            }
            
            i = j + 1;
        }
        else 
            i++;
    }
    
    //I feel job is done
    
    
    //print array
    cout << "After destuffing:";
    for(auto ele : arr) {
        cout << ele << " ";
    }

    
    return 0;
}
