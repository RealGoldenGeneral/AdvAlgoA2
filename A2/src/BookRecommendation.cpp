//
// Created by goldengeneral on 04/03/24.
//

#include <iostream>
#include <vector>
#include "../include/Utils.h"
#include "../include/Stack.h"
#include "../include/UnorderedSet.h"
#include "../include/HashTable.h"
#include "../include/BookRecommendation.h"

void BookRecommendation::addUserBorrowedBook(Patron &userID, Book &book) {

}

std::vector<Book> BookRecommendation::getBookRecommendations(const std::string &targetUserID, int numRecommendations,
                                                             int neighborhoodSize) {

}

double BookRecommendation::calculateSimilarity(const std::string &userID1, const std::string &userID2) {

}

UnorderedSet<std::string> BookRecommendation::getNeighborhood(const std::string &targetUserID, int neighborhoodSize) {

}

UnorderedSet<Book> BookRecommendation::getRecommendedBooks(const UnorderedSet<std::string> &neighborhood,
                                                           const std::string &targetUserID) {

}