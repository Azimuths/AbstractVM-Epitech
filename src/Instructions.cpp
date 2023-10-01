/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** Instructions
*/

#include <cmath>
#include "Instructions.hpp"
#include "Exceptions.cpp"
#include "iomanip"

AbstractVM::Instructions::Instructions()
{
}

AbstractVM::Instructions::~Instructions()
{
}

void AbstractVM::Instructions::push(AbstractVM::Stack *stack, IOperand *operand)
{
    stack->push(operand);
}

bool AbstractVM::Instructions::pop(AbstractVM::Stack *stack, IOperand *operand)
{
    delete operand;
    if (stack->empty())
        return false;
    delete stack->top();
    stack->pop();
    return true;
}

void AbstractVM::Instructions::clear(AbstractVM::Stack *stack, IOperand *operand)
{
    delete operand;
    while (!stack->empty()) {
        stack->pop();
    }
}

bool AbstractVM::Instructions::dup(AbstractVM::Stack *stack, IOperand *operand)
{
    if (stack->empty()) {
        delete operand;
        return false;
    }
    IOperand *top = stack->top();
    delete operand;

    stack->push(top);
    return true;
}

bool AbstractVM::Instructions::swap(AbstractVM::Stack *stack, IOperand *operand)
{
    if (stack->size() < 2) {
        delete operand;
        return false;
    }
    IOperand *top = stack->top();

    delete operand;
    stack->pop();
    IOperand *second = stack->top();
    stack->pop();
    stack->push(top);
    stack->push(second);
    return true;
}

void AbstractVM::Instructions::dump(AbstractVM::Stack *stack, IOperand *operand)
{
    std::stack<IOperand *> tmp = *stack->getStack();
    std::stringstream ss;
    int index = 0;

    delete operand;
    while (!tmp.empty()) {
        ss.clear();
        ss.str(std::string());
        if (tmp.top()->getType() == Float) {
            ss.unsetf(std::ios::floatfield);
            ss.precision(7);
            ss << tmp.top()->toString();
            std::cout << ss.str() << std::endl;
        } else if (tmp.top()->getType() == Double) {
            ss.unsetf(std::ios::floatfield);
            ss.precision(15);
            ss << tmp.top()->toString();
            std::cout << ss.str() << std::endl;
        } else
            std::cout << tmp.top()->toString() << std::endl;
        tmp.pop();
        index += 1;
    }
}

bool AbstractVM::Instructions::assert(AbstractVM::Stack *stack, IOperand *operand)
{
    if (stack->empty()) {
        std::cerr << "Error: Assert failed" << std::endl;
        return false;
    }
    IOperand *top = stack->top();

    if (top->getType() != operand->getType() || top->toString().compare(operand->toString()) != 0) {
        std::cerr << "Error: Assert failed" << std::endl;
        return false;
    }
    delete operand;
    return true;
}

