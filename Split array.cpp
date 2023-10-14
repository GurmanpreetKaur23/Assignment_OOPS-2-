#include <iostream>
#include <vector>

void countWaysToSplit(const std::vector<int>& array, int idx, int Sum1, int Sum2, int& count) {
    if (idx == array.size()) {
        if (Sum1 == Sum2) {
            count++;
        }
        return;
    }

    countWaysToSplit(array, idx + 1, Sum1 + array[idx], Sum2, count);

    countWaysToSplit(array, idx + 1, Sum1, Sum2 + array[idx], count);
}

void findWaysToSplit(const std::vector<int>& array, int idx, int Sum1, int Sum2, std::vector<int>& group1, std::vector<int>& group2) {
    if (idx == array.size()) {
        if (Sum1 == Sum2) {
            for (int num : group1) {
                std::cout << num << " ";
            }
            std::cout << "and ";
            for (int num : group2) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        return;
    }
    group1.push_back(array[idx]);
    findWaysToSplit(array, idx + 1, Sum1 + array[idx], Sum2, group1, group2);
    group1.pop_back(); 

    group2.push_back(array[idx]);
    findWaysToSplit(array, idx + 1, Sum1, Sum2 + array[idx], group1, group2);
    group2.pop_back(); 

}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> array(N);

    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }

    std::vector<int> group1, group2;
    findWaysToSplit(array, 0, 0, 0, group1, group2);

	int count = 0;
    countWaysToSplit(array, 0, 0, 0, count);
    std::cout <<count << std::endl;

    return 0;
}
