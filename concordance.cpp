#include "concordance.h"

Concordance::Concordance(std::string filename)
{
    m_filename = filename;
}

void Concordance::parse()
{
    std::ifstream file(m_filename.c_str());
    while(!file.eof())
    {
        std::string word = next_word(file);
        std::cout << "Enter word to search: " << std::endl;
        getline(std::cin, word);
        std::string s;
        int count = 0;
        int line=0;
        while(file >>s)
        {
            if (s == word)
            {
         
                count++;
            }
        }
        std::cout << word<<": " <<count;
    while( getline(file, s))
    {
           if( s==word)
           {
               line++;
           }
           std::cout << line << ": ";
    }
std::cout << std:: endl;
    
        
        // implement the rest of this function
        // This is just to see the words as they are printed out.
        // The word may have some puncuation attached to it, this
        // will be ok for this example.
      //  std::cout << word <<": " << count;
    }
}

bool Concordance::is_whitespace(char c)
{
  return (c == ' ' || c == '\n' ||  c == '\t');
}

void Concordance::eat_whitespace(std::ifstream& input)
{
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            input.putback(c); // this will put the character back on the input stream
            break;
        }
    }
}

std::string Concordance::next_word(std::ifstream& input)
{
    std::string word;
    for(;;)
    {
        char c;
        input.get(c);
        if(input.eof())
            break;
        if(!is_whitespace(c))
        {
            word += c;
        }
        else
        {
            eat_whitespace(input);
            break;
        }
    }
    return word;
}
int Concordance::find_word(std::string word)
{
    // search the Word vector, and return the index in the vector.
}

void Concordance::print()
{
    // print out the concordance 
 
}
