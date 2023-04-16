#include "sorts.h"

bool comp(int a, int b) {
	return a ? (a > b) : b;
}

void fill_array(std::vector<int>& arr) {
	std::cout << "Введите количество элементов в массиве (не больше 10 000)" << std::endl;
	int n;
	std::cin >> n;
	for (int i{ 0 }; i < n; i++) {
		arr.push_back(rand() % 100);
	}
}

void bubble_sort(std::vector<int>& arr) {
	std::cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int i{ 0 }; i < arr.size() - 1; i++) {
		for (int j{ 0 }; j < arr.size() - 1; j++) {
			n_comps++;
			if (comp(arr[j], arr[j + 1])) {
				n_reeqs += 3;
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	std::cout << "Количество сравнений: " << n_comps << std::endl;
	std::cout << "Количество переприсваиваний: " << n_reeqs << std::endl;
	std::cout << "Отсортированный массив: ";
	output_array(arr);
}

void insertion_sort(std::vector<int>& arr) {
	std::cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };
	int i, key, j;

	for (i = 1; i < arr.size(); i++)
	{
		n_reeqs++;
		key = arr[i];
		j = i - 1;
		n_comps++;
		while (j >= 0 && comp(arr[j], key))
		{
			n_comps++;
			arr[j + 1] = arr[j];
			n_reeqs++;
			j--;
		}

		if (arr[j + 1] != key) {
			n_comps++;
			arr[j + 1] = key;
		}
	}

	std::cout << "Количество сравнений: " << n_comps << std::endl;
	std::cout << "Количество переприсваиваний: " << n_reeqs << std::endl;
	std::cout << "Отсортированный массив: ";
	output_array(arr);
}

void selection_sort(std::vector<int>& arr) {
	std::cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int i{ 0 }; i < arr.size() - 1; i++) {
		int min_ind = i;
		for (int j{ i + 1 }; j < arr.size(); j++) {
			n_comps++;
			if (comp(arr[min_ind], arr[j])) {
				min_ind = j;
			}
		}
		if (min_ind != i) {
			n_reeqs += 3;
			std::swap(arr[i], arr[min_ind]);
		}
	}

	std::cout << "Количество сравнений: " << n_comps << std::endl;
	std::cout << "Количество переприсваиваний: " << n_reeqs << std::endl;
	std::cout << "Отсортированный массив: ";
	output_array(arr);
}

int partition(std::vector<int> &arr, int start, int end, int &n_comps, int &n_reeqs) {
	int pivot = arr[end];
	int pivot_index{ start - 1 };

	for (int i{ start }; i <= end - 1; i++)
	{
		n_comps++;
		if (arr[i] < pivot)
		{
			pivot_index++;
			std::swap(arr[pivot_index], arr[i]);
			n_reeqs += 3;
		}
	}

	std::swap(arr[pivot_index + 1], arr[end]);
	n_reeqs += 3;
	return pivot_index + 1;
}

int random_partition(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs) {
	int i = (rand() % (end - start)) + start;
	std::swap(arr[end], arr[i]);
	n_reeqs += 3;
	return partition(arr, start, end, n_comps, n_reeqs);
}

void quick_sort(std::vector<int> &arr, int start, int end, int &n_comps, int &n_reeqs) {

	if (start < end) {
		int p = random_partition(arr, start, end, n_comps, n_reeqs);
		quick_sort(arr, start, p - 1, n_comps, n_reeqs);
		quick_sort(arr, p + 1, end, n_comps, n_reeqs);
	}
}

void heapify(std::vector<int> &arr, int i, int size, int &n_comps, int &n_reeqs) {
	int largest{ i };
	int left{ 2 * i + 1 };
	int right{ 2 * i + 2 };

	n_comps++;
	if (left < size && arr[left] > arr[largest])
		largest = left;

	n_comps++;
	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		n_reeqs += 3;
		std::swap(arr[i], arr[largest]);
		heapify(arr, size, largest, n_comps, n_reeqs);
	}
}

void heap_sort(std::vector<int> &arr) {
	std::cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	int size = (int)arr.size();

	for (int i{ size / 2 - 1 }; i >= 0; i--) {
		heapify(arr, i, size, n_comps, n_reeqs);
	}

	for (int i{ size - 1 }; i >= 0; i--) {
		n_reeqs += 3;
		std::swap(arr[0], arr[i]);
		heapify(arr, 0, i, n_comps, n_reeqs);
	}

	std::cout << "Количество сравнений: " << n_comps << std::endl;
	std::cout << "Количество переприсваиваний: " << n_reeqs << std::endl;
	std::cout << "Отсортированный массив: ";
	output_array(arr);
}

void shell_sort(std::vector<int>& arr) {
	std::cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int gap{ (int)arr.size() }; gap > 0; gap /= 2)
	{
		for (int i{ gap }; i < arr.size(); ++i)
		{
			int temp{ arr[i] };
			int j{};
			n_comps++;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
				n_reeqs++;
			}

			arr[j] = temp;
			n_reeqs++;
		}
	}

	std::cout << "Количество сравнений: " << n_comps << std::endl;
	std::cout << "Количество переприсваиваний: " << n_reeqs << std::endl;
	std::cout << "Отсортированный массив: ";
	output_array(arr);
}

void output_array(std::vector<int>& arr) {
	for (int i{ 0 }; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}