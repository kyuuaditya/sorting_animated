#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    std::uniform_int_distribution<> distr(0, 1000); // Define the range

    // number of numbers to be sorted
    long long int n = 900;

    // Load sound
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("step.wav")) {
        return -1; // error
    }
    sf::Sound sound;
    sound.setBuffer(buffer);

    // Generate random numbers
    std::vector<long long int> unique_numbers(n);
    for (long long int i = 0; i < n; i++) {
        unique_numbers[i] = distr(gen);
    }

    // display window setup
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Main menu", sf::Style::Fullscreen, settings);

    int count = n;
    int i = 0;

    window.clear(sf::Color::Black);
    window.display();
    sf::sleep(sf::milliseconds(1000));

    while (window.isOpen()) {
        int temp = 0;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) { // key events
                if (event.key.code == sf::Keyboard::Escape) { // close the window
                    window.close();
                }
            }
        }

        sf::sleep(sf::milliseconds(10));

        window.clear(sf::Color::Black);

        // // bubble sort
        // if (count != 0) {
        //     for (long long int j = 0;j < n - 1; j++) {
        //         if (unique_numbers[j] > unique_numbers[j + 1]) {
        //             long long int temp = unique_numbers[j];
        //             unique_numbers[j] = unique_numbers[j + 1];
        //             unique_numbers[j + 1] = temp;
        //             sound.play(); // Play sound after each swap
        //         }
        //     }
        //     count--;
        // }

        // // selection sort
        // if (count != 0) {
        //     // for (int i = 0;i < n; i++) {
        //     i = n - count;
        //     int minIndex = i;
        //     for (int j = i + 1;j < n; j++) {
        //         if (unique_numbers[j] < unique_numbers[minIndex]) {
        //             minIndex = j;
        //         }
        //     }
        //     int temp = unique_numbers[i];
        //     unique_numbers[i] = unique_numbers[minIndex];
        //     unique_numbers[minIndex] = temp;
        //     // }
        //     count--;
        //     sound.play(); // Play sound after each swap
        // }


        // insertion sort
        if (count != 0) {
            i = n - count;
            int j = i;
            while (j > 0 && unique_numbers[j] < unique_numbers[j - 1]) {
                int temp = unique_numbers[j];
                unique_numbers[j] = unique_numbers[j - 1];
                unique_numbers[j - 1] = temp;
                temp = j - 1;
                j--;
            }
            count--;
            sound.play(); // Play sound after each swap
        }

        // // quick sort
        // quickSort(unique_numbers, 0, n - 1);

        // if (0 < n - 1) {
        //     int pi = partition(unique_numbers, 0, n - 1);
        //     quickSort(unique_numbers, 0, pi - 1);
        //     quickSort(unique_numbers, pi + 1, 0);
        // }

        // ? <---------------------------------------------drawing----------------------------------------->
        // draw the rectangles
        for (long long int i = 0; i < n; i++) {
            if (i == temp) {
                sf::RectangleShape rectangle(sf::Vector2f(2, unique_numbers[i]));
                rectangle.setPosition(60 + i * 2, 1080 - unique_numbers[i] - 40);
                rectangle.setFillColor(sf::Color::Red);
                window.draw(rectangle);
            }
            else {
                sf::RectangleShape rectangle(sf::Vector2f(2, unique_numbers[i]));
                rectangle.setPosition(60 + i * 2, 1080 - unique_numbers[i] - 40);
                rectangle.setFillColor(sf::Color::White);
                window.draw(rectangle);
            }
        }
        window.display();
        // ? <---------------------------------------------drawing----------------------------------------->
    }

    // <-------------------------------------------------------clock----------------------------------------->
    // // start the time clock
    // auto start = std::chrono::high_resolution_clock::now(); // Start time

    // // end the clock
    // auto end = std::chrono::high_resolution_clock::now(); // End time
    // std::chrono::duration<double> duration = end - start; // Calculate duration

    // // print the time taken
    // std::cout << "Time taken for sorting: " << duration.count() << " seconds" << std::endl;
    // <-------------------------------------------------------clock------------------------------------------>

    // return 0;
}