#include <iostream>

int hexify(int i){
	int res =0;
	while(i > 0){
		int temp = i;
		i << 
	}
}

int postify(int i){
	bool neg=false;
	if (i < 0){
		i*=-1;
		neg = true;
	}

	if (neg){
		return -hexify(i);
	}else{
		return hexify(i);
	}
}

int main(){

	std::ios_base::sync_with_stdio(false);
	int i;
	while(std::cin >> i){
		std::cout << i << '\n';
	}

	return 0;
}