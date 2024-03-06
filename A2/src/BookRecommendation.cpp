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
    if (!userBorrowedBooks.search(userID.ID)) {
        userBorrowedBooks.insert(userID.ID, UnorderedSet<Book>());
    }

    if (!bookBorrowedByUsers.search(book.ISBN)) {
        bookBorrowedByUsers.insert(book.ISBN, UnorderedSet<Patron>());
    }

    // Add borrowed book to user's list of borrowed book
    userBorrowedBooks[userID.ID].insert(book);

    // Add the user to list of users who borrowed this book
    bookBorrowedByUsers[book.ISBN].insert(userID);
}

std::vector<Book> BookRecommendation::getBookRecommendations(const std::string &targetUserID, int numRecommendations,
                                                             int neighborhoodSize) {
    std::vector<Book> recommendations;

    // Get neighbourhood of similar users
    UnorderedSet<std::string> neighbourhood = getNeighborhood(targetUserID, neighborhoodSize);

    // Get recommended books based on neighbourhood
    UnorderedSet<Book> recommendedBooks = getRecommendedBooks(neighbourhood, targetUserID);

    // Convert UnorderedSet to vector
    for (const auto& book : recommendedBooks) {
        recommendations.push_back(book);
    }

    return recommendations;
}

double BookRecommendation::calculateSimilarity(const std::string &userID1, const std::string &userID2) {

    // Retrieve the set of books borrowed by each user
    const auto& books1 = userBorrowedBooks[userID1];
    const auto& books2 = userBorrowedBooks[userID2];

    // Calculate the size of the intersection of the two sets
    size_t intersectionSize = 0;
    for (const auto& book : books1) {
        if (books2.search(book)) {
            intersectionSize++;
        }
    }

    // Calculate the union size
    size_t unionSize = books1.size() + books2.size() - intersectionSize;

    // Calculate the Jaccard similarity score
    double similarity = static_cast<double>(intersectionSize) / unionSize;

    return similarity;
}

UnorderedSet<std::string> BookRecommendation::getNeighborhood(const std::string &targetUserID, int neighborhoodSize) {
    // Get set of all patron IDs (including the largest patron ID)
    UnorderedSet<std::string> patronIDs;
    for (const auto& entry : userBorrowedBooks)  {
        if (entry->key != targetUserID) {
            patronIDs.insert(entry->key);
        }
    }

    // Stack to keep track of the most similar users and their similarity scores
    Stack<std::pair<double, std::string>> similarityStack;

    // Calculate and store the similarity scores of all users with the target user
    for (const std::string& userID : patronIDs)  {
        double similarity = calculateSimilarity(targetUserID, userID);
        similarityStack.push({similarity, userID});
    }

    // Convert the Stack to an UnorderedSet to return the neighbourhood
    UnorderedSet<std::string> neighbourhood;
    while (!similarityStack.isEmpty() && neighborhoodSize > 0) {
        auto topUser = similarityStack.top();
        similarityStack.pop();
        neighbourhood.insert(topUser.second);
        neighborhoodSize--;
    }
}

UnorderedSet<Book> BookRecommendation::getRecommendedBooks(const UnorderedSet<std::string> &neighborhood,
                                                           const std::string &targetUserID) {
    // Create a HashTable to store the frequency of each book borrowed by users
    HashTable<Book, int> bookFrequency;

    // Iterate through the neighbourhood to find the frequency of each book
    for (const auto& userID : neighborhood) {
        if (userID != targetUserID) {
            // Get the set of books borrowed by the current user in the neighbourhood
            const UnorderedSet<Book>& borrowedBooks = userBorrowedBooks[userID];

            // Update the frequency of each book in the HashTable
            for (const Book& book : borrowedBooks) {
                bookFrequency[book]++;
            }
        }
    }

    // Create an UnorderedSet to store recommended books
    UnorderedSet<Book> recommendedBooks;

    // Iterate through the frequency map and add unborrowed books
    for (const auto& entry : bookFrequency) {
        const Book book = entry->key;
        int frequency = entry->value;

        // Check if target user has not borrowed the book
        if (frequency == 0)  {
            // Add the book to recommendedBooks
            recommendedBooks.insert(book);
        }
    }

    return recommendedBooks;
}