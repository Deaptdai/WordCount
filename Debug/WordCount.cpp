#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	    
    FILE *file;
    int charCount = 0, wordCount = 0;
    int inWord = 0; // 用于跟踪是否处于单词中

    // 打开文件
    file = fopen(argv[2], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // 读取文件并计数
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        charCount++; // 对每个字符进行计数

        // 检查是否为单词分隔符
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            if (inWord) {
                wordCount++; // 如果之前在单词中，增加单词计数
                inWord = 0; // 重置标志
            }
        } else {
            if (!inWord) {
                inWord = 1; // 进入单词
            }
        }
    }

    // 检查文件末尾是否有一个单词
    if (inWord) {
        wordCount++;
    }

    fclose(file); // 关闭文件

    // 输出结果
    if (argv[1][1] == 'c'){
		printf("Character count: %d\n", charCount);
	}else if (argv[1][1] == 'w'){
		printf("Word count: %d\n", wordCount);
	}
    return 0;
}
