CC = g++
OUTDIR = build
SRC = src/engineer.cpp src/officer_management.cpp src/officer.cpp src/staff.cpp src/worker.cpp main.cpp
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