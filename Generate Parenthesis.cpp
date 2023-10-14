#include<iostream>
using namespace std ;
int parenthesis(int n , int open , int close ,int idx , char *ans ){
	if(idx==2*n) {
		ans[idx] = '\0' ;
		cout<<ans<<"\n" ;
		// return; 
	}
	if(close<open) {
		ans[idx] = ')' ;
		parenthesis(n,open,close+1,idx+1,ans);
	}
	if(open<n) {
		ans[idx] = '(' ;
		parenthesis(n,open+1,close,idx+1,ans);
	}
	
	ans[idx]= ' ' ;
	return 0 ;
}
int main() {
	char ans[100] = "" ;
	int n ;
	cin>>n ;
	parenthesis(n,0,0,0,ans) ;
	return 0 ;
}
