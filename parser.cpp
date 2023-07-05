#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>

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

int main(){
    std::string filename ="sample.txt";
    std::vector<std::string> words = parseDocument(filename);

    //print extracted words
    for(const auto& word : words) {
        std::cout << word << std::endl;
    }
    return 0;
}