#include <iostream>
#include <cmath>
#include <string>

int digitsPower(int digit, int digitsNumber) {
	int power=1;
	for (int i = 0; i < digitsNumber; i++) {
		power *= digit;
	}
	return power;
}

bool isArmstrongNumber(int number,int digitsNumber)
{
	// TODO: implement some functionality to see if this number is an armstrong number
	int temp = number;
	int temp2;
	int sum = 0;
	while (number != 0) {
		temp2 = number % 10;
		sum += digitsPower(temp2,digitsNumber);
		number = number / 10;
	}
	if (sum == temp) {
		return true;
	}
	return false;
}

void printIsArmstrong(int number, int digitsNumber)
{
	if (isArmstrongNumber(number,digitsNumber))
	{
		std::cout << "Armstrong" << std::endl;
	}
	else
	{
		std::cout << "NOT Armstrong" << std::endl;
	}
}

int main(int argc, char *argv[])
{
	// What is this program expected to do?
	// - Shows whether an argument is an armstrong number.
	// (what?)
	// -	An Armstrong number is a number that is equal to the sum of cubes of its digits.
	//		For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
	//		Let's try to understand why 153 is an Armstrong number:
	//			1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
	//
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  03_armstrong.exe 1		=> Output: Armstrong
	//		  03_armstrong.exe 2		=> Output: NOT Armstrong
	//		  03_armstrong.exe 			=> Output: No program arguments found.
	//		  03_armstrong.exe ABC		=> Undefined output (do whatever).
	//		  03_armstrong.exe 153		=> Output: Armstrong
	//		  03_armstrong.exe 154		=> Output: NOT Armstrong
	//

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	int readNumber = 0;
	int digitsNumber = 0;
	// Get the first argument
	std::string argumentAsString = argv[1];

	if (argumentAsString.empty()) {
		printf("No program arguments found");
		return 1;
	}

	for (int i = 0; i < argumentAsString.length(); i++) {
		if (!isdigit(argumentAsString.at(i))) {
			printf("Undefined output");
			return 1;
		}	
		digitsNumber++;
	}
	readNumber = std::stoi(argumentAsString);

	printIsArmstrong(readNumber,digitsNumber);
	return 0;
}