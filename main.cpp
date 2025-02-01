#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <random>
#include <bits/stdc++.h>
using namespace std;

// <-------------------------------- functions for quick sort -------------------------------->
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
// <-------------------------------- functions for quick sort -------------------------------->

int main() {
    // Create a random number generator
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(0, 1000); // Define the range

    // number of numbers to be sorted
    long long int n = 900;

    // Generate random numbers
    std::vector<long long int> unique_numbers(n);
    for (long long int i = 0; i < n; i++) {
        unique_numbers[i] = distr(gen);
    }

    // Load sound
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("step.wav")) {
        return -1; // error
    }
    sf::Sound sound;
    sound.setBuffer(buffer);

    // display window setup
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Main menu", sf::Style::Fullscreen, settings);

    window.clear(sf::Color::Black);
    window.display();
    sf::sleep(sf::milliseconds(1000));

    int count = n;
    int i = 0;

    while (window.isOpen()) {
        int current_num = 0;
        // ? <-------------------------------------------------------Event Listener----------------------------------------->
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
        // ? <-------------------------------------------------------Event Listener----------------------------------------->

        sf::sleep(sf::milliseconds(10)); // sleep for 10 milliseconds

        // ! <-------------------------------------------------------bubble sort----------------------------------------->
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
        // ! <-------------------------------------------------------bubble sort----------------------------------------->

        // ? <-------------------------------------------------------selection sort----------------------------------------->
        // if (count != 0) {
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
        //     count--;
        //     sound.play(); // Play sound after each swap
        // }
        // ? <-------------------------------------------------------selection sort----------------------------------------->

        // ! <-------------------------------------------------------insertion sort----------------------------------------->
        if (count != 0) {
            i = n - count;
            int j = i;
            while (j > 0 && unique_numbers[j] < unique_numbers[j - 1]) {
                int temp = unique_numbers[j];
                unique_numbers[j] = unique_numbers[j - 1];
                unique_numbers[j - 1] = temp;
                current_num = j - 1;
                j--;
            }
            count--;
            sound.play(); // Play sound after each swap
        }
        // ! <-------------------------------------------------------insertion sort----------------------------------------->

        // <-------------------------------------------------------Quick sort----------------------------------------->
        // // quick sort
        // quickSort(unique_numbers, 0, n - 1);

        // if (0 < n - 1) {
        //     int pi = partition(unique_numbers, 0, n - 1);
        //     quickSort(unique_numbers, 0, pi - 1);
        //     quickSort(unique_numbers, pi + 1, 0);
        // }
        // <-------------------------------------------------------Quick sort----------------------------------------->

        // ? <---------------------------------------------drawing----------------------------------------->
        window.clear(sf::Color::Black);

        // draw the rectangles
        for (long long int i = 0; i < n; i++) {
            if (i == current_num) {
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

    // ! <-------------------------------------------------------clock----------------------------------------->
    // // start the time clock
    // auto start = std::chrono::high_resolution_clock::now(); // Start time

    // // end the clock
    // auto end = std::chrono::high_resolution_clock::now(); // End time
    // std::chrono::duration<double> duration = end - start; // Calculate duration

    // // print the time taken
    // std::cout << "Time taken for sorting: " << duration.count() << " seconds" << std::endl;
    // ! <-------------------------------------------------------clock------------------------------------------>

    // return 0;
}