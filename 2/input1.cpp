#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("./input1.txt");

    if (!inFile) {
        exit(1);
    }

    int countTwo = 0;
    int countThree = 0;
    string line;
    while (inFile >> line) {
        map<char, int> frequencies;
        for (int i = 0; i < line.length(); ++i) {
            char c = line.at(i);
            auto it = frequencies.find(c);
            frequencies.insert(
                make_pair(c, (it != frequencies.end()) ? (++it->second) : 1)
            );
        }

        bool countTwoNotSet = true;
        bool countThreeNotSet = true;
        for (
            auto it = frequencies.begin();
            it != frequencies.end() && (countTwoNotSet || countThreeNotSet);
            ++it
        ) {
            if (it->second == 2 && countTwoNotSet) {
                countTwo += 1;
                countTwoNotSet = false;
            }
            if (it->second == 3 && countThreeNotSet) {
                countThree += 1;
                countThreeNotSet = false;
            }
        }
    }

    cout << countThree << endl;
    cout << countTwo << endl;
    int checkSum = countThree * countTwo;
    cout << checkSum << endl;
    return 0;
}
