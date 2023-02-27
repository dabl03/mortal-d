BIN_APP="./mortal-d.exe"
BIN_DIR="./bin/"
SRC_APP="./src/main.cpp"
CXX=g++
SRC_ALL=
CXXFLAGS=-Wall -g
LIBS=-lopengl32 -lfreeglut -lglu32


$(BIN_APP):$(SRC_MAIN) $(SRC_ALL)
	$(CXX) $(CXXFLAGS) -o $(BIN_APP) $(SRC_APP) $(SRC_ALL) $(LIBS)