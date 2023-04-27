#include "sorts.h"

bool comp(int a, int b) {
	return a ? (a > b) : b;
}

void fill_array(std::vector<int>& arr) {
	std::cout << "Введите количество элементов в массиве (не больше 10 000)" << std::endl;
	int n;
	std::cin >> n;
	for (int i{ 0 }; i < n; i++) {
		arr.push_back(rand() % 1000);
	}
}

/*void fill_uniform_array(std::vector<double> &arr) {
	int max, min, n;
	std::cout << "Введите отрезок на котором определено распределение" << std::endl;
	std::cin >> max >> min;
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> n;
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	std::uniform_int_distribution<> dist(1, 100);

	for (int i{ 0 }; i < n; i++) {
		arr.push_back(dist(gen) / 100.0);
	}
}*/

void fill_uniform_int_array(std::vector<int> &arr, int opt) {
	int n{};
	std::cout << "Числа будут сгенерированы от 0 до n, введите n" << std::endl;
	std::cin >> n;

	if (opt == 0) {
		for (int i{ 0 }; i < n; i++) {
			arr.push_back(i);
		}
	}
	else {
		for (int i{ 0 }; i < n + rand() % n; i++) {
			arr.push_back(rand() % n);
		}
	}

	std::random_shuffle(arr.begin(), arr.end());
}

void fill_array_for_radix(std::vector<int>& arr) {
	int n{}, m{};
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> n;
	
	std::cout << "Введите количество разрядов у рандомных чисел" << std::endl;
	std::cin >> m;

	for (int i{ 0 }; i < n; i++) {
		arr.push_back(rand() % ((int)(pow(10, m) - 1) - (int)pow(10, m - 1)) + (int)pow(10, m - 1));
	}
}

void fill_array_for_radix_2(std::vector<int>& arr) {
	int n{}, m{};
	std::cout << "Введите размер массива" << std::endl;
	std::cin >> n;

	std::cout << "Введите количество разрядов у рандомных чисел" << std::endl;
	std::cin >> m;

	for (int i{ 0 }; i < n; i++) {
		arr.push_back(rand() % (int)pow(10, m));
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

		n_comps++;
		if (arr[j + 1] != key) {
			arr[j + 1] = key;
			n_reeqs++;
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

int partition(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs) {
	int pivot = arr[end];
	int pivot_index{ start - 1 };

	for (int i{ start }; i < end; i++)
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

void quick_sort(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs) {

	if (start < end) {
		int p = random_partition(arr, start, end, n_comps, n_reeqs);
		quick_sort(arr, start, p - 1, n_comps, n_reeqs);
		quick_sort(arr, p + 1, end, n_comps, n_reeqs);
	}
}

void heapify(std::vector<int>& arr, int i, int size, int& n_comps, int& n_reeqs) {
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

void heap_sort(std::vector<int>& arr) {
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
				n_comps++;
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

void bucket_sort(std::vector<int>& arr) {
	std::cout << "Несортированный массив: ";
	output_array(arr);
	//int n_comps{ 0 };
	//int n_reeqs{ 0 };
	int command{};
	std::cout << "Введите команду:\n0 - без доп. массива\n1 - с доп. массивом" << std::endl;
	std::cin >> command;
	if (command == 0) {
		for (int i{ 0 }; i < arr.size(); i++)
		{
			while (arr[i] != i)
			{
				int temp{ arr[arr[i]] };
				arr[arr[i]] = arr[i];
				arr[i] = temp;
				//n_reeqs++;
				//n_comps++;
			}
		}
	}
	else if (command == 1) {
		std::vector<int> b(arr.size());

		for (int i{ 0 }; i < arr.size(); i++) {
			b[arr[i]] = arr[i];
			//n_reeqs++;
		}
		arr = b;
	}
	//std::cout << "Количество сравнений: " << n_comps << std::endl;
	//std::cout << "Количество переприсваиваний: " << n_reeqs << std::endl;
	std::cout << "Отсортированный массив: ";
	output_array(arr);
}

void count_sort(std::vector<int> &arr, int exp)
{
	std::vector<int> count(10);
	std::vector<int> output(arr.size());
	int i{};
	for (i = 0; i < arr.size(); i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = arr.size() - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	arr = output;
}

void radix_sort(std::vector<int> &arr)
{
	std::cout << "Несортированный массив: ";
	output_array(arr);

	int m{ *std::max_element(arr.begin(), arr.end()) };
	for (int exp = 1; m / exp > 0; exp *= 10)
		count_sort(arr, exp);

	std::cout << "Отсортированный массив: ";
	output_array(arr);
}

void lists_to_array(std::vector<Node *> &b, std::vector<int> &arr) {
	Node* cur{};
	int j{ 0 };
	int max{ *std::max_element(arr.begin(), arr.end()) };
	for (int i{ 0 }; i <= max; i++) {
		cur = b[i];
		while (cur) {
			arr[j] = cur->data;
			cur = cur->next;
			j++;
		}
	}
	output_array(arr);
}

void push_back(Node *&head, int data) {
	Node* cur{head};
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = new Node;
	cur->next->data = data;
}

void generic_bucket_sort(std::vector<int> &arr) {
	std::cout << "Несортированный массив: ";
	output_array(arr);
	int max{ *std::max_element(arr.begin(), arr.end()) };
	std::vector<Node*> b(max + 1);
	for (int i{ 0 }; i < arr.size(); i++) {
		if (!b[arr[i]]) {
			b[arr[i]] = new Node;
			b[arr[i]]->data = arr[i];
		}
		else {
			push_back(b[arr[i]], arr[i]);
		}
	}

	/*for (int i{ 0 }; i <= max; i++) {
		cur = b[i];
		std::cout << "Промежуточный список: ";
		while (cur) {
			std::cout << cur->data << " ";
			cur = cur->next;
		}
		std::cout << "\n";
	}*/

	lists_to_array(b, arr);
	std::cout << "Отсортированный массив: ";
	output_array(arr);
}

void output_array(std::vector<int>& arr) {
	for (int i{ 0 }; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}