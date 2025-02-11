// libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <random>
#include <bits/stdc++.h>
using namespace std;

// ! <-------------------------------- function for rendering array -------------------------------->
void renderArray(std::vector<long long int>& arr, sf::RenderWindow& window) {
    window.clear();
    for (size_t idx = 0; idx < arr.size(); idx++) {
        sf::RectangleShape rectangle(sf::Vector2f(2, arr[idx]));
        rectangle.setPosition(60 + idx * 2, window.getSize().y - arr[idx] - 40);
        window.draw(rectangle);
    }
    window.display();
}
// ! <-------------------------------- function for rendering array -------------------------------->

// ? <-------------------------------- functions for merge sort -------------------------------->
void merge(std::vector<long long int>& arr, int left, int mid, int right, sf::Sound& sound, sf::RenderWindow& window) {
    if (window.isOpen() == false) {
        return;
    }
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<long long int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) { // key events
            if (event.key.code == sf::Keyboard::Escape) { // close the window
                window.close();
                break;
            }
        }
    }

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;

        renderArray(arr, window);
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        renderArray(arr, window);
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        renderArray(arr, window);
    }
}

void mergeSort(std::vector<long long int>& arr, int left, int right, sf::Sound& sound, sf::RenderWindow& window) {
    if (window.isOpen() == false) {
        return;
    }
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, sound, window);
    mergeSort(arr, mid + 1, right, sound, window);
    merge(arr, left, mid, right, sound, window);
}
// ? <-------------------------------- functions for merge sort -------------------------------->

int main() {
    // ! <------------------------------------------ random number generator ----------------------------------------->
    // Create a random number generator
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(0, 920); // Define the range

    // number of numbers to be sorted
    long long int n = 880;

    // Generate random numbers
    std::vector<long long int> unique_numbers(n);
    for (long long int i = 0; i < n; i++) {
        unique_numbers[i] = distr(gen);
    }
    // ! <------------------------------------------ random number generator ----------------------------------------->

    // ? <------------------------------------------ sound ----------------------------------------->
    // Load sound
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("step.wav")) {
        return -1; // error
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    // ? <------------------------------------------ sound ----------------------------------------->

    // ! <---------------------------------------------- window settings ----------------------------------------->
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1880, 1000), "Main menu", sf::Style::Default, settings);

    window.clear(sf::Color::Black);
    window.display();
    sf::sleep(sf::milliseconds(1000));
    // ! <---------------------------------------------- window settings ----------------------------------------->

    int count = n;
    int i = 0;
    int once = 1;
    int render = 0;
    int pressed = 0;


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
                if (event.key.code == sf::Keyboard::Space) { // pause the sorting
                    pressed = 1;
                }
            }
        }
        // ? <-------------------------------------------------------Event Listener----------------------------------------->

        sf::sleep(sf::milliseconds(10)); // sleep for 10 milliseconds

        // ! <-------------------------------------------------------bubble sort----------------------------------------->
        // if (count != 0 && pressed) {
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
        // render = 1;
        // ! <-------------------------------------------------------bubble sort----------------------------------------->

        // ? <-------------------------------------------------------selection sort----------------------------------------->
        // if (count != 0 && pressed) {
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
        //     current_num = minIndex;
        //     count--;
        //     sound.play(); // Play sound after each swap
        // }
        // render = 1;
        // ? <-------------------------------------------------------selection sort----------------------------------------->

        // ! <-------------------------------------------------------insertion sort----------------------------------------->
        // if (count != 0 && pressed) {
        //     i = n - count;
        //     int j = i;
        //     while (j > 0 && unique_numbers[j] < unique_numbers[j - 1]) {
        //         int temp = unique_numbers[j];
        //         unique_numbers[j] = unique_numbers[j - 1];
        //         unique_numbers[j - 1] = temp;
        //         current_num = j - 1;
        //         j--;
        //     }
        //     count--;
        //     sound.play(); // Play sound after each swap
        // }
        // render = 1;
        // ! <-------------------------------------------------------insertion sort----------------------------------------->

        // ? <-------------------------------------------------------Quick sort----------------------------------------->

        // ? <-------------------------------------------------------Quick sort----------------------------------------->

        // ! <------------------------------------------------------- merge sort ----------------------------------------->
        if (once && pressed) {
            mergeSort(unique_numbers, 0, unique_numbers.size() - 1, sound, window);
            once = 0;
        }
        render = 1;
        // ! <------------------------------------------------------- merge sort ----------------------------------------->

        // ? <---------------------------------------------drawing----------------------------------------->
        window.clear(sf::Color::Black);

        // draw the rectangles
        if (render) {
            for (long long int i = 0; i < n; i++) {
                if (i == current_num) {
                    sf::RectangleShape rectangle(sf::Vector2f(2, unique_numbers[i]));
                    rectangle.setPosition(60 + i * 2, 1000 - unique_numbers[i] - 40);
                    rectangle.setFillColor(sf::Color::Red);
                    window.draw(rectangle);
                }
                else {
                    sf::RectangleShape rectangle(sf::Vector2f(2, unique_numbers[i]));
                    rectangle.setPosition(60 + i * 2, 1000 - unique_numbers[i] - 40);
                    rectangle.setFillColor(sf::Color::White);
                    window.draw(rectangle);
                }
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