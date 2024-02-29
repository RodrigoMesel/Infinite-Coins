#include <iostream>
#include <vector>
using namespace std;

class Set{
public:
    vector<vector < int >> set;

    bool contains(vector<int> e) {
        /**
         * The function bellow will
         * - Iterate on each element on the set trying to find an equal element. Returns true if there is an equal element and false otherwise
         */
        for (auto it : set) {
            if (it == e) {
                return true;
            }
        }

        return false;
    }

    void add(vector <int> e) {
        /**
         * The function bellow will
         * - Check if the element isnt in the set and insert in that case
         */

        if (!contains(e)) {
            set.emplace_back(e);
        }
    }

};

class Change {
public:
    int value;
    vector<int> coinsTypes;
    Set solution;

    Change(int v) {
        value = v;
        coinsTypes = {25, 10, 5, 1};
    }

    void findCombinations(vector<int>& combo, int coinIndex, int remainingValue) {

        /**
         * The function bellow will
         * - Check if the remaining change is 0, if so, it is a possible combination, so it add the combination to the solution set
         * - Check if there is any more type of coin to be tested
         * - If possible, use the actual coin and calculate every combination that includes the actual coin
         * - Calculate every combination without using the actual coin
         */


        if (remainingValue == 0) {
            solution.add(combo);
            return;
        }

        if (coinIndex >= coinsTypes.size()) {
            return;
        }

        if (coinsTypes[coinIndex] <= remainingValue) {
            combo[coinIndex]++;
            findCombinations(combo, coinIndex, remainingValue - coinsTypes[coinIndex]);
            combo[coinIndex]--;
        }

        findCombinations(combo, coinIndex + 1, remainingValue);
    }

    Set makeChange() {
        /**
         * The function bellow will
         * - Create a vector to store every partial result
         * - Call the findCombinations
         * - Return the result
         *
         *
         *
         * It was possible to do this in a more efficient way with dynamic programming but I couldn´t
         * do it without searching, so I prefered to do in a simple way but without searching :)
         */

        vector<int> combo(coinsTypes.size(), 0);
        findCombinations(combo, 0, value);
        return solution;
    }

};

int main() {
    int value;
    cin >> value;
    Change c(value);
    Set output = c.makeChange();

    return 0;
}
