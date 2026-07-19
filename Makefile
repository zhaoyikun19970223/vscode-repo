# 目标可执行文件名
TARGET = main_debug

# 所有C源文件
SRCS = main.c increment_pid.c position_pid.c

# 对应.o目标文件
OBJS = $(SRCS:.c=.o)

# 头文件目录（当前目录）
INC = -I./

# 编译参数：-g 生成gdb调试符号；-Wall 开启警告；-O0 关闭优化（调试必备）
CFLAGS = -g -O0 -Wall $(INC)

# 链接器参数
LDFLAGS = 

# 编译器
CC = gcc

# 主生成规则：链接所有.o生成可执行程序
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# 编译.c生成带调试信息的.o文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 调试快捷命令：直接启动gdb
debug: $(TARGET)
	gdb ./$(TARGET)

# 清理编译产物
clean:
	rm -f $(OBJS) $(TARGET)

# 伪目标，防止和文件重名冲突
.PHONY: clean debug
