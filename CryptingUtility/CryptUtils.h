#pragma once
#include<string>

//buf and key must be the same length else the func doesn't work and returns false
bool WriteEncryptedDataToFile(const std::string& filePath, const std::string& buf, const std::string& key);
//buf and key must be the same length else the func doesn't work and returns false
bool ReadEncryptedDataFromFile(const std::string& filePath, const std::string& key, std::string& buf);
//the func opening a file by path and returns symbol line from file
std::string CheckFile(const std::string& filePath);
//the func to clear all data in a file
void ClearFile(const std::string& filePath);