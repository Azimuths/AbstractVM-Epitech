/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** AssemblyParser
*/

#include "AssemblyParser.hpp"
#include <algorithm>

AssemblyParser::AssemblyParser(std::string const &filePath) : _filePath{filePath}
{
    std::ifstream assemblyFile(filePath);
    int lineCount = 0;

    if (assemblyFile.is_open()) {
        std::string line;
        while (getline(assemblyFile, line)) {
            lineCount++;
            if (line[0] == ';' && line[1] != ';' || line[0] == '\n' || line.empty()) {
                continue;
            }
            if (checkLine(line)) {
                std::cerr << "Line :" << lineCount << "\n\tSyntax error, invalid line" <<  std::endl;
                exit(EXIT_FAILURE);
            }
            _fileBuffer += line;
            _fileBuffer += '\n';
        }
        assemblyFile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

AssemblyParser::AssemblyParser()
{
    _exit = EXIT_FAILURE;
}

AssemblyParser::~AssemblyParser()
{
}

int AssemblyParser::Parse(AbstractVM::Stack &stack)
{
    std::string line;
    std::istringstream iss(_fileBuffer);
    while (std::getline(iss, line)) {
        if (ExecuteLine(line, stack) != EXIT_SUCCESS)
            return GENERAL_ERROR_INVALID_LINE;
    }
    return _exit;
}

int AssemblyParser::ExecuteLine(std::string const &line, AbstractVM::Stack &stack)
{
    std::vector<std::string> tokens = Tokenize(line);
    int instruction = FindInstruction(tokens);

    if (instruction == UNKNOWN) {
        return EXIT_INVALID_INSTRUCTION;
    } if (instruction == EXIT) {
        _exit = EXIT_SUCCESS;
    }
    int dataType = getDataType(tokens);
    if (dataType == Unknown) {
        return EXIT_INVALID_TYPE;
    }
    std::string dataValue = getDataValue(tokens);
    try {
        _instructions.ExecuteInstruction(instruction, &stack, _factory.createOperand(static_cast<eOperandType>(dataType), dataValue));
    } catch(AbstractVM::Exception const& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    } catch (std::out_of_range const& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int AssemblyParser::FindInstruction(std::vector<std::string> const &tokens)
{
    for (auto &instruction : tokens) {
        if (instruction.find("push") != std::string::npos) {
            return PUSH;
        } if (instruction.find("pop") != std::string::npos) {
            return POP;
        } if (instruction.find("clear") != std::string::npos) {
            return CLEAR;
        } if (instruction.find("dup") != std::string::npos) {
            return DUP;
        } if (instruction.find("swap") != std::string::npos) {
            return SWAP;
        } if (instruction.find("dump") != std::string::npos) {
            return DUMP;
        } if (instruction.find("assert") != std::string::npos) {
            return ASSERT;
        } if (instruction.find("add") != std::string::npos) {
            return ADD;
        } if (instruction.find("sub") != std::string::npos) {
            return SUB;
        } if (instruction.find("mul") != std::string::npos) {
            return MUL;
        } if (instruction.find("div") != std::string::npos) {
            return DIV;
        } if (instruction.find("mod") != std::string::npos) {
            return MOD;
        } if (instruction.find("load") != std::string::npos) {
            return LOAD;
        } if (instruction.find("store") != std::string::npos) {
            return STORE;
        } if (instruction.find("print") != std::string::npos) {
            return PRINT;
        } if (instruction.find("exit") != std::string::npos) {
            return EXIT;
        }
    }
    return UNKNOWN;
}

int AssemblyParser::getDataType(std::vector<std::string> const &tokens)
{
    if (tokens.size() >= 2) {
        if (tokens[1].find("int8") != std::string::npos) {
            return eOperandType::Int8;
        } if (tokens[1].find("int16") != std::string::npos) {
            return eOperandType::Int16;
        } if (tokens[1].find("int32") != std::string::npos) {
            return eOperandType::Int32;
        } if (tokens[1].find("float") != std::string::npos) {
            return eOperandType::Float;
        } if (tokens[1].find("double") != std::string::npos) {
            return eOperandType::Double;
        } else {
            return eOperandType::Unknown;
        }
    }
    return eOperandType::NoOperand;
}

std::string AssemblyParser::getDataValue(std::vector<std::string> const &tokens)
{
    std::string dataValue = "";
    bool isType = true;

    if (tokens.size() >= 2) {
        for (int i = 0; tokens[1][i] != tokens[1].back(); i++) {
            if (((tokens[1][i] <= '9' && tokens[1][i] >= '0') || (tokens[1][i] == '-') || (tokens[1][i] == '.')) && !isType)
            dataValue += tokens[1][i];
            if (tokens[1][i] == '(')
                isType = false;
        }
    } else {
        dataValue.clear();
        return dataValue;
    }
    return dataValue;
}

int AssemblyParser::getFromString(std::string const &file)
{
    _fileBuffer = file;
    return EXIT_SUCCESS;
}

int AssemblyParser::Extract(std::string &FileToExtract)
{
    std::ifstream assemblyFile(FileToExtract);
    int lineCount = 0;

    if (assemblyFile.is_open()) {
        std::string line;
        while (getline(assemblyFile, line)) {
            lineCount++;
            if (line[0] == ';' && line[1] != ';' || line[0] == '\n' || line.empty()) {
                continue;
            }
            if (checkLine(line)) {
                std::cerr << "Line: " << lineCount << "\nSyntax error, invalid line" <<  std::endl;
                exit(EXIT_FAILURE);
            }
            _fileBuffer += line;
            _fileBuffer += '\n';
        }
        assemblyFile.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
    return EXIT_SUCCESS;
}

void AssemblyParser::setFactory(Factory &factory)
{
    _factory = factory;
}

std::vector<std::string> AssemblyParser::Tokenize(std::string const &line)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream iss(line);

    while (std::getline(iss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}

bool AssemblyParser::checkLine(std::string &line)
{
    std::string noCommentLine = line;

    if (noCommentLine.empty()) {
        std::cerr << "Empty line" << std::endl;
        return true;
    }
    size_t pos = noCommentLine.find(';');
    if (pos != std::string::npos) {
        noCommentLine.erase(pos);
    }
    for(int i = 0; i < noCommentLine.size(); i++) {
        if (noCommentLine[i] == ' ' && noCommentLine[i + 1] == ' ') {
            noCommentLine.erase(i + 1, 1);
        }
    }
    for (int i = 0; i < noCommentLine.size(); i++) {
        if (noCommentLine[i] == '(' && (noCommentLine[i + 1] < '0' || (noCommentLine[i + 1] > '9')) && noCommentLine[i + 1] != '-') {
            std::cerr << "Opened parenthesis followed by invalid character" << std::endl;
            return true;
        }
    }
    if (noCommentLine.find('(') != std::string::npos && noCommentLine.find(')') == std::string::npos) {
        std::cerr << "Missing closing parenthesis" << std::endl;
        return true;
    }
    line = noCommentLine;
    return false;
}
