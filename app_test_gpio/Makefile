NAME_MODULE = app_master
OBJ_DIR = build_$(NAME_MODULE)
CXX = arm-buildroot-linux-gnueabi-g++
CC  = arm-buildroot-linux-gnueabi-gcc
CFLAGS = -I.
OBJ = gpio.o
IP_ADDR = 192.168.1.126
all: create $(OBJ_DIR)/$(NAME_MODULE)
create:
	@echo mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.c
	@echo CXX $<
	@$(CC) -c -o $@ $< $(CFLAGS)
$(OBJ_DIR)/$(NAME_MODULE): $(OBJ)
	@echo ---------- START LINK PROJECT ----------
	@echo $(CC) -o $@ $^ $(CFLAGS)
	@$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean
clean:
	@echo rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)	

.PHONY: copy
copy:
	scp -r ./$(OBJ_DIR)/$(NAME_MODULE) pi@$(IP_ADDR):/home/pi/f1c100s/
