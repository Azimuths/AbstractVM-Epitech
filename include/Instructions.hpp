/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** Instructions
*/

#pragma once

#include "Stack.hpp"
#include "IOperand.hpp"

enum AssemblyInstructions
{
    PUSH,
    POP,
    CLEAR,
    DUP,
    SWAP,
    DUMP,
    ASSERT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    LOAD,
    STORE,
    PRINT,
    EXIT,
    UNKNOWN
};


namespace AbstractVM {
    class Instructions {
        public:
            Instructions();
            ~Instructions();

            void ExecuteInstruction(int instruction, AbstractVM::Stack *stack, IOperand *operand);
            void push(AbstractVM::Stack *stack, IOperand *operand);
            bool pop(AbstractVM::Stack *stack, IOperand *operand);
            void clear(AbstractVM::Stack *stack, IOperand *operand);
            bool dup(AbstractVM::Stack *stack, IOperand *operand);
            bool swap(AbstractVM::Stack *stack, IOperand *operand);
            void dump(AbstractVM::Stack *stack, IOperand *operand);
            bool assert(AbstractVM::Stack *stack, IOperand *operand);
            bool add(AbstractVM::Stack *stack, IOperand *operand);
            bool sub(AbstractVM::Stack *stack, IOperand *operand);
            bool mul(AbstractVM::Stack *stack, IOperand *operand);
            bool div(AbstractVM::Stack *stack, IOperand *operand);
            bool mod(AbstractVM::Stack *stack, IOperand *operand);
            bool load(AbstractVM::Stack *stack, IOperand *operand);
            bool store(AbstractVM::Stack *stack, IOperand *operand);
            bool print(AbstractVM::Stack *stack, IOperand *operand);
            std::string cleanNumber(std::string const &number);
            protected:
            private:
    };
}
