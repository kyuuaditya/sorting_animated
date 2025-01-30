#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <random>
#include <bits/stdc++.h>
using namespace std;

// int partition(vector<long long int>& vec, int low, int high) {
//     int pivot = vec[high];
//     int i = (low - 1);
//     for (int j = low; j <= high - 1; j++) {
//         if (vec[j] <= pivot) {
//             i++;
//             swap(vec[i], vec[j]);
//         }
//     }
//     swap(vec[i + 1], vec[high]);
//     return (i + 1);
// }

// void quickSort(vector< long long int>& vec, int low, int high) {
//     if (low < high) {
//         int pi = partition(vec, low, high);
//         quickSort(vec, low, pi - 1);
//         quickSort(vec, pi + 1, high);
//     }
// }

// void merge(vector<long long int>& arr, int left,
//     int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // Create temp vectors
//     vector<int> L(n1), R(n2);

//     // Copy data to temp vectors L[] and R[]
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     int i = 0, j = 0;
//     int k = left;

//     // Merge the temp vectors back 
//     // into arr[left..right]
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of L[], 
//     // if there are any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of R[], 
//     // if there are any
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(vector<long long int>& arr, int left, int right) {
//     if (left >= right)
//         return;

//     int mid = left + (right - left) / 2;
//     mergeSort(arr, left, mid);
//     mergeSort(arr, mid + 1, right);
//     merge(arr, left, mid, right);
// }

int main() {
    // Create a random number generator
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(0, 100); // Define the range

    // number of numbers to be sorted
    long long int n = 50;

    // Generate random numbers
    std::vector<long long int> unique_numbers(n);
    for (long long int i = 0; i < n; i++) {
        unique_numbers[i] = distr(gen);
    }

    // display window setup
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Main menu", sf::Style::Default, settings);
    // window.setFramerateLimit(1); // set frame rate limit
    // window.setVerticalSyncEnabled(true); // enable vertical sync

    int count = n;
    while (window.isOpen() && count != 0) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::sleep(sf::milliseconds(100));

        window.clear();

        // bubble sort
        if (count != 0) {
            for (long long int j = 0;j < n - 1; j++) {
                if (unique_numbers[j] > unique_numbers[j + 1]) {
                    long long int temp = unique_numbers[j];
                    unique_numbers[j] = unique_numbers[j + 1];
                    unique_numbers[j + 1] = temp;
                }
            }
            count--;
            for (long long int i = 0; i < n; i++) {
                std::cout << unique_numbers[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    // start the time clock
    auto start = std::chrono::high_resolution_clock::now(); // Start time


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

    // // quick sort
    // quickSort(unique_numbers, 0, n - 1);

    // // merge sort
    // mergeSort(unique_numbers, 0, n - 1);

    // end the clock
    auto end = std::chrono::high_resolution_clock::now(); // End time
    std::chrono::duration<double> duration = end - start; // Calculate duration

    // print the time taken
    std::cout << "Time taken for sorting: " << duration.count() << " seconds" << std::endl;

    return 0;
}