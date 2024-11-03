#include <gtest/gtest.h>
#include <vector>
#include <string>

// Function declaration
int countUniqueWords(const std::vector<char>& book);

class CountUniqueWordsTest : public ::testing::Test {
protected:
    // Helper function to create a vector of chars from a string
    std::vector<char> createTestBook(const std::string& text) {
        return std::vector<char>(text.begin(), text.end());
    }
};

TEST_F(CountUniqueWordsTest, CountUniqueWordsBasic) {
    // Create test input with some words
    std::vector<char> bookContent = createTestBook("Hello World Hello");

    // Call the function to count unique words
    int uniqueCount = countUniqueWords(bookContent);
    
    // Expect 2 unique words: "Hello" and "World"
    EXPECT_EQ(uniqueCount, 2);
}
/*
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/


