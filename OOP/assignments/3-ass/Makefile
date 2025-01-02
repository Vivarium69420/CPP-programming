CC = g++
OUTDIR = build
SRC = src/main.cpp src/EnrollmentManager.cpp src/Candidate.cpp

OBJS = $(SRC:%.cpp=$(OUTDIR)/%.o)
TARGET = $(OUTDIR)/main

$(shell mkdir -p $(OUTDIR)/src)

$(OUTDIR)/%.o: %.cpp
	$(CC) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $^ -o $@
	rm -rf $(OUTDIR)/*.o

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf $(OUTDIR)