#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
@file Lab6_rasare3.cpp
@author Richie
@date 2026 - 10- 10
@brief Computes the average, highest, and lowest test scores using both static arrays and vectors.
*/




//function protoptype declaration
void arraySolution();
void vectorSolution();



/**
* @brief Calculates the average of scores in a static array.
* @param arr  Array containing the scores.
* @param size Number of scores in the array.
* @return The average as a float.
*/
float calculateAverage(const int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return static_cast<float>(sum) / size;
}



/**
* @brief Finds the highest score in a static array.
* @param arr  Array containing the testscores.
* @param size Number of scores in the array.
* @return Highest score.
*/
int findMax(const int arr[], int size) {
	int Highest = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > Highest) {
			Highest = arr[i];
		}
	}
	return Highest;
}


/*
* @brief Finds the lowest score in a static array.
* @param arr  Array containing the testscores.
* @param size Number of scores in the array.
* @return Lowest score.
*/
int findMin(const int arr[], int size) {
	int Lowest = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < Lowest) {
			Lowest = arr[i];
		}
	}
	return Lowest;
}


/**
* @brief Calculates the average of scores in a vector.
* @param scores Vector containing the scores.
* @return The average scoreas a float, or 0 if empty.
*/
float calculateAverage(const vector<int>& scores) {
	if (scores.empty()) {
		return 0.0f;
	}
	int sum = 0;
	for (int score : scores) {
		sum += score;
	}
	return static_cast<float>(sum) / scores.size();
}


/*
* @brief Finds the highest score in a vector.
* @param scores Vector containing the test scores.
* @return The highest score, or 0 if empty.
*/
int findMax(const vector<int>& scores) {
	if (scores.empty()) {
		return 0; 
	}
	
	return *max_element(scores.begin(), scores.end());
}



/**
* @brief Finds the lowest score in a vector.
* @param scores Vector containing the test scores.
* @return The lowest score, or 0 if empty.
*/
int findMin(const vector<int>& scores) {
	if (scores.empty()) {
		return 0;
	}

	return *min_element(scores.begin(), scores.end());
}




/**
* @brief Solves the problem using a static array.
* @param none
* @return none
*/
void arraySolution() {
	const int size = 10;
	int scores[size];
	for (int i = 0; i < size; i++)
	{
		int score;

		cout << "Enter test score " << i + 1 << " (0-100): ";
		cin >> score;
		while (score < 0 || score > 100) {
			cout << "Invalid input. Please enter a score between 0 and 100: ";
			cin >> score;
		}
		scores[i] = score;
	}

cout << "\n--- Static Array Solution ---" << endl;
cout << "Average score: " << calculateAverage(scores, size) << endl;
cout << "Highest score: " << findMax(scores, size) << endl;
cout << "Lowest score: " << findMin(scores, size) << endl;

}



/*
*@brief Solves the problem using a vector.
* @param none
* @return none
*/
void vectorSolution() {
		vector<int> scores;
		int score = 0;
		cout << "\n";

		while (true) {
			cout << "Enter score from 0 to 100 (-1 to finish): ";
		cin >> score;

		if (score == -1) {
			break;
		}
		if (score >= 0 && score <= 100) {
			scores.push_back(score);
		}
		else {
			cout << "Invalid score. Please enter a score between 0 and 100." << endl;
			}
		}
			if (scores.empty()) {
				cout << "No valid scores were entered." << endl;
				return;
			}
			cout << "\n--- Vector Solution ---" << endl;
			cout << "Average score: " << calculateAverage(scores) << endl;
			cout << "Highest score: " << findMax(scores) << endl;
			cout << "Lowest score: " << findMin(scores) << endl;

			sort(scores.begin(), scores.end());

			cout << "Score in ascending order: ";
			for (const int& s : scores) {
				cout << s << " ";
			}
			cout << endl;
		}


/*
* @brief The main function to run the program.
* @param none
* @return 0 on successful execution.
*/
int main() {

	arraySolution();
	vectorSolution();

	return 0;
}