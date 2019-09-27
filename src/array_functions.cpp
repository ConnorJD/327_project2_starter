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
#include "constants.h"
#include "utilities.h"

using namespace constants;
using namespace std;
//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct words {
	int count;
	string word;
};

//TODO add a global array of entry structs (global to this file)
struct words mywords[MAX_WORDS];

//TODO add variable to keep track of nex available slot in array
int nex = 0;
//TODO define all functions in header file
void clearArray() {
	for (int i = 0 ; i < MAX_WORDS ; i++) {
		mywords[i].word = "";
		mywords[i].count = 0;
	}
	nex = 0;
};

int getArraySize() {
	return nex;
};

std::string getArrayWordAt(int i) {
	return mywords[i].word;
};

int getArrayWord_NumbOccur_At(int i) {
	return mywords[i].count;
};

bool processFile(std::fstream &myfstream) {
	if (!myfstream.is_open()) {
		return false;
	}
	std::string line;
	while (!myfstream.eof()) {
		getline(myfstream, line);
		processLine(line);
	}
	return true;
};

void processLine(std::string &myString) {
	string temptoken;
	stringstream ss(myString);
	while(getline(ss, temptoken, CHAR_TO_SEARCH_FOR)) {
		processToken(temptoken);
	}
};

void processToken(std::string &token) {
	bool exists = false;
	if(strip_unwanted_chars(token)) {
		for (int i = 0 ; i < nex ; i++) {
			std::string temp = mywords[i].word;
			toUpper(temp);
			std::string temptoken = token;
			toUpper(temptoken);
			if (temp == temptoken) {
				mywords[i].count++;
				exists = true;
			}
		}
		if (!exists) {
			mywords[nex].word = token;
			mywords[nex].count = 1;
			nex++;
		}
	}

};

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){
	myfile.open(myFileName.c_str(), mode);
	return myfile.is_open();
};

void closeFile(std::fstream& myfile) {
	if(myfile.is_open()){
		myfile.close();
	}
};

int writeArraytoFile(const std::string &outputfilename) {
	ofstream myOutputfile;
	myOutputfile.open(outputfilename.c_str(), ios::out);
	if(!myOutputfile.is_open()) {
		return FAIL_FILE_DID_NOT_OPEN;
	}
	if (nex == 0) {
		return FAIL_NO_ARRAY_DATA;
	}

	for (int i = 0 ; i < nex ; i++) {
		myOutputfile << mywords[i].word;
		myOutputfile << " ";
		myOutputfile << mywords[i].count;
		myOutputfile << "\n";
	}
	myOutputfile.close();
	return SUCCESS;
};

void sortArray(constants::sortOrder so) {
	switch(so){
	case sortOrder::ASCENDING:
		for (int i = 0 ; i < nex-1 ; i++) {
			for (int j = 0 ; j < nex-i-1 ; j++) {
				std::string temp1 = mywords[j].word;
				std::string temp2 = mywords[j+1].word;
				toUpper(temp1);
				toUpper(temp2);
				if (temp1 > temp2) {
					words temp = mywords[j];
					mywords[j] = mywords[j+1];
					mywords[j+1] = temp;
				}
			}
		}
		break;
	case sortOrder::DESCENDING:
		for (int i = 0 ; i < nex-1 ; i++) {
			for (int j = 0 ; j < nex-i-1 ; j++) {
				std::string temp1 = mywords[j].word;
				std::string temp2 = mywords[j+1].word;
				toUpper(temp1);
				toUpper(temp2);
				if (temp1 < temp2) {
					words temp = mywords[j];
					mywords[j] = mywords[j+1];
					mywords[j+1] = temp;
				}
			}
		}
		break;
	case sortOrder::NUMBER_OCCURRENCES:
		break;
	case sortOrder::NONE:
		break;
	};
};
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
