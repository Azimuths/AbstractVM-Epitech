/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** Factory
*/

#pragma once

#include "IOperand.hpp"
#include <memory>

class Factory {
    public:
        Factory();
        ~Factory();

        IOperand *createOperand(eOperandType type, const std::string &value) const;
    protected:
    private:
};
