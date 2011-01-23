# Project info

SOURCES_DIR := sources
HEADERS_DIR := headers
OBJECTS_DIR := objects
BINARIES_DIR := binaries

EXECUTABLE := project
SOURCES := main.cpp misc.cpp Texture.cpp Math.cpp Skybox.cpp Camera.cpp Terrain.cpp

# System info

CC := g++
CFLAGS := -iquote $(HEADERS_DIR) -Wall

LD := $(CC)
LDFLAGS := -Wall -Wl,--enable-auto-import

OPENGL_LIBS := -lopengl32 -lglu32 -lglew32 -lfreeglut

EXECUTABLE := $(addsuffix .exe, $(EXECUTABLE))
PRINT_LINE := echo
PRINT_FILE :=
DELETE := delete /Q /F

# Auto generated project info (DO NOT MODIFY!)

EXECUTABLE := $(addprefix $(BINARIES_DIR)/, $(EXECUTABLE))

HEADERS := $(SOURCES:.cpp=.h)
OBJECTS := $(SOURCES:.cpp=.o)

SOURCES := $(addprefix $(SOURCES_DIR)/, $(SOURCES)) 
HEADERS := $(addprefix $(HEADERS_DIR)/, $(HEADERS))
OBJECTS := $(addprefix $(OBJECTS_DIR)/, $(OBJECTS))

SOURCE = $(word $(1), $(SOURCES))
OBJECT = $(word $(1), $(OBJECTS))
HEADER = $(word $(1), $(HEADERS))

# Implicit rules

%.exe:
	$(PRINT_LINE) Linking ...
	$(LD) $(LDFLAGS) $^ -o $@ $(OPENGL_LIBS) 
	$(PRINT_LINE) Done.

%.o:
	$(PRINT_LINE) Compiling ($(patsubst $(SOURCES_DIR)/%.cpp,%.cpp,$<)) ...
	$(CC) -c $< -o $@ $(CFLAGS) $(OPENGL_LIBS)

# Explicit rules

.SILENT:

# Quick reference list

# main		#1
# misc		#2
# texture	#3
# math		#4
# skybox	#5
# camera	#6
# terrain	#7

$(EXECUTABLE): $(OBJECTS)

$(call OBJECT,1): $(call SOURCE,1) $(call HEADER,4) $(call HEADER,5) $(call HEADER,6)  $(call HEADER,7)
$(call OBJECT,2): $(call SOURCE,2) $(CALL HEADER,2)
$(call OBJECT,3): $(call SOURCE,3) $(call HEADER,3)
$(call OBJECT,4): $(call SOURCE,4) $(call HEADER,4)
$(call OBJECT,5): $(call SOURCE,5) $(call HEADER,5) $(call HEADER,3)
$(call OBJECT,6): $(call SOURCE,6) $(call HEADER,6) $(call HEADER,2) $(call HEADER,4)
$(call OBJECT,7): $(call SOURCE,7) $(call HEADER,7) $(call HEADER,3)

# Fake targets

.PHONY: all run display clean help

all: clean $(EXECUTABLE) run display

run: $(EXECUTABLE)
	.\binaries\project.exe
display:

clean: