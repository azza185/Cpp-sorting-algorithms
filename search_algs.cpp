#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // For std::is_sorted

// using the random_device stuff cause the rand fucntion is terrible at giving different numbers

// Quick Sort implementation
std::vector<int> quickSort(std::vector<int> inputList) {
    if (inputList.size() < 2) {
        return inputList;
    }
    int pivot = inputList[inputList.size() / 2];
    std::vector<int> less;
    std::vector<int> greater;
    for (int i = 0; i < inputList.size(); i++) {
        if (i == inputList.size() / 2) continue;
        if (inputList[i] <= pivot) {
            less.push_back(inputList[i]);
        } else {
            greater.push_back(inputList[i]);
        }
    }
    less = quickSort(less);
    greater = quickSort(greater);
    less.push_back(pivot);
    less.insert(less.end(), greater.begin(), greater.end());
    return less;
}

// Bubble Sort implementation
std::vector<int> bubbleSort(std::vector<int> inputList) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < inputList.size() - 1; i++) {
            if (inputList[i] > inputList[i + 1]) {
                std::swap(inputList[i], inputList[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
    return inputList;
}

// Bogo Sort implementation (inefficient, for fun)
std::vector<int> bogoSort(std::vector<int> inputList) {
    std::random_device rd;
    std::mt19937 gen(rd());
    while (!std::is_sorted(inputList.begin(), inputList.end())) {
        std::shuffle(inputList.begin(), inputList.end(), gen);
    }
    return inputList;
}

// Print elements of a list
void printList(const std::vector<int>& inputList) {
    for (int num : inputList) {
        std::cout << num << ", ";
    }
    std::cout << "\n\n";
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100000);
    std::vector<int> numbers;
    for (int i = 0; i < 20; i++) {
        numbers.push_back(dist(gen));
    }
    std::cout << "Original List:\n";
    printList(numbers);
    /* if using bogo sort pls lower the number of 
     elements otherwise it could take a while */
    std::vector<int> sorted = quickSort(numbers);
    std::cout << "Sorted List (Quick Sort):\n";
    printList(sorted);
    return 0;
}
