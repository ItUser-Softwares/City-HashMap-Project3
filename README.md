# City Hash Map Project

This C++ project demonstrates the use of hash maps to store and retrieve city data from a CSV file using different hashing strategies. The data is sourced from `US_Cities_Data.csv`, which contains information on various U.S. cities.

## 📁 Project Structure

* `City.h` – Defines the `City` class with attributes and a display method.
* `HashMapVector.h` – Implements a hash table using a vector of vectors, with support for three hashing functions.
* `main.cpp` – Provides a CLI menu for loading and displaying city data using different hash strategies.
* `HashAnalysis.docx` – Explains the logic and performance of each hash function.
* `US_Cities_Data.csv` – CSV dataset containing the city records.

## 🚀 Features

* Three hash functions:

  * **Bad Hash:** Uses the ASCII value of the first character.
  * **Better Hash:** Sums all ASCII characters.
  * **Best Hash:** Uses the djb2 algorithm.
* Displays bucket contents in a clean, formatted output.
* Tracks and displays the number of collisions per hash strategy.
* Menu-driven interface for interaction.

## 📊 Sample Menu

```
Menu:
1. Display table with bad hash
2. Display table with better hash
3. Display table with best hash
4. Exit
```

## 🧠 Hash Function Insights

* Collisions are reduced significantly from bad to best.
* djb2 provides the most even distribution.
* Detailed analysis provided in `HashAnalysis.docx`.

## ✅ How to Compile and Run

Ensure you have a C++ compiler (e.g., g++) and run:

```bash
g++ main.cpp -o CityHash
./CityHash
```

## 📝 Acknowledgements

* djb2 hash algorithm by Daniel J. Bernstein.
* Project instructions provided as part of Lab 7 coursework.
* AI assistance from OpenAI's ChatGPT for structuring and formatting.

