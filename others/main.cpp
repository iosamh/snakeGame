#include <iostream>
#include <string>

int main() {

	int n,t,counter = 0;
	std::string b;


	std::cout << "Enter the number" << std::endl;
	std::cin >> n;

	int i = 0;
	t = n;
	while (t > 0) {
		i++;
		if (t > 1) {
			t /= 2;
		}
		else {
			break;
		}
	}
	
	std::cout << i << " bit" << std::endl;

	
	t = n;

	for (; i > 0; i--) {

		if (t - pow(2, i - 1) >= 0) {
			t = t - pow(2, i - 1);
			b += "1";
			std::cout << "1";
		}
		else if ((t - pow(2, i - 1) == 2)&&(i ==2)) {
			std::cout << "1";
			b += "1";
			continue;
		}
		else if ((t - pow(2, i - 1) == 1) && (i == 1)) {
			std::cout << "1";
			b += "1";
			continue;
		}
		else {
			counter++; 
			b += "0";
			std::cout << "0";
		}
	}

	std::cout << std::endl << "zeros number :" << counter << std::endl;
		
	int maxG = 0, counterG = 0;
	bool last1 = false;
	//std::cout << b << std::endl;


	i = b.length();
	while (i>0) {
		if (b[i-1] == '0') {
			if (last1) {
				counterG++;
			}
		}
		else if (b[i-1] == '1') {
			last1 = true;
			if (maxG < counterG) {
				maxG = counterG;
			}
			counterG = 0;
		}
		i--;
	}
	std::cout << "gaps length: " << maxG << std::endl;

}
