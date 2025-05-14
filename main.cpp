#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void displayWelcomeMessage() {
	cout << "WELCOME!\n\nThis program will calculate the temperature readings on a daily basis.\n\n";
}

vector<float> promptTemperatures() {
	int n = 0;

	while (n < 1 || cin.fail()) {
		cout << "Enter the number of temperature readings: ";
		cin >> n;
	}

	vector<float> temperatures(n);

	for (int i = 0; i < n; i++) {
		cout << "Enter the temperature reading #" << (i + 1) << ": ";
		cin >> temperatures[i];
	}

	return temperatures;
}

float calculateAverage(const vector<float> &vec) {
	float sum = 0;
	for (const float &val : vec) sum += val;

	return sum / vec.size();
}

void flSort(vector<float> &vec) {
	int size = vec.size();

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			int fli = vec[i], flj = vec[j];

			if (flj < fli) {
				swap(vec[i], vec[j]);
			}
		}
	}
}

int main() {
	// Display Welcome Message
	displayWelcomeMessage();

	for (int i = 0; ; i++) {
		cout << "Day #" << (i + 1) << ": ";

		// Prompt for the number of temperature readings to capture, and
		// Prompt for the temperature readings
		vector<float> temperatures = promptTemperatures();

		// Calculate the average temperature per day
		float averageTemperature = calculateAverage(temperatures);

		// Arrange the temperature (Ascending)
		flSort(temperatures);

		// Find the highest and lowest temperature
		float highest = temperatures[temperatures.size() - 1], lowest = temperatures[0];

		// Display the necessary output
		cout << "\n";
		cout << "The Average Temperature Readings of the Day: " << averageTemperature << "\n";
		cout << "The Temperatures Sorted in Ascending Order: ";

		for (const float &temperature : temperatures) cout << temperature << ", ";
		cout << "\n";

		cout << "The Highest Temperature: " << highest << "\n";
		cout << "The Lowest Temperature: " << lowest << "\n\n";

	 	// Repeat if there are readings for the next day  
		char response = ' ';
		while (response != 'y' && response != 'n') {
			cout << "Continue to Day #" << (i + 2) <<" [y/n]: ";
			cin >> response;
		}

		if (response == 'y')
			cout << "[Proceed]\n\n";
		else {
			cout << "[Stop]\n";

			break;
		} 
	}

	return 0;
}
