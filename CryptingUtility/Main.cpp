#include "CryptUtils.h"
#include <iostream>

int main()
{
	std::string filePath{"../Debug/EncriptedData.txt"};

	std::cout << "the Data and Key must be the same length for successful data encryption!" << std::endl;

	std::cout << "Enter some data: ";
	std::string originalData;
	std::cin >> originalData;

	std::cout << "Enter a key: ";
	std::string key;
	std::cin >> key;

	WriteEncryptedDataToFile(filePath, originalData, key);

	std::string encriptedData = CheckFile(filePath);
	std::cout << "Encripted Data: " << encriptedData << std::endl;

	std::cout << "Enter the key again: ";
	std::cin >> key;
	std::string resultData;
	ReadEncryptedDataFromFile(filePath, key, resultData);
	std::cout << "Decripted Data: " << resultData;

	ClearFile(filePath);
	return 0;
}