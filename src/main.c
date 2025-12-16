#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 매크로 상수 정의 (Java의 static final)
#define MAX_CMD_LEN 100

void print_intro() {
    printf("==========================================\n");
    printf("   WELCOME TO MY-OS (C Simulation)   \n");
    printf("   Memory: 64KB | Disk: 1MB          \n");
    printf("==========================================\n");
}

void print_help() {
    printf("[HELP] Available commands:\n");
    printf(" - help           : Show this message\n");
    printf(" - status         : Show system status\n");
    printf(" - exit           : Shutdown system\n");
}

int main() {
    char input[MAX_CMD_LEN];
    char *command;

    print_intro();

    // 메인 루프 (OS는 꺼지기 전까지 무한 반복)
    while (1) {
        // 1. 프롬프트 출력
        printf("my-os> ");

        // 2. 명령어 입력 받기 (Java의 Scanner.nextLine() 유사)
        if (fgets(input, MAX_CMD_LEN, stdin) == NULL) {
            break; // EOF (Ctrl+D) 입력 시 종료
        }

        // 입력 문자열 끝의 개행문자(\n) 제거
        input[strcspn(input, "\n")] = 0;

        // 아무것도 입력 안 했을 경우 다시 루프
        if (strlen(input) == 0) continue;

        // 3. 명령어 파싱 (공백 기준으로 첫 단어 자르기)
        // Java의 split(" ")[0] 과 유사하지만, C에서는 strtok 사용
        command = strtok(input, " ");

        // 4. 명령어 처리
        if (strcmp(command, "exit") == 0) {
            printf("Shutting down... Goodbye!\n");
            break;
        } 
        else if (strcmp(command, "help") == 0) {
            print_help();
        } 
        else if (strcmp(command, "status") == 0) {
            printf("[SYSTEM] System is running.\n");
            printf("[SYSTEM] TODO: Implement system status check.\n");
        } 
        else {
            printf("[ERROR] Unknown command: '%s'. Type 'help' for list.\n", command);
        }
    }

    return 0;
}
