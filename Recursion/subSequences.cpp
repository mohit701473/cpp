// Code Studio    Que: Subsequences of String

#include <bits/stdc++.h> 
void getSubSequences(string str, string output, int index, vector<string> &ans) {

	if(index == str.length()) {
		if(output.length() > 0){
			ans.push_back(output) ;
		}
		return ;
	}

	// Exclude 
	getSubSequences(str, output, index+1, ans) ;

	// Include
	char element = str[index] ;
	output.push_back(element) ;
	getSubSequences(str, output, index+1, ans) ;
}

vector<string> subsequences(string str){
	
	// Write your code here
	int index = 0 ;
	string output = "";
	vector<string> ans ;

	getSubSequences(str, output, index, ans) ;
	
	return ans ;
	
}
