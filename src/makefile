IDIR=../include
IDIRG=$(LDIR)/googletest-master/googletest/include
CXX=g++
CXXFLAGS=-g -L../lib/googletest-master/googletest/build -I$(IDIR) -I$(IDIRG)
FLAGS=-c -Wall
ODIR=../obj
LDIR=../lib
LIBS= -lgtest -lpthread -lgtest_main
LIBS_C = -ftest-coverage -fprofile-arcs
EXEC=main

_DEPS = funcs.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o AddTest.o funcs.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) $(FLAGS) -o $@ $< $(CXXFLAGS) $(LIBS) $(LIBS_C)

main: $(OBJ)
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS) $(LIBS_C)

run: main
	@./main

move:
	mv $(ODIR)/*.gc* .

.PHONY: clear

clear:
	rm -rf $(ODIR)/*.o $(ODIR)/*.gcda $(ODIR)/*.gcno $(ODIR)/*~ core $(IDIR)/*~ *.gcov *.gcno *.gcda
