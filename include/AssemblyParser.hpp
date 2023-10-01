/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** AssemblyParser
*/

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Defines.hpp"
#include "Factory.hpp"
#include "Instructions.hpp"
#include "Stack.hpp"

class AssemblyParser {
    public:
        AssemblyParser(std::string const &file_path);
        AssemblyParser();
        ~AssemblyParser();

        int Parse(AbstractVM::Stack &stack);
        int ExecuteLine(std::string const &line, AbstractVM::Stack &stack);
        int getFromString(std::string const &file);
        int Extract(std::string &FileToExtract);
        void setFactory(Factory &factory);
        bool checkLine(std::string &line);

    protected:
    private:
        int FindInstruction(std::vector<std::string> const &tokens);
        int getDataType(std::vector<std::string> const &tokens);
        std::string getDataValue(std::vector<std::string> const &tokens);
        std::vector<std::string> Tokenize(std::string const &line);
        AbstractVM::Instructions _instructions;
        std::string _fileBuffer;
        std::string _filePath;
        Factory _factory;
        int _exit;
};
