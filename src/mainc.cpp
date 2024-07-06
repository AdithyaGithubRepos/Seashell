#include "iostream"
#include "fstream"
#include "cstring"
#include "string"
#include "cstdlib"
#include "regex"
#include "cstdio"
#include "stdexcept"

std::string filename;
std::string toprint;
std::string function;
std::string compileChoice;
std::string opp;
double towait; // wait func
std::string outfilename = "out.c";
std::string tosys; // System command
std::ofstream outfile(outfilename, std::ios_base::app);

void writeStd() // write headers
{

    outfile << "#include <stdio.h>\n";
    outfile << "#include <stdlib.h>\n";
    outfile << "#include <unistd.h>\n";
    outfile << "#include <string.h>\n\n";
    outfile << "int main(){\n\n\n";
}

void write()
{
    if (!toprint.empty())
    {
        outfile << "printf(\"" + toprint + "\");" << std::endl;
    }
    if (!tosys.empty())
    {
        outfile << "system(\"" + tosys + "\");" << std::endl;
    }
    if(towait > 0)
    {
        outfile << "sleep(" << towait << ");" << std::endl;
    }
    toprint.clear();
    tosys.clear();
    towait = 0;
}

void finalize()
{
    outfile << "\n return 0;\n }" << std::endl;
    outfile.close();
}

void debug() // macro for debugging
{
    std::cout << "test passed" << std::endl;
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
                write();
                break;
            }
        }
        if (line == "sysrun:")
        {
            while (getline(file, line))
            {
                tosys = line;
                write();
                break;
            }
        }
        if (line == "wait:")
        {
            try
            {
                while (getline(file, line))
                {
                    towait = std::stoi(line);
                    write();
                    break;
                }
            }
            catch (std::invalid_argument &e)
            {
                std::cerr << "Invalid int at function wait:\n compilation terminated" << std::endl;
                exit(EXIT_FAILURE);
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
    c(filename); // initialize and finalize
    finalize();

    std::cout << "Compile for which operating system? W for windows, L for linux and O for an object file.\n If you don't want to compile, Type K." << std::endl;
    std::cin >> compileChoice;
    if (compileChoice == "W")
    {
        system("gcc out.c -o shll.exe");
    }
    if (compileChoice == "L")
    {
        system("gcc out.c -o shll.sh");
    }
    if (compileChoice == "O")
    {
        system("gcc out.c -o shll.o");
    }
    if (compileChoice == "K")
    {
        exit(EXIT_SUCCESS);
    }

    return 0;
}