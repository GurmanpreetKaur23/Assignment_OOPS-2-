#include <iostream>
#include <vector>

void SubsetsWithSum(const std::vector<int>& array, int idx, int current_sum, int target_sum, std::vector<int>& subset) {
    if (idx == array.size()) {
        if (current_sum == target_sum) {
            for (int num : subset) {
                std::cout << num << " ";
            }
            std::cout <<"  ";
        }
        return;
    }

    subset.push_back(array[idx]);
    SubsetsWithSum(array, idx + 1, current_sum + array[idx], target_sum, subset);
    subset.pop_back(); 

    SubsetsWithSum(array, idx + 1, current_sum, target_sum, subset);
}

int countSubsetsWithSum(const std::vector<int>& array, int idx, int current_sum, int target_sum) {
    if (idx == array.size()) {
        if (current_sum == target_sum) {
            return 1;
        }
        return 0;
    }

    int includeCount = countSubsetsWithSum(array, idx + 1, current_sum + array[idx], target_sum);

    int excludeCount = countSubsetsWithSum(array, idx + 1, current_sum, target_sum);

    return includeCount + excludeCount;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> array(N);

    for (int i = 0; i < N; i++) {
        std::cin >> array[i];
    }

    int target_sum;
    std::cin >> target_sum;

    std::vector<int> subset;
    SubsetsWithSum(array, 0, 0, target_sum, subset);

    int count = countSubsetsWithSum(array, 0, 0, target_sum);
    std::cout <<"\n"<<count << std::endl;

    return 0;
}
