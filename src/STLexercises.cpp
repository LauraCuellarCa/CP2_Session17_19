#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

//milestone 1
std::vector<char> readBook(std::string pg2701){
    std::ifstream file(pg2701);
    std::vector<char> book;
    char c;
    while(file.get(c)){
        if(std::isalpha(c)){
            book.push_back(c);
        }
        else {
            book.push_back(' ');
        }
    }
    return book;
}

//milestone 2
std::map<std::string, int> computeWordFrequency(const std::vector<char>& book){
    //using std::stringstream
    std::map<std::string, int> wordFrequency;
    std::stringstream ss;
    for(char c : book){
        ss << c;
    }
    std::string word;
    while(ss >> word){
        wordFrequency[word]++;
    }
    return wordFrequency;
}

//milestone 3 
int countUniqueWords(const std::vector<char>& book){
    std::map<std::string, int> wordFrequency = computeWordFrequency(book);
    return wordFrequency.size();
}

//milestone 4
//sort the frequencies in decreasing order
std::multimap<int, std::string, std::greater<int>> sortFrequencies(const std::map<std::string, int>& frequencies) {
    std::multimap<int, std::string, std::greater<int>> sortedFrequencies;
    for (const auto& pair : frequencies) {
        sortedFrequencies.insert(std::make_pair(pair.second, pair.first));
    }
    return sortedFrequencies;
}

//milestone 5 (I used matplotlib and a separate python file to plot the graph)
void outputToFile(const std::multimap<int, std::string, std::greater<int>>& sortedFrequencies, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
        return;
    }
    
    int rank = 1;
    for (const auto& pair : sortedFrequencies) {
        outFile << rank << " " << pair.first << " " << pair.second << "\n";
        rank++;
    }
    outFile.close();
}

//milestone 6
void printHapaxLegomena(const std::multimap<int, std::string, std::greater<int>>& sortedFrequencies) {
    int hapaxCount = 0;
    std::vector<std::string> hapaxSamples;

    for (const auto& pair : sortedFrequencies) {
        if (pair.first == 1) { // If frequency is 1, it's a hapax legomenon
            hapaxCount++;
            if (hapaxSamples.size() < 10) { // Collect some samples to display
                hapaxSamples.push_back(pair.second);
            }
        }
    }

    // Print the number of hapax legomena and a few sample words
    std::cout << "Number of hapax legomena (words that occur only once): " << hapaxCount << std::endl;
    std::cout << "Some examples of hapax legomena:" << std::endl;
    for (const auto& word : hapaxSamples) {
        std::cout << word << std::endl;
    }
}


int main(){
    std::vector<char> book = readBook("pg2701.txt");
    std::map<std::string, int> wordFrequency = computeWordFrequency(book);
    std::set<std::pair<int, std::string>> wordFrequencySet;
    for(auto& pair : wordFrequency){
        wordFrequencySet.insert(std::make_pair(pair.second, pair.first));
    }
    /*
    for(auto& pair : wordFrequencySet){
        std::cout << pair.second << " : " << pair.first << std::endl;
    }
    */
    std::cout << "Number of unique words: " << countUniqueWords(book) << std::endl;
    std::multimap<int, std::string, std::greater<int>> sortedFrequencies = sortFrequencies(wordFrequency);
    for(auto& pair : sortedFrequencies){
        std::cout << pair.second << " : " << pair.first << std::endl;
    }
    outputToFile(sortedFrequencies, "output.txt");

    printHapaxLegomena(sortedFrequencies);



    return 0;
}

