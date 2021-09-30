/*
 * C++ program contains a function that reads words from an input stream
 * and stores them in a vector.
 * That function is used both to write programs that count the number of words in the input,
 * and to count how many times each word occurred.
 *
 * @author Kavya Devadiga
 * @date 09/19/2021
 *
 *
 * \fn void calculateTotalGrade(std::istream &in, std::vector<std::string> wordsStream)
 *   \brief Reads inout stream, prints number of words and occurance of each work in the input
 *   \param in The input stream.
 *   \param wordsStream veactor to store input stream.
 */

//Including header files
#include<iostream>
#include<vector>
#include<string>

#include <algorithm>

void readStream(std::istream &in, std::vector<std::string> wordsStream) {
	std::string word;  //Temporary variable to store individual words in stream (string)
	while (in >> word) {
		wordsStream.push_back(word);
	}
	/* Inputed stream is now stored as a vector in variable wordsStream */

	//Display number of words in stream:
	std::cout << "Total number of words in input: " << wordsStream.size()<<std::endl;

	/* Finding count of each word: */
	std::sort(wordsStream.begin(), wordsStream.end()); //Sort the input vector

	std::string previousWord = wordsStream[0];
	size_t wordCount = 0;		// Variable to store occurance of each word for displaying

	for (int i=0;i<wordsStream.size(); ++i) {	//Iterate through sorted vector to find occurence
		if(previousWord == wordsStream[i])
			wordCount++;
		else{
			std::cout << "Count of '" << previousWord << "' is " << wordCount	<< std::endl;
			previousWord = wordsStream[i];
			wordCount = 1;			//Reset the count for next word
		}
	}
}

int main() {
	try {
		std::vector < std::string > wordsStream;
		std::cout << "Input words to be tested : "<< std::endl;

		/*Call function to read all data from console */
		readStream(std::cin, wordsStream);

		return 0;
	}
	catch (const char *msg) /* catch exception if any */
	{
		std::cout << "Exception occurred" << std::endl;
	}
}
