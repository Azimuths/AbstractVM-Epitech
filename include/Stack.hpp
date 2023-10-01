/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** Stack
*/

#pragma once
#include "IOperand.hpp"
#include <stack>

namespace AbstractVM {

    class Stack {
        public:
            Stack();
            ~Stack();
            void push(IOperand *operand);
            void pop();
            IOperand *top();
            bool empty();
            std::stack<IOperand *> *getStack();
            int size();
            std::stack<IOperand *> *getRegister(int index);
        protected:
        private:
            std::stack<IOperand *> _stack;
            std::stack<IOperand *> _registers[15];
    };
}
