BIN_APP=./mortal-d.exe
BIN_DIR=./bin
SRC_APP=./src/main.cpp
CXX=g++
CXXFLAGS=-Wall -g -Wl,--subsystem,windows
LIBS=-lopengl32 -lmingw32 -lSDL2main -lSDL2 -ljsoncpp

PERSON_O=$(BIN_DIR)/person.o
GEOMETRIC_FIGURE_O=$(BIN_DIR)/geometric_figure.o
DRAW_O=$(BIN_DIR)/draw.o

PERSON_CPP=./src/person.cpp
GEOMETRIC_FIGURE_CPP=./src/geometric_figure.cpp
DRAW_CPP=./src/draw.cpp

OBJ_ALL= $(PERSON_O) $(DRAW_O)


$(BIN_APP):$(SRC_APP) $(OBJ_ALL)
	$(CXX) $(CXXFLAGS) -o $(BIN_APP) $(SRC_APP) $(OBJ_ALL) $(LIBS)

$(PERSON_O):$(PERSON_CPP)
	$(CXX) $(CXXFLAGS) -c -o $(PERSON_O) $(PERSON_CPP)

$(DRAW_O):$(DRAW_CPP)
	$(CXX) $(CXXFLAGS) -c -o $(DRAW_O) $(DRAW_CPP)