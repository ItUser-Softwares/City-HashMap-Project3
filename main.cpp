#include "hash_map_vector.h"
#include <fstream>
#include <sstream>


int hashBad(const std::string& s) {
    return (int)s[0] % 100;
}
int hashBetter(const std::string& s) {
    int sum = 0; for (char c : s) sum += c; return sum % 100;
}
int hashBest(const std::string& s) {
    unsigned long hash = 5381; for (char c : s) hash = ((hash << 5) + hash) + c; return hash % 100;
}

City parseCity(const std::string& line) {
    std::stringstream ss(line);
    std::string cityName, stateID, stateName, countyName, populationStr, landAreaStr;
    getline(ss, cityName, ',');
    getline(ss, stateID, ',');
    getline(ss, stateName, ',');
    getline(ss, countyName, ',');
    getline(ss, populationStr, ',');
    getline(ss, landAreaStr);
    return City(cityName, stateID, stateName, countyName, stoi(populationStr), stod(landAreaStr));
}

void loadCities(HashMapVector& map, const std::string& fileName, int (*hashFunc)(const std::string&)) {
    std::ifstream file(fileName);
    std::string line;
    getline(file, line); // Skip header
    while (getline(file, line)) {
        City city = parseCity(line);
        map.insert(city, hashFunc);
    }
}

int main() {
    const std::string file = "US_Cities_Data.csv";
    int choice;
    do {
        std::cout << "\nMenu:\n1. Display table with bad hash\n2. Display table with better hash\n3. Display table with best hash\n4. Exit\nChoice: ";
        std::cin >> choice;
        if (choice >= 1 && choice <= 3) {
            HashMapVector map(100);
            if (choice == 1) loadCities(map, file, hashBad);
            else if (choice == 2) loadCities(map, file, hashBetter);
            else loadCities(map, file, hashBest);
            map.displayTable();
            std::cout << "\nCollisions: " << map.countCollisions() << "\n";
        }
    } while (choice != 4);
    return 0;
}