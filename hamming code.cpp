/************HAMMING CODE PROGRAM *********************/

#include<bits/stdc++.h> 
#define ll long long int
#define mod 1000000007
using namespace std;

int main(){
	ll i,x;
	vector<ll> arr;
	cout << "Enter 7 bit data:";
	for(i = 0 ; i < 7 ;i++) {
	    cin >> x;
	    arr.push_back(x);
	}
	
	//input taken
	//insert 0 for r1,r2,r4,r8
	arr.insert(arr.begin() + 3 , 0); //R8
	arr.insert(arr.begin() + 7 , 0); //R4
	arr.insert(arr.begin() + 9 , 0); //R2
	arr.insert(arr.begin() + 10 , 0); //R1

    //now arr is ready
	
	//now check for R1,R2,R4,R8 parity
	
	//pos to check
	vector<ll>r1 = {0,2,4,6,8,10};
	vector<ll>r2 = {9,8,5,4,1,0};
	vector<ll>r4 = {7,6,5,4};
	vector<ll>r8 = {0,1,2,3};
	
	ll curr = 0;
	for(auto x : r1) {
	    curr += arr[x];
	}
	arr[10] = curr % 2 ;
	
	curr = 0;
	for(auto x : r2) {
	    curr += arr[x];
	}
	arr[9] = curr % 2 ;
	
	curr = 0;
	for(auto x : r4) {
	    curr += arr[x];
	}
	arr[7] = curr % 2 ;
	
	curr = 0;
	for(auto x : r8) {
	    curr += arr[x];
	}
	arr[3] = curr % 2 ;
	
	//keep copy of array before flipping any bit for error detection
	vector<ll> temp;
	temp = arr;
	
	
	cout << "Before flipping:" ;
	for(auto x:arr)
	    cout << x << " ";
	cout << endl;
	
	
	//now parity bits are set
	
	//now randomly flip any single bit
	ll randomPosition = (rand() % 10) + 1;
	cout << "Bit location for randomly flipping:" << randomPosition + 1 << endl;
	arr[randomPosition] = arr[randomPosition] == 1 ? 0 : 1;
	
	
	cout << "After flipping:" ;
	for(auto x:arr)
	    cout << x << " ";
	cout << endl;
	
	
	//now 1 bit has been flip
	//now check error bit 
	
	bool flag = false;
	curr = 0;
	for(auto x : r1) {
	    curr += arr[x];
	}
	
	if(curr % 2 == 1) {
	    //r1 vale bits location mein hai kahin toh error
	    //compare temp and arr
	    for(auto x : r1) {
	        if(arr[x] != temp[x]) {
	            cout << "error bit position is:" << x + 1 << endl;
	            return 0;
	        }
	    }
	}
	
	
	//for r2
	curr = 0;
	for(auto x : r2) {
	    curr += arr[x];
	}
	
	if(curr % 2 == 1) {
	    //r2 vale bits location mein hai kahin toh error
	    //compare temp and arr
	    for(auto x : r2) {
	        if(arr[x] != temp[x]) {
	            cout << "error bit position is:" << x + 1 << endl;
	            return 0;
	        }
	    }
	}
	
	
	curr = 0;
	for(auto x : r4) {
	    curr += arr[x];
	}
	
	if(curr % 2 == 1) {
	    //r4 vale bits location mein hai kahin toh error
	    //compare temp and arr
	    for(auto x : r4) {
	        if(arr[x] != temp[x]) {
	            cout << "error bit position is:" << x + 1 << endl;
	            return 0;
	        }
	    }
	}
	
	
	curr = 0;
	for(auto x : r8) {
	    curr += arr[x];
	}
	
	if(curr % 2 == 1) {
	    //r8 vale bits location mein hai kahin toh error
	    //compare temp and arr
	    for(auto x : r8) {
	        if(arr[x] != temp[x]) {
	            cout << "error bit position is:" << x + 1 << endl;
	            return 0;
	        }
	    }
	}
	
	//if come here then no error and accept data;
	cout << "Data error free,accept it" <<endl;
	
	return 0;
}
