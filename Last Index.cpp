#include<iostream>
int findLastIndex(int arr[] , int N ,int M,int currentIndex) {
	if(currentIndex<0) {
		return -1 ;
	}
	if(arr[currentIndex]==M) {
		return currentIndex ;
	}
return findLastIndex(arr,N,M,currentIndex-1) ;
	}

int main() {
	int N ;
	std::cin>>N;

	int arr[N] ;
	for(int i=0 ; i<N ; i++) {
		std::cin>>arr[i] ;
	}
	int M ;
	std::cin>>M ;

	int lastIndex = findLastIndex(arr,N,M,N-1) ;
	if(lastIndex!=-1) {
		std::cout<<lastIndex<<std::endl;
	} 
	else{
		std::cout<<"-1"<<std::endl;
	}
	return 0;
}
