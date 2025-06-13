CXX := g++
CXXFLAGS := -std=c++17 -Wall -O2 -g 
WX_CXXFLAGS := $(shell wx-config --cxxflags)
WX_LDFLAGS := $(shell wx-config --libs)
TARGET := kanji_app

SRCS = gui.cpp drawingPanel.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(WX_LDFLAGS)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(WX_CXXFLAGS) $< -o $@

.PHONY: clean

clean: 
	rm -f $(OBJS) $(TARGET)