bool AbstractVM::Instructions::add(AbstractVM::Stack *stack, IOperand *operand)
{
    if (stack->size() < 2)
        return false;
    IOperand *top = stack->top();
    stack->pop();
    IOperand *second = stack->top();
    stack->pop();
    try
    {
        IOperand *result = *second + *top;
        if (!result)
            return false;
        stack->push(result);
    }
    catch(AbstractVM::Exception const& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    delete top;
    delete second;
    delete operand;
    return true;
}

bool AbstractVM::Instructions::sub(AbstractVM::Stack *stack, IOperand *operand)
{
    if (stack->size() < 2)
        return false;
    IOperand *top = stack->top();

    stack->pop();
    IOperand *second = stack->top();
    stack->pop();
    try
    {
        IOperand *result = *second - *top;
        if (!result)
            return false;
        stack->push(result);
    }
    catch(AbstractVM::Exception const& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    delete top;
    delete second;
    delete operand;
    return true;
}

bool AbstractVM::Instructions::mul(AbstractVM::Stack *stack, IOperand *operands)
{
    if (stack->size() < 2)
        return false;

    IOperand *top = stack->top();
    stack->pop();
    IOperand *second = stack->top();
    stack->pop();
    try
    {
        IOperand *result = *second * *top;
        if (!result)
            return false;
        stack->push(result);
    }
    catch(AbstractVM::Exception const& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    delete top;
    delete second;
    delete operands;
    return true;
}

bool AbstractVM::Instructions::div(AbstractVM::Stack *stack, IOperand *operand)
{
    if (stack->size() < 2)
        return false;

    IOperand *top = stack->top();
    stack->pop();
    IOperand *second = stack->top();
    stack->pop();
    if (std::stoi(top->toString()) == 0) {
        std::cerr << "Error: Modulo by zero" << std::endl;
        return false;
    }
    try
    {
        IOperand *result = *second / *top;
        if (!result)
            return false;
        stack->push(result);
    }
    catch(AbstractVM::Exception const& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    delete top;
    delete second;
    delete operand;
    return true;
}

bool AbstractVM::Instructions::mod(AbstractVM::Stack *stack, IOperand *operand)
{
    if (stack->size() < 2)
        return false;
    IOperand *top = stack->top();

    stack->pop();
    IOperand *second = stack->top();
    stack->pop();
    if (std::stoi(top->toString()) == 0) {
        std::cerr << "Error: Modulo by zero" << std::endl;
        return false;
    }
    try
    {
        IOperand *result = *second % *top;
        if (!result)
            return false;
        stack->push(result);
    }
    catch(AbstractVM::Exception const& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    delete top;
    delete second;
    delete operand;
    return true;
}

bool AbstractVM::Instructions::load(AbstractVM::Stack *stack, IOperand *operand)
{
    if (std::stoi(operand->toString()) < 0 || std::stoi(operand->toString()) > 15)
        return false;
    std::stack<IOperand *> *loadRegister = stack->getRegister(std::stoi(operand->toString()));

    if (loadRegister->empty()) {
        std::cerr << "Error: Required register is empty" << std::endl;
        return false;
    }
    IOperand *top = loadRegister->top();

    stack->push(top);
    delete operand;
    return true;
}

bool AbstractVM::Instructions::store(AbstractVM::Stack *stack, IOperand *operand)
{
    if (std::stoi(operand->toString()) > 15 || std::stoi(operand->toString()) < 0) {
        std::cerr << "Error: Invalid register" << std::endl;
        return false;
    }
    if (stack->empty()) {
        std::cerr << "Error: Store failed" << std::endl;
        return false;
    }
    std::stack<IOperand *> *storeRegister = stack->getRegister(std::stoi(operand->toString()));

    if (!storeRegister->empty()) {
        delete storeRegister->top();
        storeRegister->pop();
    }
    storeRegister->push(stack->top());
    delete operand;
    stack->pop();
    return true;
}

bool AbstractVM::Instructions::print(AbstractVM::Stack *stack, IOperand *operand)
{
    if (stack->empty()) {
        std::cerr << "Error: Print failed" << std::endl;
        return false;
    }
    std::stack<IOperand *> *tmp = stack->getStack();
    IOperand *top = tmp->top();

    if (top->getType() != Int8) {
        std::cerr << "Error: Print failed" << std::endl;
        return false;
    }
    std::cout << (char)std::stoi(top->toString()) << std::endl;
    delete operand;
    return true;
}

void AbstractVM::Instructions::ExecuteInstruction(int instruction, AbstractVM::Stack *stack, IOperand *operand)
{
    switch (instruction) {
        case 0:
            push(stack, operand);
            break;
        case 1:
            if (!pop(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 2:
            clear(stack, operand);
            break;
        case 3:
            if (!dup(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 4:
            if (!swap(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 5:
            dump(stack, operand);
            break;
        case 6:
            if (!assert(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 7:
            if (!add(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 8:
            if (!sub(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 9:
            if (!mul(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 10:
            if (!div(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 11:
            if (!mod(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 12:
            if (!load(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 13:
            if (!store(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 14:
            if (!print(stack, operand))
                throw AbstractVM::Exception();
            break;
        case 15:
            break;
        default:
            break;
    }
}

std::string AbstractVM::Instructions::cleanNumber(std::string const &number)
{
    int flagNumber = 0;
    std::string cleanNumber = number;

    if (number.size() == 1 || number.find('.') == std::string::npos)
        return number;
    for (int i = number.length() - 1; i >= 0; i--) {
        if (number[i] == '0' && flagNumber == 0) {
            cleanNumber.erase(i, 1);
        } else if (number[i] != '0') {
            flagNumber = 1;
        } else {
            break;
        }
    }
    return cleanNumber;
}
