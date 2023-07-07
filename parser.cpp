#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
#include<unordered_map>

//convert  to lowercase


std::string toLowercase(const std::string& str){
    std::string result=str;
    std::transform(result.begin(),result.end(),result.begin(),[](unsigned char c){
        return std:: tolower(c);
    });
    return result;
}

//remove punctuation in the string
std::string removePunctuation(const std::string& str){
    std::string result=str;
    result.erase(std::remove_if(result.begin(),result.end(),[](unsigned char c){
        return std::ispunct(c);
    }),
    result.end());
    return result;
}
//parse a document to extract the words
std::vector<std::string> parseDocument(const std:: string& filename){
    std::ifstream file(filename);
    std::vector<std::string>words;

    if(file.is_open()){
        std::string line;
        while(std:: getline(file,line)){
            std::istringstream iss(line);
            std::string word;
            while(iss >> word){
                //remove punctuation and convert to lowercase
                word =removePunctuation(toLowercase(word));
                if(!word.empty()){
                    words.push_back(word);
                }
            }
        }
        file.close();
    }
    return words;
}


// invertedd index

std ::unordered_map<std::string, std::vector<std::string>> buildInvertedIndex(const std::vector<std::string>& documents){
    std::unordered_map<std::string, std::vector<std::string>> invertedIndex;

    for(const auto& document : documents){
        std::vector<std::string> words =parseDocument(document);
        for(const auto& word :words){
            invertedIndex[word].push_back(document);
        }
    }
    return invertedIndex;
}
int main(){
   std::vector<std::string> documents ={"guide.txt","sample.txt"};
   std::unordered_map<std::string, std::vector<std::string>>invertedIndex = buildInvertedIndex(documents);

   for(const auto& entry : invertedIndex) {
    std::cout <<entry.first << ": ";
    for(const auto& document : entry.second){
        std::cout << document << ": ";
    }
    std::cout <<std::endl;
   }
    
       return 0;
}