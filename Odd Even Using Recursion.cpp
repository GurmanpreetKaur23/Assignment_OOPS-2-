#include<iostream>
void printOddEven(int N) {
	if(N==0) {
		return ;
	}

	if(N%2!=0) {
		std::cout<<N<<"\n";
	}
	printOddEven(N-1) ;

	if(N%2==0 && N!=0) {
		std::cout<<N<<"\n" ;
	}
}
int main() {
	int N ;
	std::cin>>N ;
	printOddEven(N) ;
	return 0;
}
