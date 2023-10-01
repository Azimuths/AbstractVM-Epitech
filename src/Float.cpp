/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo [WSL: Arch]
** File description:
** Float
*/

#include <limits>
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

AbstractVM::Float::Float(std::string value, const Factory &factory) : _factory{factory}
{
    _value = value;
}

AbstractVM::Float::~Float()
{
}

std::string AbstractVM::Float::toString() const
{
    return _value;
}

eOperandType AbstractVM::Float::getType() const
{
    return eOperandType::Float;
}

IOperand *AbstractVM::Float::operator+(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
            if (rhs.getType() == eOperandType::Int8) {
            float value1 = 0.0f;
            short value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            float value1 = 0.0f;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            float value1 = 0.0f;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stof(this->toString());
            value2 = std::stod(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 >std::numeric_limits<double>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 <std::numeric_limits<double>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Double, stringStream.str());
        }
    } catch (std::invalid_argument const& ex) {
            std::cerr << "std::underflow_error::what(): " << ex.what() << '\n';
    } catch (std::out_of_range const& ex) {
        std::cerr << "std::overflow_error::what(): " << ex.what() << '\n';
    }
    return nullptr;
}

IOperand *AbstractVM::Float::operator-(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
        if (rhs.getType() == eOperandType::Int8) {
            float value1 = 0.0f;
            short value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            float value1 = 0.0f;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            float value1 = 0.0f;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stod(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 >std::numeric_limits<double>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 <std::numeric_limits<double>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Double, stringStream.str());
        }
    } catch (AbstractVM::Exception const& ex) {
        std::cerr << "std::general_error::what(): " << ex.what() << '\n';
        return nullptr;
    }
    return nullptr;
}

IOperand *AbstractVM::Float::operator*(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
        if (rhs.getType() == eOperandType::Int8) {
            float value1 = 0.0f;
            short value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            float value1 = 0.0f;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            float value1 = 0.0f;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stof(this->toString());
            value2 = std::stod(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 >std::numeric_limits<double>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 <std::numeric_limits<double>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Double, stringStream.str());
        }
    } catch (AbstractVM::Exception const& ex) {
        std::cerr << "std::general_error::what(): " << ex.what() << '\n';
        return nullptr;
    }
    return nullptr;
}

IOperand *AbstractVM::Float::operator/(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
        if (rhs.getType() == eOperandType::Int8) {
            float value1 = 0.0f;
            short value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            float value1 = 0.0f;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            float value1 = 0.0f;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stof(this->toString());
            value2 = std::stod(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 >std::numeric_limits<double>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 <std::numeric_limits<double>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Double, stringStream.str());
        }
    } catch (AbstractVM::Exception const& ex) {
        std::cerr << "std::general_error::what(): " << ex.what() << '\n';
        return nullptr;
    }
    return nullptr;
}

IOperand *AbstractVM::Float::operator%(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
        if (rhs.getType() == eOperandType::Int8) {
            float value1 = 0.0f;
            short value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << std::fmod(value1, value2);
            if (std::fmod(value1, value2) > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (std::fmod(value1, value2) < std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << std::fmod(value1, value2);
            if (std::fmod(value1, value2) > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (std::fmod(value1, value2) < std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            float value1 = 0.0f;
            int value2 = 0;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << std::fmod(value1, value2);
            if (std::fmod(value1, value2) > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (std::fmod(value1, value2) < std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            float value1 = 0.0f;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stof(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << std::fmod(value1, value2);
            if (std::fmod(value1, value2) > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (std::fmod(value1, value2) < std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            float value1 = 0.0f;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stof(this->toString());
            value2 = std::stod(rhs.toString());
            stringStream << std::fmod(value1, value2);
            if (std::fmod(value1, value2) > std::numeric_limits<double>::max())
                throw AbstractVM::Exception();
            if (std::fmod(value1, value2) < std::numeric_limits<double>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Double, stringStream.str());
        }
    } catch (AbstractVM::Exception const& ex) {
        std::cerr << "std::general_error::what(): " << ex.what() << '\n';
        return nullptr;
    }
    return nullptr;
}

