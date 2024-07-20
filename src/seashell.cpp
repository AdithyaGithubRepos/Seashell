#include "iostream"
#include "string"
#include "cstring"
#include "cstdlib"
#include "fstream"
#include "regex"
#include "sstream"

void exec(const std::string &code)
{
    std::regex pattern("speak\\[(\\d+)\\]\\s*\\{([^\\}]*)\\}");
    std::smatch matches;
    if (std::regex_search(code, matches, pattern))
    {
        int count = std::stoi(matches[1].str());
        std::string content = matches[2].str();
        
        std::istringstream cstream(content);
        std::string line;                                           // Basically number of times to print. note: cstream is content stream for short
        int lines = 0;
        while(std::getline(cstream, line) && lines <= count)
        {
            std::cout << line << std::endl;
            ++lines;
        }
    } else {
        std::cerr << "Invalid syntax at speak[], i am afraid i must stop the execution here.\n" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: seashell <file.shll>" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string filename = argv[1];
    std::ifstream file(filename);
    std::string line, code;
    while (std::getline(file, line))
    {
        code += line + "\n";
    }
    file.close();
    exec(code);

    return 0;
}