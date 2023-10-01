/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo [WSL: Arch]
** File description:
** Int16
*/

#include <limits>
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

AbstractVM::Int16::Int16(std::string value, const Factory &factory) : _factory{factory}
{
    _value = value;
}

AbstractVM::Int16::~Int16()
{
}

std::string AbstractVM::Int16::toString() const
{
    return _value;
}

eOperandType AbstractVM::Int16::getType() const
{
    return eOperandType::Int16;
}

IOperand *AbstractVM::Int16::operator+(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
            if (rhs.getType() == eOperandType::Int8) {
            int value1 = 0;
            short value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 > std::numeric_limits<int32_t>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 < std::numeric_limits<int32_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int32, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            int value1 = 0;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stoi(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << value1 + value2;
            if (value1 + value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 + value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            int value1 = 0;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stoi(this->toString());
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

IOperand *AbstractVM::Int16::operator-(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
        if (rhs.getType() == eOperandType::Int8) {
            int value1 = 0;
            short value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 > std::numeric_limits<int32_t>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 < std::numeric_limits<int32_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int32, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            int value1 = 0;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stoi(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << value1 - value2;
            if (value1 - value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 - value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            int value1 = 0;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stoi(this->toString());
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

IOperand *AbstractVM::Int16::operator*(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
        if (rhs.getType() == eOperandType::Int8) {
            int value1 = 0;
            short value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 > std::numeric_limits<int32_t>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 < std::numeric_limits<int32_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int32, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            int value1 = 0;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stoi(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << value1 * value2;
            if (value1 * value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 * value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            int value1 = 0;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stoi(this->toString());
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

IOperand *AbstractVM::Int16::operator/(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
        if (rhs.getType() == eOperandType::Int8) {
            int value1 = 0;
            short value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 > std::numeric_limits<int32_t>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 < std::numeric_limits<int32_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int32, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            int value1 = 0;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stoi(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << value1 / value2;
            if (value1 / value2 > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (value1 / value2 <std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            int value1 = 0;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stoi(this->toString());
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

IOperand *AbstractVM::Int16::operator%(const IOperand &rhs) const
{
    std::size_t pos{};
    try {
        if (rhs.getType() == eOperandType::Int8) {
            int value1 = 0;
            short value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 % value2;
            if (value1 % value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 % value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int16) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 % value2;
            if (value1 % value2 > std::numeric_limits<int16_t>::max())
                throw AbstractVM::Exception();
            if (value1 % value2 < std::numeric_limits<int16_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int16, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Int32) {
            int value1 = 0;
            int value2 = 0;
            std::stringstream stringStream;

            value1 = std::stoi(this->toString());
            value2 = std::stoi(rhs.toString());
            stringStream << value1 % value2;
            if (value1 % value2 > std::numeric_limits<int32_t>::max())
                throw AbstractVM::Exception();
            if (value1 % value2 < std::numeric_limits<int32_t>::min())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Int32, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Float) {
            int value1 = 0;
            float value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(7);

            value1 = std::stoi(this->toString());
            value2 = std::stof(rhs.toString());
            stringStream << std::fmod(value1, value2);
            if (std::fmod(value1, value2) > std::numeric_limits<float>::max())
                throw AbstractVM::Exception();
            if (std::fmod(value1, value2) < std::numeric_limits<float>::lowest())
                throw AbstractVM::Exception();
            return _factory.createOperand(eOperandType::Float, stringStream.str());
        }
        if (rhs.getType() == eOperandType::Double) {
            int value1 = 0;
            double value2 = 0.0f;
            std::stringstream stringStream;
            stringStream.unsetf(std::ios::floatfield);
            stringStream.precision(15);

            value1 = std::stoi(this->toString());
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

