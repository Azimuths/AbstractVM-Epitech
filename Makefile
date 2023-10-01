##
## EPITECH PROJECT, 2023
## B-SYN-400-BDX-4-1-abstractVM-diego1.marliere-calvo
## File description:
## Makefile
##

SRC =	src/main.cpp			\
		src/AbstractVMCore.cpp	\
		src/AssemblyParser.cpp	\
		src/Stack.cpp			\
		src/Factory.cpp			\
		src/Int8.cpp			\
		src/Int16.cpp			\
		src/Int32.cpp			\
		src/Float.cpp			\
		src/Double.cpp			\
		src/Instructions.cpp	\

BUILDDIR = obj

OBJ =	$(SRC:%.cpp=$(BUILDDIR)/%.o)

NAME =	abstractVM

CC = g++

CPPFLAGS =	-Iinclude/

CFLAGS = -Wall -Wextra

DEBUGFLAG = -g

TESTS = tests/test_conversions.c \
		tests/test_flags.c \
		tests/test_strings.c

TESTSFLAGS = -Iinclude/ -lcriterion --coverage

all:	$(NAME)

$(NAME):		$(OBJ)
				$(LINK.o) $^ $(LDLIBS) $(OUTPUT_OPTION)

.SECONDEXPANSION:
$(BUILDDIR)/%.o:	override CPPFLAGS += -MT $@ -MMD -MP -MF $(@:.o=.d)
$(BUILDDIR)/%.o:	%.cpp | $$(@D)/
					$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(BUILDDIR)/:
					mkdir $@

$(BUILDDIR)%/:
					mkdir -p $@

.PRECIOUS:			$(BUILDDIR)/ $(BUILDDIR)%/

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: fclean all

tests_run:
		gcc -o test_crit $(TESTS) $(SRC) $(TESTSFLAGS)
		./test_crit

debug:
		$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(DEBUGFLAG)

.PHONY: all clean fclean re

-include $(OBJ:.o=.d)