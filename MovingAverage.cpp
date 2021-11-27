#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector <double> MovingAverage(const vector <int>& arr, int windowSize) {
    // Здесь реализация вашего решения
    vector<double> temp;
    if (arr.size() < windowSize) {
        temp.push_back( 
            static_cast<double>(
                accumulate(arr.begin(), arr.end(), 0) /
                static_cast<double>(arr.size())
                )
        );
        return temp;
    }
    long long current_sum = accumulate(arr.begin(), arr.begin() + windowSize, 0);
    temp.push_back(static_cast<double>(current_sum / static_cast<double>(windowSize)));

    for (size_t i(0); i < (arr.size() - windowSize); ++i) {
        current_sum -= arr[i];
        current_sum += arr[i + windowSize];
        temp.push_back(
            static_cast<double>(
                current_sum / static_cast<double>(windowSize)
                )
        );
    }
    return temp;
}

void print(const vector <double> &result) {
	for (double x : result)
		cout << x << " ";
	cout << endl;
}

int main() {
	int n, windowSize;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> windowSize;
	print(MovingAverage(arr, windowSize));
}
