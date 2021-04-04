#include<bits/stdc++.h>
using namespace std;

int find_number(string str){
	int n = str.length();
	stringstream geek(str); 
  
    int x = 0; 
    geek >> x; 
	int power = 0;
	int ans = 0;
	while(x != 0){
		int ld = x % 10;
		ans += ld * pow(10,power);
		x /= 10;
		power++;
	}
	return ans;
}

void func(string str){
	if(str.length() > 15){
		cout << "Invalid IP" <<endl;
		return;
	}
	//values 4 hain 
	int i;
	string str1 = "";
	string str2 = "";
	string str3 = "";
	string str4 = "";
	i = 0;
	for( ; str[i] != '.' ; i++){
		str1 += str[i];
	}
	i++;
	for( ; str[i] != '.' ; i++){
		str2 += str[i];
	}
	i++;
	for( ; str[i] != '.' ; i++){
		str3 += str[i];
	}
	i++;
	for( ; str[i] != '.' and i < str.length() ; i++){
		str4 += str[i];
	}

	int a = find_number(str1);
	int b = find_number(str2);
	int c = find_number(str3);
	int d = find_number(str4);	
	
	//we have a.b.c.d
	
	if( ( a < 0 or a > 255 ) or (b < 0 or b > 255) or (c < 0 or c > 255) or (d < 0 or d > 255) ){
		cout << " Aukaat ke bahar" << endl;
		return;
	}
	vector<int> mask;
	//abhi 4 hain aur aukaat me hai
	if( a >= 0 and a <= 127 ){
		//class A
		cout << "Class A IP" << endl;
		mask.push_back(255);
		mask.push_back(0);
		mask.push_back(0);
		mask.push_back(0);
		
		//find 1st and last IP by anding and oring
		cout << "Default Mask:";
		cout << mask[0] <<"."<< mask[1] <<"."<< mask[2] <<"."<<mask[3] <<endl;
		cout << "1st IP:";
		cout << (mask[0] & a) << "."<<(mask[1] & b)<<"."<<(mask[2] & c)<<"."<<(mask[3] & d) <<endl;
		
		//come here to 1's complement of mask and then only OR it
		//scam technique
		for(int y = 0; y < 4 ; y++){
			if(mask[y] == 255)
				mask[y] = 0;
			else
				mask[y] = 255;
		}
		cout <<"last IP:" ;
		cout << (mask[0] | a) << "."<<(mask[1] | b)<<"."<<(mask[2] | c)<<"."<<(mask[3] | c) <<endl; 
		return;	
	}
	else if( a >= 128 and a <= 191 ){
		//calss B
		cout << "Class B IP" << endl;
		mask.push_back(255);
		mask.push_back(255);
		mask.push_back(0);
		mask.push_back(0);
		
		//find 1st and last IP by anding and oring
		cout << "Default Mask:";
		cout << mask[0] <<"."<< mask[1] <<"."<< mask[2] <<"."<<mask[3] <<endl;
		cout << "1st IP:";
		cout << (mask[0] & a) << "."<<(mask[1] & b)<<"."<<(mask[2] & c)<<"."<<(mask[3] & d) <<endl;
		
		//come here to 1's complement of mask and then only OR it
		//scam technique
		for(int y = 0; y < 4 ; y++){
			if(mask[y] == 255)
				mask[y] = 0;
			else
				mask[y] = 255;
		}
		cout <<"last IP:" ;
		cout << (mask[0] | a) << "."<<(mask[1] | b)<<"."<<(mask[2] | c)<<"."<<(mask[3] | c) <<endl; 
		return;	
	}
	
	else if( a >= 192 and a <= 223 ){
		//class C
		cout << "Class C IP" << endl;
		mask.push_back(255);
		mask.push_back(255);
		mask.push_back(255);
		mask.push_back(0);
		
		//find 1st and last IP by anding and oring
		cout << "Default Mask:";
		cout << mask[0] <<"."<< mask[1] <<"."<< mask[2] <<"."<<mask[3] <<endl;
		cout << "1st IP:";
		cout << (mask[0] & a) << "."<<(mask[1] & b)<<"."<<(mask[2] & c)<<"."<<(mask[3] & d) <<endl;
		
		//come here to 1's complement of mask and then only OR it
		//scam technique
		for(int y = 0; y < 4 ; y++){
			if(mask[y] == 255)
				mask[y] = 0;
			else
				mask[y] = 255;
		}
		cout <<"last IP:" ;
		cout << (mask[0] | a) << "."<<(mask[1] | b)<<"."<<(mask[2] | c)<<"."<<(mask[3] | c) <<endl; 
		return;	
	}
	else if( a >= 224 and a <= 239){
		//class D
		//first and lst ip not
		cout << "Class D IP" << endl;
		cout << "No default mask and can't find 1st and last IP";
		return;
	}
	else{
		//class E
		//same as D
		cout << "Class E IP" << endl;
		cout << "No default mask and can't find 1st and last IP";
		return;
	}
	
}

int main(){
	string str;
	cout <<"Enter IP Address:";
	cin >> str;
	func(str);
	return 0;
}
