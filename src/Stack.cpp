/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** Stack
*/

#include "Stack.hpp"

AbstractVM::Stack::Stack()
{
    for (int i = 0; i < 15; i++)
        _registers[i] = std::stack<IOperand *>();
}

AbstractVM::Stack::~Stack()
{
    IOperand *tmp;
    for (int i = 0; i < 15; i++) {
        while (!_registers[i].empty()) {
            tmp = _registers[i].top();
            _registers[i].pop();
        }
    }
    while (!_stack.empty()) {
        tmp = _stack.top();
        _stack.pop();
    }
}

void AbstractVM::Stack::push(IOperand *operand)
{
    _stack.push(operand);
}

void AbstractVM::Stack::pop()
{
    _stack.pop();
}

IOperand *AbstractVM::Stack::top()
{
    return _stack.top();
}

bool AbstractVM::Stack::empty()
{
    return _stack.empty();
}

std::stack<IOperand *> *AbstractVM::Stack::getStack()
{
    return &_stack;
}

int AbstractVM::Stack::size()
{
    return _stack.size();
}

std::stack<IOperand *> *AbstractVM::Stack::getRegister(int index)
{
    return &_registers[index];
}
