INCDIR=./include
SRCDIR=./src
CXXFLAGS = -O2 -g -Wall -DDEBUG -fmessage-length=0 -I$(INCDIR)
OBJS = $(SRCDIR)/player.o  $(SRCDIR)/tictactoeboard.o \
	   $(SRCDIR)/tictactoegame.o $(SRCDIR)/move.o tttgame.o
LIBS =
TARGET = tttgame

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all: $(TARGET)

clean:
	rm -vf $(OBJS) $(TARGET)

