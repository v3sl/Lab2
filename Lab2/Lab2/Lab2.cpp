#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(NULL));
	const int SIZE_OF_ARRAY = 2000;
	cout << "Enter the number of elements in array (1 < nuber of elements < " << SIZE_OF_ARRAY / 2 + 1 << ")" << endl;
	int SIZE;
	cin >> SIZE;
	while (true) {
		if (SIZE >= SIZE_OF_ARRAY / 2 || SIZE <= 1) {
			cout << "Please enter correct number of elements (1 < nuber of elements < " << SIZE_OF_ARRAY / 2 + 1 << ")" << endl;
			cin >> SIZE;
		}
		else {
			break;
		}
	}
	float* array_for_elements;
	array_for_elements = new float[SIZE];
	cout << "Enter 1 if you want to generate random numbers or 0 if you want to enter numbers by yourself" << endl;
	int ZERO_OR_ONE = 2;
	cin >> ZERO_OR_ONE;
	float MIN_ELEMENT = 0;
	float MAX_ELEMENT = 0;
	while (true) {
		if (ZERO_OR_ONE != 1 && ZERO_OR_ONE != 0) {
			cout << "You should enter 1 or 0 to continue" << endl;
			cin >> ZERO_OR_ONE;
		}
		else {
			break;
		}
	}
	if (ZERO_OR_ONE == 0) {
		cout << "Enter numbers" << endl;
		for (int i = 0; i < SIZE; i++) {
			cout << "[" << i + 1 << "]" << ": ";
			cin >> array_for_elements[i];
		}
	}
	else {
		cout << "Enter maximum border of your array " << endl;
		cin >> MAX_ELEMENT;
		cout << "Enter minimum border of your array " << endl;
		cin >> MIN_ELEMENT;
		cout << "Your array will consist of elemenst from " << MIN_ELEMENT << " to " << MAX_ELEMENT << " " << endl;
		for (int i = 0; i < SIZE; i++) {
			static const float fraction = 1.0 / (static_cast<float>(RAND_MAX) + 1.0);
			array_for_elements[i] = (rand() * fraction * (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT);
			cout << "[" << i + 1 << "]" << ": ";
			cout << array_for_elements[i] << endl;
		}
	}
	float minValue = FLT_MAX;
	int index_minvalue = 0;
	for (int i = 0; i < SIZE; i++) {
		if (array_for_elements[i] <= minValue) {
			index_minvalue = i;
			minValue = array_for_elements[i];
		}
	}
	cout << "TASK 1" << endl;
	cout << index_minvalue + 1 << endl;
	int index_of_first_negative_value = 22;
	for (int i = 0; i < SIZE; i++) {
		if (array_for_elements[i] < 0 && index_of_first_negative_value == 22) {
			index_of_first_negative_value = i;
			break;
		}
	}
	int index_of_last_negative_value = 22;
	for (int i = 0; i < SIZE; i++) {
		if (array_for_elements[i] < 0) {
			index_of_last_negative_value = i;
		}
	}
	float sum = 0;
	if (index_of_last_negative_value == 22 || index_of_last_negative_value == index_of_first_negative_value) {
		cout << "There are not enough negative elements in your array." << endl;
	}
	else {
		for (int i = 0; i < SIZE; i++) {
			if (i > index_of_first_negative_value && i < index_of_last_negative_value) {
				sum += array_for_elements[i];
			}
		}
		if (sum == 0) {
			cout << "There are no elements between firts and last negatie elements" << endl;
		}
		else {
			cout << "TASK 2" << endl;
			cout << sum << endl;
		}
	}
	int index = 0;
	int SIZE2 = SIZE;
	float X = 60;
	cout << "TASK 3 " << endl;
	cout << "Enter X for task 3" << endl;
	cin >> X;
	float swap_element = 0;
	int i1 = 0;
	for (int i = 0; i < SIZE; i++) {
		if (fabs(array_for_elements[i]) <= X) {
			swap_element = array_for_elements[index];
			array_for_elements[index] = array_for_elements[i];
			array_for_elements[i] = swap_element;
			index += 1;
		}
		else {
			array_for_elements[SIZE2 + 1] = array_for_elements[i];
			SIZE2 += 1;
		}
	}
	SIZE2 = SIZE;
	for (int i = 0; i < SIZE; i++) {
		if (fabs(array_for_elements[i]) > X) {
			array_for_elements[i] = array_for_elements[SIZE2 + 1];
			SIZE2 += 1;
		}
	}
	cout << "TASK 3" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "[" << i + 1 << "]" << ": " << array_for_elements[i] << endl;
	}
	delete[] array_for_elements;
	return 0;
}