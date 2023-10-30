#include <iostream>
#include <string>
using namespace std;

class State {
public:
    State(string n, double e, double s)
        : name(n), energy_consumed(e), size(s) {
        // Calculate the land area needed for solar panels
        land_needed = (energy_consumed / 51) / 18;  // 51 BTUs per panel and 18 sq ft per panel
        percentage_needed = (land_needed / size) * 100;
    }

    double getPercentageNeeded() const {
        return percentage_needed;
    }

    string getName() const {
        return name;
    }

    // ... (other member functions and variables as necessary)

private:
    string name;
    double energy_consumed;  // in BTUs
    double size;  // in square miles
    double land_needed;  // in square miles
    double percentage_needed;  // percentage of the state's land
};

class Node {
public:
    State state;
    Node* next;
    Node(const State& s) : state(s), next(nullptr) {}
};
