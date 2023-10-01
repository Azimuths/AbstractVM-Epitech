/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** main
*/

#include <iostream>
#include <string>
#include "Defines.hpp"
#include "AssemblyParser.hpp"
#include "AbstractVMCore.hpp"
#include "Stack.hpp"
#include "Int8.hpp"

int CheckArgs(int argc, char **argv)
{
    if (!argv) {
        return UNDEFINED_POINTER_ERROR;
    }
    if (argc > 2) {
        return EXIT_INVALID_ARGUMENT_NUMBER;
    }
    if (argc == 2) {
        std::string arg1 = std::string(argv[1]);
        if (arg1 == "-h" || arg1 == "--help") {
            std::cout << "\tUSAGE" << std::endl;
            std::cout << "\t./abstractVM [file]\n" << std::endl;
            std::cout << "\tDESCRIPTION" << std::endl;
            std::cout << "\tfile\tfile that contains the instructions" << std::endl;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
    int error = CheckArgs(ac, av);
    if (error != EXIT_SUCCESS) {
        return error;
    }
    Factory factory;
    AbstractVMCore core;
    AbstractVM::Stack stack;
    AssemblyParser parser;
    parser.setFactory(factory);
    if (ac == 1) {
        error = core.LoopMode(parser);
    } if (ac == 2) {
        error = core.OneShotMode(parser, std::string(av[1]));
    }
    if (error != EXIT_SUCCESS) {
        return EXIT_GENERAL_ERROR;
    }
    return EXIT_SUCCESS;
}