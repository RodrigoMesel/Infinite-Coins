#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Change {
public:
    int value;
    vector<int> types;
    vector<vector<vector<int>>> dynamicProgramming;
    set < vector < int >> solution;

    Change(int v) : value(v) {
        types = {1, 5, 10, 25};
        dynamicProgramming.resize(value + 1, vector<vector<int>>());

        dynamicProgramming[0].emplace_back(types.size(), 0); // Caso base de 0 moedas
    }

    void DynamicProgramming () {
        /**
         * The function bellow will
         * - Do a dynamicProgramming to calculate the solution in a faster way
         * - The first loop will iterate on each type of coin
         * - The second loop will iterate from the value of the actual coin until the total value. J is the remaining change
         * - The third loop will progressively build all possible combinations that add up to J, considering the addition of the current currency.
         */


        for (int i = 0; i < types.size(); ++i) {
            for (int j = types[i]; j <= value; ++j) {
                for (auto &prevCombo : dynamicProgramming[j - types[i]]) {
                    vector<int> newCombo = prevCombo;
                    newCombo[i]++;
                    dynamicProgramming[j].push_back(newCombo);
                }
            }
        }
    }

    set <vector<int>> changeMaker() {
        /**
         * The function bellow will
         * - Call the DynamicProgramming
         * - Store the result at the set
         * - Return the set
         */
        DynamicProgramming();

        for (auto &combo : dynamicProgramming[value]) {
            solution.insert(combo);
        }

        return solution;

    }

};

int main() {
    int value;
    cin >> value;
    Change c(value);
    set <vector< int>> output = c.changeMaker();

    return 0;
}
