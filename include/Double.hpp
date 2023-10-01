/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo [WSL: Arch]
** File description:
** Double
*/

#pragma once
#include "IOperand.hpp"
#include "Defines.hpp"
#include "Factory.hpp"

namespace AbstractVM {
    class Double : public IOperand{
        public:
            Double(std::string, const Factory &factory);
            ~Double();
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
