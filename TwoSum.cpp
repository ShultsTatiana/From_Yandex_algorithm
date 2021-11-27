#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Если ответ существует, верните вектор из двух элементов
// Если нет - то верните пустой вектор
vector <int> TwoSumSort(const vector <int>& sortedArr, int targetSum) {
	// Здесь реализация вашего решения
	vector <int> temp;
	if (!sortedArr.empty()) {
		int left(0), right(sortedArr.size() - 1);
		while (left < right) {
			int current_sum = sortedArr[left] + sortedArr[right];
			if (current_sum == targetSum) {
				temp.push_back(sortedArr[left]);
				temp.push_back(sortedArr[right]);
				return temp;
			}
			else if (current_sum > targetSum) {
				--right;
			}
			else {
				++left;
			}
		}
	}
	return temp;
}

vector <int> TwoSumMemory(const vector <int>& sortedArr, int targetSum) {
	set<int> memory_element;
	vector <int> temp;
	for (const int element : sortedArr) {
		auto it = memory_element.count(targetSum - element);
		if (it != 0) {
			temp.push_back(element);
			temp.push_back(targetSum - element);
			return temp;
		}
		else {
			memory_element.insert(element);
		}
	}
	return temp;
}

void print(const vector <int>& result) {
	if (result.size() != 2)
		cout << "None" << endl;
	else
		cout << result[0] << " " << result[1] << endl;
}

int main() {
	int n, targetSum;
	cin >> n;
	vector <int> sortedArr(n);
	for (int i = 0; i < n; ++i)
		cin >> sortedArr[i];
	cin >> targetSum;
	print(TwoSumMemory(sortedArr, targetSum));
}
