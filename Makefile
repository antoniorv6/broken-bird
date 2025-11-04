.PHONY := all clean info clean-cache dev-deps install uninstall dist

GREEN := \033[1;32m
YELLOW := \033[1;33m
BLUE := \033[1;34m
RED := \033[1;31m
RESET := \033[0m

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
DIST_DIR := dist
LIB_DIR := vendor/lib/
RAYLIB := libraylib.a
RAYLIB_DEP := $(addprefix $(LIB_DIR),$(RAYLIB))

PREFIX ?= /usr/local
BINDIR := $(PREFIX)/bin
LIBDIR := $(PREFIX)/lib/$(APP_NAME)
DATADIR := $(PREFIX)/share/
INSTALL := install
INSTALL_PROGRAM := $(INSTALL) -m 0755
INSTALL_DATA := $(INSTALL) -m 0644
INSTALL_DIR := $(INSTALL) -d
APP_NAME ?= game
ASSETS_DIR := assets

# Buscar todos los .cpp recursivamente dentro de src/
SRC := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Generar los .o correspondientes en obj/ con la misma estructura
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Dependencias de enlace
DEPENDENCIES := -lraylib -lGL -lm -lpthread -lrt -lX11

# Incluir automáticamente todos los subdirectorios de src/
INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_VENDORS := $(shell find vendor/include -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) $(addprefix -I,$(INC_VENDORS))

all: $(RAYLIB_DEP) $(BIN_DIR)/$(APP_NAME)

$(BIN_DIR)/$(APP_NAME): $(OBJECTS)
	@echo "$(BLUE)🔗 Enlazando objetos...$(RESET)"
	@mkdir -p $(BIN_DIR)
	@ccache g++ -o $@ $^ -L $(LIB_DIR) $(DEPENDENCIES)
	@echo "$(GREEN)Ejecutable generado: $(BIN_DIR)/$(APP_NAME)$(RESET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "$(YELLOW)Compilando $< → $@$(RESET)"
	@mkdir -p $(dir $@)
	@ccache g++ -c $^ -o $@ $(INC_FLAGS)


clean:
	@echo "$(RED)Limpiando...$(RESET)"
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(DIST_DIR)
	@echo "$(GREEN)Limpieza completada.$(RESET)"


info:
	$(info SRC = $(SRC))
	$(info OBJECTS = $(OBJECTS))
	$(info INC_FLAGS = $(INC_FLAGS))
	$(info LIB_DEPS = $(LIB_DEP))
	$(info RAYLIB= $(RAYLIB_DEP))

clean-cache:
	ccache -C
	ccache --zero-stats

$(RAYLIB_DEP): | $(LIB_DEP)
	@if [ ! -f "$(RAYLIB_DEP)" ]; then \
		echo "$(YELLOW)Raylib no está instalada. Descargando...$(RESET)"; \
		git clone --depth 1 https://github.com/raysan5/raylib.git; \
		$(MAKE) -C raylib/src/ PLATFORM=PLATFORM_DESKTOP; \
		mkdir -p $(LIB_DIR); \
		mv raylib/src/libraylib.a $(LIB_DIR)/; \
		rm -rf raylib; \
		echo "$(GREEN)Raylib instalada correctamente.$(RESET)"; \
	else \
		echo "$(GREEN)Raylib ya instalada. Omitiendo descarga.$(RESET)"; \
	fi

$(LIB_DEP):
	mkdir -p vendor/lib