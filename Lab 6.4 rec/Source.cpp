#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

// ���������� ������� ��� ��������� ������
std::vector<double> create_array(int n, int i = 0) {
    if (i >= n) return std::vector<double>(n); // ���� ������
    std::vector<double> arr = create_array(n, i + 1); // ����������� ������
    arr[i] = (static_cast<double>(rand()) / RAND_MAX) * 200.0 - 100.0; // ��������� ��������
    return arr;
}

// ���������� ������� ��� ��������� ������
void print_array(const std::vector<double>& arr, int i = 0) {
    if (i == 0) std::cout << "[";
    if (i >= arr.size()) {
        std::cout << "]" << std::endl;
        return; // ���� ������
    }

    std::cout << std::fixed << std::setprecision(2) << arr[i];
    if (i != arr.size() - 1) {
        std::cout << ", ";
    }

    print_array(arr, i + 1); // ����������� ������ ��� ���������� ��������
}

// ���������� ������� ��� ���������� ���� �������� ��������
double sum_positive_elements(const std::vector<double>& arr, int i = 0) {
    if (i >= arr.size()) return 0.0; // ���� ������
    double sum = (arr[i] > 0) ? arr[i] : 0;
    return sum + sum_positive_elements(arr, i + 1); // ����������� ������
}

// ���������� ������� ��� ����������� ������� ������������� �� ������� ��������
int find_max_index(const std::vector<double>& arr, int i = 1, int max_index = 0) {
    if (i >= arr.size()) return max_index; // ���� ������
    if (std::abs(arr[i]) > std::abs(arr[max_index])) {
        max_index = i;
    }
    return find_max_index(arr, i + 1, max_index); // ����������� ������
}

// ���������� ������� ��� ����������� ������� ���������� �� ������� ��������
int find_min_index(const std::vector<double>& arr, int i = 1, int min_index = 0) {
    if (i >= arr.size()) return min_index; // ���� ������
    if (std::abs(arr[i]) < std::abs(arr[min_index])) {
        min_index = i;
    }
    return find_min_index(arr, i + 1, min_index); // ����������� ������
}

// ���������� ������� ��� ���������� ������� �� ������������ �� ��������� �� �������
double product_between_max_min(const std::vector<double>& arr, int i = 0, double product = 1.0) {
    int max_index = find_max_index(arr);
    int min_index = find_min_index(arr);

    if (max_index > min_index) std::swap(max_index, min_index); // ������������ �������

    if (i > max_index || i <= min_index) return product; // ���� ������
    return product_between_max_min(arr, i + 1, product * arr[i]); // ����������� ������
}

// ���������� ������� ��� ���������� �������� ��������
void sort_odd_elements(std::vector<double>& odd_elements, int i = 0) {
    if (i >= odd_elements.size() - 1) return; // ���� ������
    for (int j = i + 1; j < odd_elements.size(); ++j) {
        if (odd_elements[i] < odd_elements[j]) {
            std::swap(odd_elements[i], odd_elements[j]);
        }
    }
    sort_odd_elements(odd_elements, i + 1); // ����������� ������
}

// ���������� ������� ��� ���������� �������� �������� � �������� �������
std::vector<double> sort_odd_elements_desc(const std::vector<double>& arr, int i = 0) {
    if (i >= arr.size()) return arr; // ���� ������

    std::vector<double> odd_elements;
    for (double x : arr) {
        if (static_cast<int>(x) % 2 != 0) {
            odd_elements.push_back(x);
        }
    }

    sort_odd_elements(odd_elements); // ������� ������ ��������

    std::vector<double> result(arr.size());
    size_t odd_index = 0;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (static_cast<int>(arr[i]) % 2 != 0) {
            result[i] = odd_elements[odd_index++];
        }
        else {
            result[i] = arr[i];
        }
    }

    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::srand(static_cast<unsigned int>(std::time(0)));

    int n;
    std::cout << "������ ������� �������� ������: ";
    std::cin >> n;

    std::vector<double> arr = create_array(n);

    std::cout << "���������� �����:" << std::endl;
    print_array(arr);

    double positive_sum = sum_positive_elements(arr);
    std::cout << "���� �������� ��������: " << std::fixed << std::setprecision(2) << positive_sum << std::endl;

    double product = product_between_max_min(arr);
    std::cout << "������� �������� �� ������������ �� ��������� �� �������: " << product << std::endl;

    std::vector<double> sorted_arr = sort_odd_elements_desc(arr);
    std::cout << "������������� �����:" << std::endl;
    print_array(sorted_arr);

    return 0;
}
