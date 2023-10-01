/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo [WSL: Arch]
** File description:
** Int16
*/

#pragma once

#include "IOperand.hpp"
#include "Defines.hpp"
#include "Factory.hpp"

namespace AbstractVM {
    class Int16 : public IOperand{
        public:
            Int16(std::string value, const Factory &factory);
            ~Int16();
        public:
            std::string toString() const override;
            eOperandType getType() const override;
            IOperand *operator+(const IOperand &rhs) const override;
            IOperand *operator-(const IOperand &rhs) const override;
            IOperand *operator*(const IOperand &rhs) const override;
            IOperand *operator/(const IOperand &rhs) const override;
            IOperand *operator%(const IOperand &rhs) const override;
        protected:
        private:
            std::string _value;
            const Factory &_factory;
    };
}
