BIN_APP=./mortal-d.exe
BIN_DIR=./bin
SRC_APP=./src/main.cpp
CXX=g++
CXXFLAGS=-Wall -g
LIBS=-lopengl32 -lfreeglut -lglu32

PERSON_O=$(BIN_DIR)/person.o
GEOMETRIC_FIGURE_O=$(BIN_DIR)/geometric_figure.o

PERSON_CPP=./src/person.cpp
GEOMETRIC_FIGURE_CPP=./src/geometric_figure.cpp

OBJ_ALL=$(PERSON_O) $(GEOMETRIC_FIGURE_O)


$(BIN_APP):$(SRC_APP) $(OBJ_ALL)
	$(CXX) $(CXXFLAGS) -o $(BIN_APP) $(SRC_APP) $(OBJ_ALL) $(LIBS)

$(PERSON_O):$(PERSON_CPP)
	$(CXX) $(CXXFLAGS) -c -o $(PERSON_O) $(PERSON_CPP)

$(GEOMETRIC_FIGURE_O):$(GEOMETRIC_FIGURE_CPP)
	$(CXX) $(CXXFLAGS) -c -o $(GEOMETRIC_FIGURE_O) $(GEOMETRIC_FIGURE_CPP)