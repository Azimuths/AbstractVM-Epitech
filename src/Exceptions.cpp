/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** Exceptions
*/

#include "Exceptions.hpp"

AbstractVM::Exception::Exception()
{
}

AbstractVM::Exception::~Exception()
{
}

const char *AbstractVM::Exception::what() const throw()
{
    return "General Error\n";
}
