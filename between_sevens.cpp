#include <iostream>

int input() {
	//PURPOSE: Let a user input a number greater than 1000000
	//INPUTS: The user inputted value
	//OUTPUTS: returns the user inputted value
	bool smaller = true; 
	unsigned long int number;
	while (smaller) { 
		std::cout << "Enter a number larger than 1,000,000: ";
		std::cin >> number;
		if (number > 1000000) {
			smaller = false;
		}
	}
	return number;
}

void number_processor() {
	//PURPOSE: Find the numbers in an integer between the first two sevens, starting from the right
	//INPUTS: An array for keeping track of the numbers between the sevens
	//OUTPUTS: Returns the size of the array
	unsigned long int number = input();
	int digit; //for keeping track of each digit in the number
	int seven_located = 0; //for flip-flopping between when a 7 exists and when it doesn't
	int array_size = 0;
	int between_sevens[20] = { 0 }; //array that is used to keep track of the numbers between sevens
	while (number > 0) {
		digit = number % 10; //find the digit in the one's place
		if (digit == 7 && (seven_located % 2 == 1)) {
			break;
		}
		if (seven_located % 2 == 1) {  //if a seven has been located, seven_located will be odd, causing this code to run
			between_sevens[array_size] = digit; 
			array_size++;
		}
		if (digit == 7) { //if the digit it 7, increment seven_located to keep track of located seven
			seven_located++;
		}
		if (seven_located > 2) { //if the amount of 7's is greater than 2, the code is exited
			break;
		}
		number /= 10; //this breaks down the full number, removing the one's digit
	}

	for (int i = array_size - 1; i >= 0; --i) {
		std::cout << between_sevens[i] << " "; //prints the array backwards (it was inputted backwards, so it flips it back to normal)
	}
	if (array_size == 0) {
		std::cout << between_sevens[0] << " "; //prints 0 if the array has not been populated
	}
	std::cout << std::endl;

}

int main() {
	number_processor();
}
