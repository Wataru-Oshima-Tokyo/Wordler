#include "dictionary.h"
#include <vector>
#include <string>
#include <fstream>

// initiate word dictionary from file .wordler.data and store them as a 
// list of upper case letters
dictionary::dictionary(){
    dictionary_file = DEFAULT_DICTIONARY; // default file
    load_dictionary(dictionary_file);
}

// loads words from file name passed in as long as it includes
// at least one word
void dictionary::load_dictionary(std::string file){
    std::ifstream read(file);
    std::vector <std::string> temp;

    if( !read.is_open() ){
        return;
    }
    else{
        std::string word;
        while( getline(read,word) ){
            //convert every word to UPPER CASE
            for(int i=0; i<word.length(); i++){
                word[i] = toupper(word[i]);
            }
           temp.push_back(word);
        }
    }

    if( temp.size() > 0 ){
        words = temp;
        dictionary_file = file;
    }
    read.close();
}

// returns the name of the file that was most recently used to 
// load the current dictionary
std::string dictionary::file_name(){
    return dictionary_file;
}

// select a random word from our dictionary and return it
std::string dictionary::select_word(){
    return words.at(rand() % words.size());
}

// return a word from our dictionary given a seed as an index
std::string dictionary::select_word(int seed){
    return words.at(seed % words.size());
}

// retrieves the number of words currently in the dictionary
int dictionary::size(){
    return words.size();
}