#include "iostream"
#include "fstream"
#include "cstring"
#include "string"

std::string filename;
std::string toprint;
std::string function;
std::string opp;
std::string outfilename = "out.lua";
std::ofstream outfile(outfilename, std::ios_base::app);

void write(const std::string& filename)
{
    outfile << "print(\"" + toprint + "\")" << std::endl;
}

void finalized()
{
    // ...
    outfile.close();
}

void lu(const std::string& filename)
{
    std::cout << "shllu v1, compiling, please make sure that any out.lua file in this directory is deleted to prevent overwriting\n" << std::endl;
    std::string line;
    std::ifstream file(filename);
    while (getline(file, line))
    {
        if (line == "speak:")
        {
            while (getline(file, line))
            {
                toprint = line;
                write(filename);
                break;
            }
        }
    }
}

int main(int argc, char* argv[])
{
   if(argc != 2)
    {
        std::cerr << "usage: (shll_) something.shll" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string filename = argv[1];

    lu(filename);
    finalized();
    return 0;
}