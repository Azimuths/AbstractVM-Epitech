/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** AbstractVMCore
*/

#include "AbstractVMCore.hpp"

AbstractVMCore::AbstractVMCore()
{
}

AbstractVMCore::~AbstractVMCore()
{
}

int AbstractVMCore::LoopMode(AssemblyParser parser)
{
    std::string file;
    std::string line;
    AbstractVM::Stack stack;
    std::string filename = "instructions.avm";
    std::ofstream newFile(filename);
    int exit = EXIT_FAILURE;

    while (std::cin) {
        getline(std::cin, line);
        if (line[0] == ';' && line[1] != ';' || line[0] == '\n' || line.empty()) {
            continue;
        }
        if (line == ";;")
            break;
        line.append("\n");
        file.append(line);
    }
    newFile << file;
    newFile.close();
    parser.Extract(filename);
    exit = parser.Parse(stack);
    if (exit != EXIT_SUCCESS)
        std::cerr << "Program failed to execute properly" << std::endl;
    return exit;
}

int AbstractVMCore::OneShotMode(AssemblyParser parser, std::string fileToParse)
{
    AbstractVM::Stack stack;
    int exit = EXIT_FAILURE;

    parser.Extract(fileToParse);
    exit = parser.Parse(stack);
    if (exit != EXIT_SUCCESS)
        std::cerr << "Program failed to execute properly" << std::endl;
    return exit;
}
