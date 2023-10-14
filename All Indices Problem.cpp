#include <iostream>
#include <vector>

std::vector<int> findIndices(const std::vector<int>& arr, int M, int currentIndex) {
    std::vector<int> indices;

    if (currentIndex == arr.size()) {
        return indices; 
    }

    if (arr[currentIndex] == M) {
        indices.push_back(currentIndex);
    }

    std::vector<int> remainingIndices = findIndices(arr, M, currentIndex + 1);
    indices.insert(indices.end(), remainingIndices.begin(), remainingIndices.end());

    return indices;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int M;
    std::cin >> M;

    std::vector<int> result = findIndices(arr, M, 0);

    if (result.empty()) {
        std::cout << M << std::endl;
    } else {
        for (int index : result) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
