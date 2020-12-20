#include <iostream>
/*
Student name: Christopher Oka
Student number: 20892372

SYDE 121 Test #1: Control Flow (Question 3)
Filename: control_flow.cpp

 I hereby declare that this code, submitted for credit for the course
 SYDE121, is a product of my own efforts. This coded solution has
 not been plagiarized from other sources and has not been knowingly plagiarized by others.

 Project: 121 Test
 Purpose:
 Due date: Friday, October 23

*/
/*
Program steps:
1. Create an input function that will allow the user to enter an
integer number that is greater than 1000000. If the number
does not exceed 1000000, the user is prompted to enter another
number
2. The number is returned from this function
3. Create a processing function that takes the inputted number
4. Iterates through the given number from the back until a 7
is found. This is done by using the modulus operator and
the division operator to break down the number into its
digits.
5. If a 7 is not found, 0 is printed
6. If a 7 is found, the program outputs each digit until 
another 7 is found. If it is not found, everything after the first
7 is outputted.
*/

/*
Tested values:
1234568 because there are no 7s
1234567 because there is a single 7 at the end
7123456 because there is a single 7 at the front
1237745 because there are two adjacent 7s
7123457 because two 7s cap the number off at both ends
1237475 because two 7s contain a number
7097987 because there are three 7s

All tested values work!
*/

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
	std::cout << "For 1234567, expected values are 123456\n";
	std::cout << "For 7123456, expected values are 0\n";
	std::cout << "For 1237745, expected values are 0\n";
	std::cout << "For 7123457, expected values are 12345\n";
	std::cout << "For 1237475, expected values are 4\n";
	std::cout << "For 7097987, expected values are 98\n";
	number_processor();
}