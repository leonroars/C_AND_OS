# 컴파일러 설정 (gcc 사용)
CC = gcc

# 컴파일 옵션
# -Iinclude: include 폴더를 헤더 파일 경로로 추가 (Java의 import 경로 설정과 유사)
# -Wall -Wextra: 모든 경고 메시지 출력 (엄격한 코딩 습관용)
# -g: 디버깅 정보 포함 (GDB 사용 시 필수)
CFLAGS = -Iinclude -Wall -Wextra -g

# 디렉토리 설정
SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/my_os

# src 디렉토리 하위의 모든 .c 파일 찾기 (src/hal, src/memory 등 포함)
# 리눅스/맥 명령어 find 사용
SRCS = $(shell find $(SRC_DIR) -name '*.c')

# .c 파일 이름들을 .o (Object file) 이름으로 변환
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# 1. 기본 타겟: make 라고 치면 실행됨
all: $(TARGET)

# 2. 실행 파일 생성 규칙 (링크 단계)
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@
	@echo "Build complete: $@"

# 3. 개별 소스 파일 컴파일 규칙
# $< : 입력 파일(.c), $@ : 출력 파일(.o)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 4. 청소 (Clean): 빌드된 파일 삭제
clean:
	rm -rf $(BUILD_DIR)
	@echo "Cleaned build directory."

# 가짜 타겟 선언 (파일 이름과 겹침 방지)
.PHONY: all clean
