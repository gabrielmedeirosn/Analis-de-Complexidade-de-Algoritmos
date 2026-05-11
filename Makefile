CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++11

TARGET = programa

SRC = main.cpp \
      algoritmos/buscas.cpp \
      algoritmos/ordenacao.cpp \
      benchmark/benchmark.cpp \
      utils/csv.cpp

all: $(TARGET)

$(TARGET):
	mkdir -p resultados
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -f resultados/*.csv

rebuild: clean all