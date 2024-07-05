#include <iostream>
#include <fstream>
#include <string>

std::string filename;
std::string toprint;
std::string func;
std::string opp;

void write(const std::string& filename)
{
    std::ofstream outfile(filename, std::ios_base::app);
    outfile << "print(\"" + toprint + "\")" << std::endl;
    outfile.close();
}

void py(const std::string& filename)
{
    std::cout << "shllpy v1, compiling" << std::endl;
    std::string line;
    std::ifstream file(filename);
    while (getline(file, line))
    {
        if (line=="speak:")
        {
           while (getline(file, line))
           {
             toprint = line;
             write("out.py");
             break;
           }
           
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
