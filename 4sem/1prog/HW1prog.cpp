#include <iostream>
#include <algorithm>	
#include <string>
#include <map>
#include <fstream>
#include <iterator>
#include <vector>
#include <cctype>

/*
в с++ можно
using mapT = std::map<std::string,int>; Ok
*/
typedef std::map<std::string,int>  mapT;

struct statistics
{
  int count;
  std::string word;
};

void prepare(std::string& word)
{
  std::transform(word.begin(), word.end(), word.begin(), ::tolower);
  word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
}

void map_create(const mapT& words)
{
  std::cout << "Map_create starting" << "\n";
  std::ifstream input("input.txt");

  if (input.is_open())
  {
    std::string word;    
    while(!input.eof())
    {
      input >> word;		
      prepare(word);

      if (!word.empty())
        words[word]++;
      word = "";
    }
  }
  
  std::cout << "Map complete" << "\n";
  input.close();
  std::cout << "Input_close complete" << "\n";
}

/*
fixit:
лучше передать константную ссылку на words DONE
*/
void vector_create(mapT words, std::vector<statistics>& vwords)
{
  std::cout << "Vector_create starting" << "\n";
  mapT::iterator it;
  statistics stat;
  
  /*
  вам точто 
  for (const auto& pair : words)
  {
    stat.word = pair.first  Меньше)
    ...
  }
  меньше нравится?)
  */
  for (it = words.begin(); it != words.end(); it++)
  {
    stat.word = (*it).first;
    stat.count = (*it).second;
    vwords.push_back(stat);
  }

  std::cout << "Vector_create complete" << "\n";
}

bool comparator(const statistics& lhs, const statistics& rhs)
{
  return rhs.count < lhs.count;
}

int data_input()
{
  int words_amount = 0;
  std::cout << "Input the amount of words to output \n" << std::endl;
  std::cin >> words_amount;

  return words_amount;
}
 
int main()
{
  std::ofstream output("output.txt");
  int words_amount = data_input();
  mapT words;
  map_create(words);
  std::vector<statistics> vwords;
  vector_create(words, vwords);
  
  std::sort(vwords.begin(), vwords.end(), comparator); 
 
  int num = std::min(words_amount, (int) vwords.size());
  for (int i = 0; i < num; i++)
    output << "Place: " << i+1 << " " << vwords[i].count << " " << vwords[i].word << std::endl;

  output.close(); 
  std::cout << "Successfully completed"<< "\n";     
  return 0;
}
