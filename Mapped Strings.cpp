#include <iostream>
#include <vector>
#include <string>

void generateStrings(const std::string& numStr, const std::string& mapping, std::string current, int index) {
    if (index == numStr.length()) {
        std::cout << current << std::endl;
        return;
    }
    int singleDigit = numStr[index] - '0';
    if (singleDigit >= 1 && singleDigit <= 9) {
        generateStrings(numStr, mapping, current + mapping[singleDigit - 1], index + 1);
    }

    if (index + 1 < numStr.length()) {
        int twoDigits = (numStr[index] - '0') * 10 + (numStr[index + 1] - '0');
        if (twoDigits >= 10 && twoDigits <= 26) {
            generateStrings(numStr, mapping, current + mapping[twoDigits - 1], index + 2);
        }
    }
}

int main() {
    std::string numStr;
    std::cin >> numStr;

    std::string mapping = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    generateStrings(numStr, mapping, "", 0);

    return 0;
}
