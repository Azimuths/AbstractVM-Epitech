/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** AbstractVMCore
*/

#pragma once

#include <iostream>
#include "AssemblyParser.hpp"

class AbstractVMCore {
    public:
        AbstractVMCore();
        ~AbstractVMCore();

        int LoopMode(AssemblyParser parser);
        int OneShotMode(AssemblyParser parser, std::string fileToParse);
    protected:
    private:
};
