#include <iostream>
#include <windows.h>
#include <sstream>

// MATH POWER
int power(int base, int exponent) { //I know the math.h exist, but I prefear do it myself :P
	if (exponent == 0) return 1; 
	if (exponent == 1) return base;

	int result = 1;
	for (int i = 0; i < exponent; i++) result *= base;
	return result;
}

//BINARY TO DECIMAL CONVERTER
int binaryToDecimal(unsigned int numberToConvert) {
	int lastDigit;
	int decimalConverted = 0;
	int value = std::to_string(numberToConvert).length(); //output the numberToConvert lenght

	for (int i = 0; i <= value; i++)
	{
		lastDigit = numberToConvert % 10; //assign the last digit into lastDigit variable
		numberToConvert = numberToConvert / 10; //remove the last digit from the numberToConvert
		
		//do the sum and the power to obtain the decimal number.
		if (lastDigit == 1)
		{
			decimalConverted += power(2, i);
		}
	}
	return decimalConverted;
}

// DECIMAL TO BINARY CONVERTER
int decimalToBinary(int numberToConvert) { //DOESN'T WORK!
	int exponent = 0;
	bool result[20] = { 0 };

	while (numberToConvert > power(2, exponent)) exponent++; //select the maxium exponent for power of 2

	for (int i = exponent; i >= 0; i--) {
		int powerResult = power(2, i);

		if (numberToConvert >= powerResult) {
			numberToConvert -= powerResult;
			result[i] = 1;
		}
		else {
			result[i] = 0;
		}
		std::cout << result[i];
	}

	return 0;
}


int menu(void) { //menu function
	int number;
	std::cout << "Write the number you want to convert: (do not excede 4 billion)\n";
	std::cin >> number; // input number to convert
	char selection;
	std::cout << "\nDo you want to convert this number into a decimal or a binary number?\n"
		<< "Write \"d\" for decimal or \"b\" for binary.\n";
	std::cin >> selection;

	//selected BINARY to DECIMAL
	if (std::tolower(selection) == 'd')
	{
		std::cout << "\nResult: " << binaryToDecimal(number) << "\n";
	}

	//selected DECIMAL to BINARY
	else if (std::tolower(selection) == 'b')
	{
		std::cout << "\nResult: ";
		decimalToBinary(number);
	}

	else
	{
		system("cls");
		std::cout << "Error! Write b for binary or d for decimal\n\n";
		menu();
	}

	std::cout << "\n\n\nDo you want to do it one more time? [y] YES\t[n] NO\n";
	std::cin >> selection;

	system("cls");

	if (selection == 'y') menu(); 
	else if (selection == 'n') return 0; 
	else std::cout << "Your selection isn't valid. This program will close soon.\n";
}

/*MAIN FUNCTION
It starts the program and recieve the number to convert.
*/
int main(void) {
	std::cout << "DECIMAL - BINARY SOFTWARE CONVERTER\n";
	Sleep(3000);
	system("cls"); //clear the terminal Windows

	menu(); //Going into the menu function
}