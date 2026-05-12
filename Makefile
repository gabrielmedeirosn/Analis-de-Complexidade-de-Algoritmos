CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++11

TARGET = programa.exe

SRC = main.cpp \
      algoritmos/buscas.cpp \
      algoritmos/ordenacao.cpp \
      benchmark/benchmark.cpp \
      utils/csv.cpp

all: $(TARGET)

$(TARGET):
	if not exist resultados mkdir resultados
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	$(TARGET)

clean:
	del /Q $(TARGET)
	del /Q resultados\\*.csv