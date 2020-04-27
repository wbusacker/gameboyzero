# Project Directories
SRC 		:= src
BLD 		:= bld
TST			:= test
DEPDIR 		:= $(BLD)/deps
PRJ_NAME 	:= $(shell basename $(CURDIR))

# Application Files
C_SOURCE_FILES 			:= $(shell find ./$(SRC) -type f -name *.c)
C_SOURCE_FILES_BASE 	:= $(notdir $(C_SOURCE_FILES))
C_OBJECT_FILES 			:= $(addprefix $(BLD)/, $(patsubst %.c, %.o, $(C_SOURCE_FILES_BASE)))
C_DEP_FILES 			:= $(addprefix $(DEPDIR)/, $(patsubst %.c, %.Td, $(C_SOURCE_FILES_BASE)))

CXX_SOURCE_FILES 		:= $(shell find ./$(SRC) -type f -name *.cpp)
CXX_SOURCE_FILES_BASE 	:= $(notdir $(CXX_SOURCE_FILES))
CXX_OBJECT_FILES 		:= $(addprefix $(BLD)/, $(patsubst %.cpp, %.o, $(CXX_SOURCE_FILES_BASE)))
CXX_DEP_FILES 			:= $(addprefix $(DEPDIR)/, $(patsubst %.cpp, %.Td, $(CXX_SOURCE_FILES_BASE)))

SOURCE_FILES			:= $(C_SOURCE_FILES) $(CXX_SOURCE_FILES)
SOURCE_FILES_BASE		:= $(C_SOURCE_FILES_BASE) $(CXX_SOURCE_FILES_BASE)
OBJECT_FILES			:= $(C_OBJECT_FILES) $(CXX_OBJECT_FILES)
SOURCE_DIRS				:= $(shell find ./$(SRC)/ -type d)
DEP_FILES				:= $(C_DEP_FILES) $(CXX_DEP_FILES)

# Test Files
C_TEST_SOURCE_FILES 		:= $(shell find ./$(TST) -type f -name *.c)
C_TEST_SOURCE_FILES_BASE 	:= $(notdir $(C_TEST_SOURCE_FILES))
C_TEST_OBJECT_FILES 		:= $(addprefix $(BLD)/, $(patsubst %.c, %.o, $(C_TEST_SOURCE_FILES_BASE)))
C_TEST_DEP_FILES 			:= $(addprefix $(DEPDIR)/, $(patsubst %.c, %.Td, $(C_TEST_SOURCE_FILES_BASE)))

CXX_TEST_SOURCE_FILES 		:= $(shell find ./$(TST) -type f -name *.cpp)
CXX_TEST_SOURCE_FILES_BASE 	:= $(notdir $(CXX_TEST_SOURCE_FILES))
CXX_TEST_OBJECT_FILES 		:= $(addprefix $(BLD)/, $(patsubst %.cpp, %.o, $(CXX_TEST_SOURCE_FILES_BASE)))
CXX_TEST_DEP_FILES 			:= $(addprefix $(DEPDIR)/, $(patsubst %.cpp, %.Td, $(CXX_TEST_SOURCE_FILES_BASE)))

TEST_SOURCE_FILES			:= $(C_TEST_SOURCE_FILES) $(CXX_TEST_SOURCE_FILES)
TEST_SOURCE_FILES_BASE		:= $(C_TEST_SOURCE_FILES_BASE) $(CXX_TEST_SOURCE_FILES_BASE)
TEST_OBJECT_FILES			:= $(C_TEST_OBJECT_FILES) $(CXX_TEST_OBJECT_FILES) $(filter-out $(BLD)/main.o, $(OBJECT_FILES))
TEST_SOURCE_DIRS			:= $(shell find ./$(TST)/ -type d)
DEP_FILES					+= $(C_TEST_DEP_FILES) $(CXX_TEST_DEP_FILES) 

CC 		:= gcc
CXX		:= g++
ASM_CMD := objdump
IMG_CMD := objcopy

OPT 			:= -O0 -g
INCLUDE_DIRS 	:= $(addprefix -I, $(SOURCE_DIRS)) $(addprefix -I, $(TEST_SOURCE_DIRS))
WARN			:= -Wall
LINK			:= -lpthread -lncurses -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS 			:= $(INCLUDE_DIRS) $(OPT) $(WARN) $(LINK)
DEPFLAGS		= -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

# Output Files
EXE := $(PRJ_NAME).exe
IMG := $(PRJ_NAME).img
GTS := $(PRJ_NAME).test.exe

# Surpress stdout
M	:= @

exe: $(EXE)

all: $(EXE) $(GTS)

img: $(IMG)

test: $(GTS)
	./$(GTS)

stat:
	$(M)echo Main Source Files
	$(M)echo $(SOURCE_FILES)
	$(M)echo Test Source Files
	$(M)echo $(TEST_SOURCE_FILES)
	$(M)echo Main OBJECT Files
	$(M)echo $(OBJECT_FILES)
	$(M)echo Test OBJECT Files
	$(M)echo $(TEST_OBJECT_FILES)

clean:
	$(M)echo Cleaning
	$(M)rm -rf $(BLD)/*.o $(EXE) $(GTS)

cleanall:
	$(M)echo Cleaning all
	$(M)rm -rf $(BLD)/* $(EXE) $(GTS)	

remake: clean all

format:
	$(M)clang-format -i ./$(SRC)/**/* ./$(TST)/**/*

$(EXE): $(OBJECT_FILES)
	$(M)echo Linking
	$(M)$(CXX) $(CFLAGS) -o $@ $^

$(IMG): $(EXE)
	$(M)echo Building Image
	$(M)$(IMG_CMD) -Obinary $^ $@

$(GTS): $(TEST_OBJECT_FILES)
	$(M)echo Linking Test 
	$(M)$(CXX) $(CFLAGS) -o $@ $^ -lgtest -lgmock

# Generic Rules
$(BLD)/%.o: **/**/%.c **/**/%.h  | $(DEPDIR) $(DEPDIR)/%.Td
	$(M)echo Compiling $(@F)
	$(M)$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.c | $(DEPDIR) $(DEPDIR)/%.Td
	$(M)echo Compiling $(@F)
	$(M)$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.cpp **/**/%.h  | $(DEPDIR) $(DEPDIR)/%.Td
	$(M)echo Compiling $(@F)
	$(M)$(CXX) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

$(BLD)/%.o: **/**/%.cpp | $(DEPDIR) $(DEPDIR)/%.Td
	$(M)echo Compiling $(@F)
	$(M)$(CXX) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

.PHONY: all exe img clean remake test

$(DEP_FILES):

$(TEST_DEP_FILES):

$(SRC):
	mkdir $@

$(BLD):
	mkdir $@

$(DEPDIR): 
	mkdir $@
>>>>>>> 9cb9829... Unit tested main Arithmetic Functions

remake:
	make clean; make