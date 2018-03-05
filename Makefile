#先把当前Makefile的工作目录截到

ROOT_PATH=$(shell pwd)
CLIENT_PATH=$(ROOT_PATH)/client
COMM_PATH=$(ROOT_PATH)/comm
CONFIG_PATH=$(ROOT_PATH)/config
LIB_PATH=$(ROOT_PATH)/lib
LOG_PATH=$(ROOT_PATH)/log
SERVER_PATH=$(ROOT_PATH)/server
WINDOW_PATH=$(ROOT_PATH)/window
DATA_POOL_PATH=$(ROOT_PATH)/data_pool

#生成的目标文件/使用的方法cc

CC=g++

FLAGS=-D_FAST_
LDFLAGS=-lpthread -ljsoncpp#-static

INCLUDE_PATH=-I$(SERVER_PATH) -I$(DATA_POOL_PATH) -I$(LOG_PATH) -I$(COMM_PATH) -I$(LIB_PATH)/include -I$(WINDOW_PATH)
JSON_PATH=-L$(LIB_PATH)/lib

lib=-lpthread -ljsoncpp


#生成的目标文件名字

SERVER_BIN=udpServer
CLIENT_BIN=udpClient

#源代码的位置

SERVER_SRC=$(shell ls $(SERVER_PATH) $(DATA_POOL_PATH) $(LOG_PATH) $(COMM_PATH)| egrep -v '^.*\.h'|egrep '.*\.cpp')
CLIENT_SRC=$(shell ls $(CLIENT_PATH) $(LOG_PATH) $(COMM_PATH) $(WINDOW_PATH)| egrep -v '^.*\.h'|egrep '.*\.cpp')

#拿到依赖文件/目标文件列表(把.cpp变成.o)
SERVER_OBJ=$(shell echo $(SERVER_SRC)|sed 's/\.cpp/\.o/g')
CLIENT_OBJ=$(shell echo $(CLIENT_SRC)|sed 's/\.cpp/\.o/g')

.PHONY:all 
all:$(SERVER_BIN) $(CLIENT_BIN)

$(SERVER_BIN):$(SERVER_OBJ)
	@echo "Link [$^] to [$@]"
	@$(CC) -o $@ $^  $(JSON_PATH) $(LDFLAGS) $(lib) $(LDFLAGS)
	@echo "Link done..."
%.o:$(SERVER_PATH)/%.cpp 
	@echo "Compling [$<] to [$@]..." #把.cpp变成.o
	@$(CC) -c $< $(INCLUDE_PATH)

$(CLIENT_BIN):$(CLIENT_OBJ)
	@echo "Link [$^] to [$@]"
	@$(CC) -o $@ $^ $(JSON_PATH) $(LDFLAGS) $(lib) $(LDFLAGS) -lncurses
	@echo "Link done..."
%.o:$(CLIENT_PATH)/%.cpp
	@echo "Compling [$<] to [$@]..." #把.cpp变成.o
	@$(CC) -c $< $(INCLUDE_PATH)

%.o:$(DATA_POOL_PATH)/%.cpp
	@echo "Compling [$<] to [$@]..." #把.cpp变成.o
	@$(CC) -c $< $(INCLUDE_PATH)

%.o:$(LOG_PATH)/%.cpp
	@echo "Compling [$<] to [$@]..." #把.cpp变成.o
	@$(CC) -c $< $(INCLUDE_PATH)
%.o:$(COMM_PATH)/%.cpp
	@echo "Compling [$<] to [$@]..." #把.cpp变成.o
	@$(CC) -c $< $(INCLUDE_PATH) $(FLAGS)
%.o:$(WINDOW_PATH)/%.cpp
	@echo "Compling [$<] to [$@]..." #把.cpp变成.o
	@$(CC) -c $< $(INCLUDE_PATH) $(FLAGS)
.PHONY:clean
clean:
	rm -rf $(SERVER_BIN) $(CLIENT_BIN) *.o output
#.PHONY:output
#output:
#	mkdir -p output/log
#	cp $(SERVER_BIN) output
#	cp $(CLIENT_BIN) output
#	cp -rf config output
#	cp server_ctl.sh output


#调试
.PHONY:debug
debug:
	@echo $(SERVER_SRC)    #加@是只显示结果不显示过程
	@echo $(CLIENT_SRC)
	@echo $(SERVER_OBJ)
	@echo $(SERVER_OBJ)


