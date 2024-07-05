#include "iostream"
#include "fstream"
#include "cstring"
#include "string"
#include "cstdlib"
#include "regex"
#include "cstdio"

std::string filename;
std::string toprint;
std::string function;
std::string opp;
std::string outfilename = "out.c";
std::ofstream outfile(outfilename, std::ios_base::app);

void writeStd() // write headers
{
    outfile << "#include <stdio.h>\n";
    outfile << "#include <stdlib.h>\n";
    outfile << "#include <unistd.h>\n";
    outfile << "#include <string.h>\n\n";
    outfile << "int main(){\n\n\n";
    
}

void write(const std::string &filename)
{
    outfile << "printf(\"" + toprint + "\");" << std::endl;
    
}

void finalize()
{
   outfile << "\n return 0;\n }" << std::endl;
   outfile.close();
}

void c(const std::string &filename)
{
    std::cout << "shllc v1, compiling, please make sure that any out.c file in this directory is deleted to prevent overwriting\n Make sure gcc is present!" << std::endl;
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

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: (shll_) something.shll" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string filename = argv[1];
    
    writeStd();
    c(filename);      // initialize and finalize
    finalize();

    system("gcc out.c -o shll.exe");
    system("gcc out.c -o shll.sh");
    system("gcc out.c -o shll.o");
    

    return 0;
}