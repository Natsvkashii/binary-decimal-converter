#include <iostream>
#include <windows.h>
#include <sstream>

// math power 
int power(int base, int exponent) {
	if (exponent == 0) return 1;
	if (exponent == 1) return base;

	int result = 1;
	for (int i = 0; i < exponent; i++) result *= base;
	return result;
}

//BINARY TO DECIMAL CONVERTER
int decimalConversion(unsigned int numberToConvert) {
	int lastDigit;
	int decimalConverted = 0;
	int value = std::to_string(numberToConvert).length();
	for (int i = 0; i <= value; i++) //OK no bug
	{
		lastDigit = numberToConvert % 10;
		numberToConvert = numberToConvert / 10;
		if (lastDigit == 1)
		{
			decimalConverted += power(2, i);
		}
	}
	return decimalConverted;
}

// DECIMAL TO BINARY CONVERTER
int binaryConversion(int numberToConvert) {
	return 1;
}


int menu(unsigned int number) { //menu function
	char selection;
	std::cout << "Do you want to convert this number into a decimal or a binary number?\n"
		<< "Write \"d\" for decimal or \"b\" for binary.\n";
	std::cin >> selection;

	//selected BINARY to DECIMAL
	if (std::tolower(selection) == 'd') 
	{
		std::cout << decimalConversion(number) << "\n";
	}

	//selected DECIMAL to BINARY
	else if (std::tolower(selection) == 'b')
	{
		std::cout << binaryConversion(number) << "\n";
	}

	else
	{
		system("cls");
		std::cout << "Error! Write b for binary or d for decimal\n";
		menu(number);
	}
	return 0;
}

int main(void) {
	std::cout << "DECIMAL - BINARY SOFTWARE CONVERTER\n";
	Sleep(3000);
	system("cls");

	unsigned int number;
	std::cout << "Write the number you want to convert: (don't excede 4 billions)\n";
	std::cin >> number;

	menu(number); //Going into the menu function
}