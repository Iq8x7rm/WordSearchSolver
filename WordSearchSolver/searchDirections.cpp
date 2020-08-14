/* Includes functions for searching whether a specific word is present in the puzzle
    as well as a function to display the puzzle(in a word search grid) */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>


std::string searchUp (std::string wordToFind, int currRow, int currColumn, 
int rows, int columns, std::vector<std::vector<char>> puzzle) {
    
    int counter = 1;

    while (counter != wordToFind.size()) {
        if (currRow-counter >= 0 && 
            puzzle.at(currColumn).at(currRow-counter) == wordToFind[counter]) {}
        else {
            return("");
        }
        // Adding to counter allows while loop to go to the next character
        ++counter;
    }

    return("Found " + wordToFind + " at " + std::to_string(currColumn+1) + ", " + std::to_string(currRow+1));

}

std::string searchDown (std::string wordToFind, int currRow, int currColumn, 
int rows, int columns, std::vector<std::vector<char>> puzzle) {
    
    int counter = 1;

    while (counter != wordToFind.size()) {
        if (currRow+counter < rows && 
            puzzle.at(currColumn).at(currRow+counter) == wordToFind[counter]) {}
        else {
            return("");
        }
        // Adding to counter allows while loop to go to the next character
        ++counter;
    }
    
    return("Found " + wordToFind + " at " + std::to_string(currColumn+1) + ", " + std::to_string(currRow+1));

}

std::string searchLeft (std::string wordToFind, int currRow, int currColumn, 
int rows, int columns, std::vector<std::vector<char>> puzzle) {

    int counter = 1;
    
    while (counter != wordToFind.size()) {
        if (currColumn-counter >= 0 && 
            puzzle.at(currColumn-counter).at(currRow) == wordToFind[counter]) {}
        else {
            return("");
        }
        // Adding to counter allows while loop to go to the next character
        ++counter;
    }
    
    return("Found " + wordToFind + " at " + std::to_string(currColumn+1) + ", " + std::to_string(currRow+1));

}

std::string searchRight(std::string wordToFind, int currRow, int currColumn, 
int rows, int columns, std::vector<std::vector<char>> puzzle) {

    int counter = 1;
    
    while (counter != wordToFind.size()) {
        if (currColumn+counter < columns && 
            puzzle.at(currColumn+counter).at(currRow) == wordToFind[counter]) {}
        else {
            return("");
        }
        // Adding to counter allows while loop to go to the next character
        ++counter;
    }
    
    return("Found " + wordToFind + " at " + std::to_string(currColumn+1) + ", " + std::to_string(currRow+1));

}

std::string searchUpLeft (std::string wordToFind, int currRow, int currColumn, 
int rows, int columns, std::vector<std::vector<char>> puzzle) {

    int counter = 1;
    
    while (counter != wordToFind.size()) {
        if (currColumn-counter >= 0 && currRow-counter >= 0 && 
            puzzle.at(currColumn-counter).at(currRow-counter) == wordToFind[counter]) {}
        else {
            return("");
        }
        // Adding to counter allows while loop to go to the next character
        ++counter;
    }
    
    return("Found " + wordToFind + " at " + std::to_string(currColumn+1) + ", " + std::to_string(currRow+1));

}

std::string searchUpRight (std::string wordToFind, int currRow, int currColumn, 
int rows, int columns, std::vector<std::vector<char>> puzzle) {

    int counter = 1;
    
    while (counter != wordToFind.size()) {
        if (currColumn+counter < columns && currRow-counter >= 0 && 
            puzzle.at(currColumn+counter).at(currRow-counter) == wordToFind[counter]) {}
        else {
            return("");
        }
        // Adding to counter allows while loop to go to the next character
        ++counter;
    }
    
    return("Found " + wordToFind + " at " + std::to_string(currColumn+1) + ", " + std::to_string(currRow+1));

}

std::string searchDownLeft (std::string wordToFind, int currRow, int currColumn, 
int rows, int columns, std::vector<std::vector<char>> puzzle) {

    int counter = 1;

    while (counter != wordToFind.size()) {
        if (currColumn-counter >= 0 && currRow+counter < rows && 
            puzzle.at(currColumn-counter).at(currRow+counter) == wordToFind[counter]) {
            }
        else {
            return("");
        }
        // Adding to counter allows while loop to go to the next character
        ++counter;
    }

    return("Found " + wordToFind + " at " + std::to_string(currColumn+1) + ", " + std::to_string(currRow+1));

}

std::string searchDownRight (std::string wordToFind, int currRow, int currColumn, 
int rows, int columns, std::vector<std::vector<char>> puzzle) {

    int counter = 1;
    
    while (counter != wordToFind.size()) {
        if (currColumn+counter < columns && currRow+counter < rows && 
            puzzle.at(currColumn+counter).at(currRow+counter) == wordToFind[counter]) {}
        else {
            return("");
        }
        // Adding to counter allows while loop to go to the next character
        ++counter;
    }
  
    return("Found " + wordToFind + " at " + std::to_string(currColumn+1) + ", " + std::to_string(currRow+1));

}

void displayPuzzle (int rows, int columns, std::vector<std::vector<char>> puzzle) {
    std::cout << std::endl;
    
    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < columns; ++i) {
            std::cout << puzzle.at(i).at(j) << ' ';
        }
         std::cout << std::endl;
    }

    std::cout << std::endl;
}
