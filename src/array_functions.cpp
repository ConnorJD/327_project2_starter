/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include "array_functions.h"

using namespace std;
//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct words {
	int count;
	std::string word;
}words[500];

//TODO add a global array of entry structs (global to this file)


//TODO add variable to keep track of next available slot in array
int next = 0;
//TODO define all functions in header file
void clearArray() {
	for (int i = 0 ; i < 500 ; i++) {
		words[i].word = "\0";
	}
};

int getArraySize() {
	int count = 0;
	int cur = 0;
	while (words[cur].word != "/0") {
		if (words[cur].count == 0){
			count++;
		}
		cur++;
	}
	return count;
};

std::string getArrayWordAt(int i) {
	return words[i].word;
};

int getArrayWord_NumbOccur_At(int i) {
	return words[i].count;
};

bool processFile(std::fstream &myfstream) {

	return false;
};

void processLine(std::string &myString) {

};

void processToken(std::string &token) {

};

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){
	return false;
};

void closeFile(std::fstream& myfile) {
	if(myfile.is_open()){
		myfile.close();
	}
};

int writeArraytoFile(const std::string &outputfilename) {
	return 0;
};

void sortArray(constants::sortOrder so) {

};
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
