/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
** File description:
** Exceptions
*/

#pragma once

#include <exception>

namespace AbstractVM {
    class Exception : std::exception {
        public:
            Exception();
            ~Exception();

            const char *what() const throw() override;
        protected:
        private:
    };
}
