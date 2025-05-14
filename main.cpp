#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

void displayWelcomeMessage() {
	cout << "WELCOME!\n\nThis program will calculate the temperature readings on a daily basis.\n\n";
}

vector<float> promptTemperatures() {
	int n = 0;

	while (n < 1) {
		cout << "Enter the number of temperature readings: ";
		cin >> n;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10'000, '\n');
		}
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

int readingCount(const vector<float> &vec, int basis = 40) {
	int count = 0;
	for (const float &val : vec) if (val > basis) count++;

	return count;
}

void flSort(vector<float> &vec) {
	int size = vec.size();

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (vec[j] < vec[i]) {
				swap(vec[i], vec[j]);
			}
		}
	}
}

int main() {
	// Display Welcome Message
	displayWelcomeMessage();

	for (int i = 0; ; i++) {
		cout << "Day #" << (i + 1) << "\n";

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
		cout << fixed << setprecision(2) << "\n";
		cout << "The Average Temperature Readings of the Day: " << averageTemperature << "\n";

		int readingBasis = 40;
		cout << "The Temperature Readings Beyond " << readingBasis << " degrees Celsius: " << readingCount(temperatures, readingBasis) << "\n";

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
