/* This program takes in a text file and make a word search puzzle out of the letters from the text file.
After the puzzle is made, the user can enter a word and the program will search the puzzle for that word.
If a word is found, it will return a solution. */

/* Text file should have the number of rows listed on the first line, followed by number of columns on 
the second line, and each line proceeding should have a letter in it. The lines that have a letter 
should not have space(s) before the letter. Do not include empty lines in text file. 

ex. 
2
3
f
b
d
s
f
s
*/


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <set>
#include "searchDirections.cpp"


int main () {

    // Get name of input file
    std::string inputFile;
    std::cout << "Type in name of input file: ";
    std::cin >> inputFile;

    std::ifstream input(inputFile);

    // Get number of rows and columns from input file
    std::string rows = "";
    if (input) {
        getline(input, rows);
        std::cout << "Number of rows: " << rows << std::endl;
    }
    std::string columns = "";
    if (input) {
        getline(input, columns);
        std::cout << "Number of columns: " << columns << std::endl;
    }

    // Get all characters from input file and put them into a vector
    std::vector<char> puzzleChars;
    std::string element;
    getline(input, element);
    while (input) {
        
        puzzleChars.push_back(element[0]);
        
        getline(input, element);
    }

    std::cout << "Total number of characters: " << puzzleChars.size() << std::endl;

    // Create the board by populating puzzle with dummy vectors. Do this so the board is 2-d
    std::vector<std::vector<char>> puzzle;
    std::vector<char> dummy;
    for (int i = 0; i < std::stoi(columns); ++i) {
        puzzle.push_back(dummy);
    }
    // Now populate the 2-d puzzle with (real) characters from puzzleChars
    int currentColumn = 0;
    for (int i = 0; i < puzzleChars.size(); ++i) {
        
        puzzle.at(currentColumn).push_back(puzzleChars.at(i));

        ++currentColumn;
        if (currentColumn == std::stoi(columns)) {
            currentColumn = 0;
        }
    }

    displayPuzzle(stoi(rows), stoi(columns), puzzle);
    
    std::string wordToFind;
    std::cout << "Enter word to find: ";
    std::cin >> wordToFind;

    while (wordToFind != "quit") {
        int flag = 0;
        // Find the wordToFind
        for (int currRow = 0; currRow < stoi(rows); ++currRow) {
            for (int currColumn = 0; currColumn < stoi(columns); ++currColumn) {
                // if the first letter of wordToFind is found in puzzle
                if (puzzle.at(currColumn).at(currRow) == wordToFind[0]) {

                    /* Use a set so that if the following searches produce the 
                    same result, it won't duplicate*/
                    std::set<std::string> solutions;

                    solutions.insert(
                        searchUp(wordToFind, currRow, currColumn, stoi(rows), stoi(columns), puzzle)
                    ); 

                    solutions.insert(
                        searchDown (wordToFind, currRow, currColumn, stoi(rows), stoi(columns), puzzle)
                    );

                    solutions.insert(
                        searchLeft (wordToFind, currRow, currColumn, stoi(rows), stoi(columns), puzzle)
                    );

                    solutions.insert(
                        searchRight (wordToFind, currRow, currColumn, stoi(rows), stoi(columns), puzzle)
                    );

                    solutions.insert(
                        searchUpLeft (wordToFind, currRow, currColumn, stoi(rows), stoi(columns), puzzle)
                    );

                    solutions.insert(
                        searchUpRight (wordToFind, currRow, currColumn, stoi(rows), stoi(columns), puzzle)
                    );

                    solutions.insert(
                        searchDownLeft (wordToFind, currRow, currColumn, stoi(rows), stoi(columns), puzzle)
                    );

                    solutions.insert(
                        searchDownRight (wordToFind, currRow, currColumn, stoi(rows), stoi(columns), puzzle)
                    );

                    // Display all the solutions
                    for (auto solution : solutions) {
                        /* If the solution is not empty. If the solution is empty, 
                        then one of the search functions returned "" since that search 
                        function did not find a valid solution. */
                        if (solution.compare("") != 0) {std::cout << solution << std::endl;}
                    }
                }
            }
        }

        std::cout << std::endl << "Enter word to find: ";
        std::cin >> wordToFind;
    
    }
    

    return 0;
}
