/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand *Factory::createOperand(eOperandType type,  const std::string &value) const
{
    std::stringstream ss;
    ss.unsetf(std::ios::floatfield);

    if (type == eOperandType::Int8) {
        if (std::stoi(value) > CHAR_MAX || std::stoi(value) < CHAR_MIN)
            throw AbstractVM::Exception();
        ss << std::stoi(value);
        return new AbstractVM::Int8(ss.str(), *this);
    }
    if (type == eOperandType::Int16) {
        if (std::stoi(value) > SHORT_MAX || std::stoi(value) < SHORT_MIN)
            throw AbstractVM::Exception();
        ss << std::stoi(value);
        return new AbstractVM::Int16(ss.str(), *this);
    }
    if (type == eOperandType::Int32) {
        std::stoi(value);
        ss << std::stoi(value);
        return new AbstractVM::Int32(ss.str(), *this);
    }
    if (type == eOperandType::Float) {
        std::stof(value);
        ss.unsetf(std::ios::floatfield);
        ss.precision(7);
        ss << std::stof(value);
        return new AbstractVM::Float(ss.str(), *this);
    }
    if (type == eOperandType::Double) {
        std::stoi(value);
        ss.unsetf(std::ios::floatfield);
        ss.precision(15);
        ss << std::stod(value);
        return new AbstractVM::Double(ss.str(), *this);
    }
    return nullptr;
}
