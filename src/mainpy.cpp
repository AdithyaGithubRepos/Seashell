#include <iostream>
#include <fstream>
#include <string>

std::string filename;
std::string operation;
std::string function;


void compile(const std::string& filename)
{
    std::ofstream outfile("out.py");
    outfile << "print(\"Compiled in shllpy\")";


   


    outfile.close();
}

void py(const std::string& filename)
{
    std::cout << "shllpy v1, compiling" << std::endl;
    std::string line;
    std::ifstream file(filename);
    while (getline(file, line))
    {
       if (line=="compile")
       {
        compile(filename);
       }
    }
}



int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: (shll_) something.shll" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string filename = argv[1];
    py(filename);
    
    return 0;
}
