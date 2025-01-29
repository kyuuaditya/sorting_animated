#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <random>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<long long int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}

void quickSort(vector< long long int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(0, 1000000); // Define the range

    long long int n = 10000;

    std::vector<long long int> unique_numbers(n);
    for (long long int i = 0; i < n; i++) {
        unique_numbers[i] = distr(gen);
    }

    auto start = std::chrono::high_resolution_clock::now(); // Start time

    // // bubble sort
    // for (long long int i = 0;i < n; i++) {
    //     for (long long int j = 0;j < n - 1; j++) {
    //         if (unique_numbers[j] > unique_numbers[j + 1]) {
    //             long long int temp = unique_numbers[j];
    //             unique_numbers[j] = unique_numbers[j + 1];
    //             unique_numbers[j + 1] = temp;
    //         }
    //     }
    // }

    // // optimized bubble sort
    // for (long long int i = 0;i < n; i++) {
    //     bool isSwapped = false;
    //     for (long long int j = 0;j < n - 1; j++) {
    //         if (unique_numbers[j] > unique_numbers[j + 1]) {
    //             long long int temp = unique_numbers[j];
    //             unique_numbers[j] = unique_numbers[j + 1];
    //             unique_numbers[j + 1] = temp;
    //             isSwapped = true;
    //         }
    //         if (!isSwapped) {
    //             break;
    //         }
    //     }
    // }

    // // selection sort
    // for (int i = 0;i < n; i++) {
    //     int minIndex = i;
    //     for (int j = i + 1;j < n; j++) {
    //         if (unique_numbers[j] < unique_numbers[minIndex]) {
    //             minIndex = j;
    //         }
    //     }
    //     int temp = unique_numbers[i];
    //     unique_numbers[i] = unique_numbers[minIndex];
    //     unique_numbers[minIndex] = temp;
    // }

    // // insertion sort
    // for (int i = 1;i < n; i++) {
    //     int j = i;
    //     while (j > 0 && unique_numbers[j] < unique_numbers[j - 1]) {
    //         int temp = unique_numbers[j];
    //         unique_numbers[j] = unique_numbers[j - 1];
    //         unique_numbers[j - 1] = temp;
    //         j--;
    //     }
    // }

    // quick sort
    quickSort(unique_numbers, 0, n - 1);

    auto end = std::chrono::high_resolution_clock::now(); // End time
    std::chrono::duration<double> duration = end - start; // Calculate duration

    std::cout << "Time taken for sorting: " << duration.count() << " seconds" << std::endl;

    // for (int i = 0;i < n;i++) {
    //     std::cout << unique_numbers[i] << std::endl;
    // }

    return 0;
}