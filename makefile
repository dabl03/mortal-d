BIN_APP=./mortal-d.exe
BIN_DIR=./bin
SRC_APP=./src/main.cpp
CXX=g++
CXXFLAGS=-Wall -g -Wl,--subsystem,windows -std=c++11
LIBS=-lopengl32 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -I"./src/dependence/"

FILES_CPP=$(wildcard ./src/*.cpp)
FILES_O=$(subst src,bin,$(FILES_CPP:.cpp=.o))
RM=del

ALL:$(BIN_APP)

$(BIN_APP):$(FILES_O)
	@echo Compilando APP
	$(CXX) $(CXXFLAGS) -o $(BIN_APP) $(FILES_O) $(LIBS)

$(BIN_DIR)/%.o: ./src/%.cpp
	@echo Compilando archivo objeto{$@} ... usando {$<}
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	@echo "Limpiando archivos objetos..."
	$(RM) "bin\*.o"

run:
	$(BIN_APP)