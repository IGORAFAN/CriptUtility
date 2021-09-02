#include "pch.h"
#include "framework.h"
#include <string>
#include <iostream>
#include <fstream>
#include "CryptUtils.h"

bool WriteEncryptedDataToFile(const std::string& filePath, const std::string& buf, const std::string& key) {
	std::string result;
	if (buf.length() == key.length()) {
		//Encripting
		for (int i = 0; i < buf.length(); ++i) {
			result += (buf[i] ^ key[i]);
		}
		//Writing to file
		std::ofstream outputFile;
		outputFile.open(filePath);
		if (outputFile.is_open()) {
			outputFile << result;
		}
		outputFile.close();
		std::cout << "The data was encrypted!!!" << std::endl;
		return true;
	}
	else{
		std::cout << "the Key isn`t the same lenth as the Encripted Data" << std::endl;
		return false;
	}
}

bool ReadEncryptedDataFromFile(const std::string& filePath, const std::string& key, std::string& buf) {
	//Reading from file
	std::ifstream inputFile(filePath);
	std::string tempBuf;
	if (inputFile.is_open()) {
		getline(inputFile, tempBuf);
	}
	inputFile.close();
	//Decripting
	if (tempBuf.length() == key.length()) {
		for (int i = 0; i < tempBuf.length(); ++i) {
			buf += (tempBuf[i] ^ key[i]);
		}
		return true;
	}
	else{
		std::cout << "the Key isn`t the same lenth as the Encripted Data" << std::endl;
		return false;
	}
}

std::string CheckFile(const std::string& filePath){
	std::string result;
	std::ifstream inputFile;
	inputFile.open(filePath);
	if (inputFile.is_open()) {
		getline(inputFile, result);
		inputFile.close();
		return result;
	}
	else {
		return ("Invalid file path!");
	}
}

void ClearFile(const std::string& filePath){
	std::ofstream fileForClearing;
	fileForClearing.open(filePath, std::ofstream::out | std::ofstream::trunc);
	fileForClearing.close();
}
