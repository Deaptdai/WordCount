#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	    
    FILE *file;
    int charCount = 0, wordCount = 0;
    int inWord = 0; // ���ڸ����Ƿ��ڵ�����

    // ���ļ�
    file = fopen(argv[2], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // ��ȡ�ļ�������
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        charCount++; // ��ÿ���ַ����м���

        // ����Ƿ�Ϊ���ʷָ���
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            if (inWord) {
                wordCount++; // ���֮ǰ�ڵ����У����ӵ��ʼ���
                inWord = 0; // ���ñ�־
            }
        } else {
            if (!inWord) {
                inWord = 1; // ���뵥��
            }
        }
    }

    // ����ļ�ĩβ�Ƿ���һ������
    if (inWord) {
        wordCount++;
    }

    fclose(file); // �ر��ļ�

    // ������
    if (argv[1][1] == 'c'){
		printf("Character count: %d\n", charCount);
	}else if (argv[1][1] == 'w'){
		printf("Word count: %d\n", wordCount);
	}
    return 0;
}
