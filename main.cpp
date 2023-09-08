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
