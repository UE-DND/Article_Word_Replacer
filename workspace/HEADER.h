#pragma once
#pragma GCC optimize(3,"Ofast","inline")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_FILENAME_LEN 256

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void display_menu();
void get_valid_input(void *input, const char *prompt, const char *type, int min, int max);
void create_folder(const char* folder_name);  // 文件夹创建模块
int read_file(const char* filename, char* content);  // 文件读取模块
void write_file(const char* filename, const char* content);  // 文件写入模块
void count_words(const char* content, WordCount* word_list, int* word_count);  // 统计模块
void replace_word(const char* content, const char* original_word, const char* replacement_word, int interactive, const char* original_filename);  // 单词替换模块
void save_statistics(const char* original_filename, WordCount* word_list, int word_count);  // 结果保存模块