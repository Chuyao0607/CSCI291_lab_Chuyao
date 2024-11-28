#include <stdio.h>

FILE* qn;
FILE* flt;

int main() {
    qn = fopen("question1text.text", "r");
    if (qn != NULL) {
        // 移动文件指针到第6个字节
        if (fseek(qn, 6, SEEK_SET) == 0) {
            while (1) {
                char ch = fgetc(qn); // 读取一个字符
                if (ch == EOF) { // 如果遇到文件结尾，退出循环
                    printf("End of file reached.\n");
                    break;
                }

                if (ch == ' ') { // 假设遇到空格是浮点数的标志
                    printf("It is a float number: %d\n", ch); // 打印字符的整数值
                    flt = fopen("float.text", "w");
                    if (flt != NULL) {
                        fputc(ch, flt); // 将字符写入文件
                        fclose(flt);
                    } else {
                        printf("Failed to open float.text.\n");
                    }
                } else {
                    printf("It is an alpha character: %c\n", ch); // 打印字母字符
                }
            }
        }
        fclose(qn); // 关闭文件
    } else {
        printf("File is not opened.\n");
    }
    return 0;
}

