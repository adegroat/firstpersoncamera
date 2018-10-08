EXECUTABLE = fpcam

# Includes
INCLUDE_PATH += -I/usr/include
#INCLUDE_PATH += -I/usr/whatver/glm

LIB_PATH = -L/usr/lib/x86_64-linux-gnu

# Libraries
LIBS += -lglfw -lGL
# LIBS += -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lpthread -ldl -lGL -lglfw3


# c++ settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

# Begin compiling and linking

$(EXECUTABLE): $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIB_PATH) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(obj) $(EXECUTABLE)