#include<bits/stdc++.h>
using namespace std;

// addition
string Add(string s1, string s2){
	int i, num, carry=0, add=0;
	string s;
	int n1 = s1.length();
	int n2 = s2.length();
	int diff = abs(n1-n2);
	if(s1.length()>s2.length()){
		for(i=0;i<diff;i++){
			s2 = '0' + s2;
		}
	}
	else{
		for(i=0;i<diff;i++){
			s1 = '0' + s1;
		}
	}
	for(i=s1.length()-1;i>=0;i--){
		num = (s1[i]-48)+(s2[i]-48);
		num+=carry;
		carry = num/10;
		add = num%10;
		s = to_string(add) + s;
	}
	if(carry!=0)
	    s = to_string(carry) + s;
	return s;
}

// subtraction
string Subtract(string s1, string s2){
	int add, i, flag=0;
	string s, temp;
	int n1 = s1.length();
	int n2 = s2.length();
	int diff = abs(n1-n2);
	if(s1.length()>s2.length()){
		for(i=0;i<diff;i++){
			s2 = '0' + s2;
		}
	}
	else{
		for(i=0;i<diff;i++){
			s1 = '0' + s1;
		}
	}
	for(i=0;i<s1.length();i++){
		if(s1[i]!=s2[i]){
			if(s2[i]>s1[i]){
				temp = s1;
				s1 = s2;
				s2 = temp;
				flag=1;
				break;
			}
		}
	}
	for(i=s1.length()-1;i>=0;i--){
		if(s2[i]>s1[i]){
			add = 10 - (s2[i]-s1[i]);
			if(s1[i-1]=='0'){
				s1[i-1]='9';
				s1[i-2]=s1[i-2]-1;
			}
			else
			    s1[i-1] = s1[i-1]-1;
		}
		else{
		    add = s1[i]-s2[i];
		}
		s = to_string(add) + s;
	}
	if(flag==1)
		s = '-' + s;
	return s;
}

//multiplication
string Multiply(string s1, string s2){
	int i, j, add=0, carry=0, num;
	string result;
	vector<string> arr;
	for(i=s1.length()-1;i>=0;i--){
		string s;
		for(j=s2.length()-1;j>=0;j--){
			num = (s1[i]-48)*(s2[j]-48);
			num+=carry;
			carry = num/10;
			add = num%10;
			s = to_string(add) + s;
		}
		if(carry!=0)
		    s = to_string(carry) + s;
		for(j=0;j<s1.length()-1-i;j++){
			s+='0';
		}
		arr.push_back(s);
		carry = 0;
	}
	for(i=0;i<arr.size();i++){
		result = Add(result, arr[i]);
	}
	return result;
}


int main(){
	string s1, s2;
	cout << "Enter the first string number: ";
	cin >> s1;
	cout << "Enter the second string number: ";
	cin >> s2;
	cout << Add(s1, s2) << endl;
	cout << Subtract(s1, s2) << endl;
	cout << Multiply(s1, s2);
	return 0;
}