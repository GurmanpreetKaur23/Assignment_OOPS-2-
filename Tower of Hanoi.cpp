#include<iostream>
void TowerOfHanoi(int n , char source , char helper , char destination ){
	if(n==1) {
		std::cout<<"Moving ring 1 from "<<source<<" to "<<destination<<"\n";
		return ;
	}
	TowerOfHanoi(n-1,source,destination,helper);
	std::cout<<"Moving ring "<<n<<" from "<<source<<" to "<<destination<<"\n";
	TowerOfHanoi(n-1,helper,source,destination);
}
int main() {
	int n ;
	std::cin>>n ;
	TowerOfHanoi(n,'A','C','B');
	return 0;
}
