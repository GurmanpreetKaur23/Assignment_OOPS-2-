#include<iostream>
int findFirstIndex(int arr[],int N,int M,int currentIndex) {
	if(currentIndex==N) {
		return -1 ;
	}

	if(arr[currentIndex]==M) {
		return currentIndex ;
	}

	return findFirstIndex(arr,N,M,currentIndex+1) ;
}
int main() {
	int N;
	std::cin>>N ;

	int arr[N] ;
	for(int i=0;i<N; i++) {
		std::cin>>arr[i] ;
	}

	int M;
	std::cin>>M;

	int firstIndex = findFirstIndex(arr,N,M,0) ;
	if(firstIndex!=-1) {
		std::cout<<firstIndex<<std::endl ;
	}
	else {
		std::cout<<"-1"<<std::endl ;
	}
	return 0;
}
