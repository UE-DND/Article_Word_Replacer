void display_menu() {
    printf("\n");
    printf("******************************\n");
    printf("*        英文文章处理程序        *\n");
    printf("******************************\n");
    
    printf("\n");
    printf("请选择操作：\n");

    printf("\033[31m1. \033[0m统计单词\n");
    printf("\033[31m2. \033[0m替换单词\n");
    printf("\033[31m3. \033[0m退出\n");

    printf("\n");
    printf("******************************\n");
    printf("\n");
}

void get_valid_input(void *input, const char *prompt, const char *type, int min, int max) {
    if (strcmp(type, "int") == 0) {
        // 整数类型输入
        while (1) {
            printf("%s", prompt);  // 输出提示信息
            if (scanf("%d", (int *)input) != 1 || *((int *)input) < min || *((int *)input) > max) {
                while (getchar() != '\n');
                printf("无效输入，请输入一个数字 (%d - %d): ", min, max);
            } else {
                break;
            }
        }
    } else if (strcmp(type, "word") == 0) {
        // 字符类型输入
        while (1) {
            printf("%s", prompt);
            scanf("%s", (char *)input);
            int flag = 1;
            for (int i = 0; ((char *)input[i] != '\0'); i++) {
                if (!isalpha(((char *)input)[i])) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                break;
            } else {
                printf("无效输入，请输入一个只包含字母的单词: ");
            }
        }
    }
}

void create_folder(const char *folder_name) {
#ifdef _WIN32
    _mikdir(folder_name);
#else
    mkdir(folder_name, 0777);
#endif
}

int read_file(const char *filename, char *content) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开文件: %s\n", filename);
        return 0;
    }
    
    char line[MAX_LINE_LEN];
    content[0] = '\0';  // 初始化内容为空字符串

    // 逐行读取文件内容
    while (fgets(line, sizeof(line), file)) {
        strcat(content, line);
    }

    fclose(file);
    return 1;
}

void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("文件写入失败！\n");
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}

void count_words(const char *content, WordCount *word_list, int *word_count) {
    char temp_content[MAX_LINE_LEN * 100];
    strcpy(temp_content, content);  // 复制内容到临时变量

    char *token = strtok(temp_content, " \n\t.,;:!?()[]\"'");  // 分割单词
    *word_count = 0;

    while (token) {
        // 逐个转换为小写
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        int found = 0;  // 标记是否找到重复单词
        for (int i = 0; i < *word_count; i++) {
            if (strcmp(word_list[i].word, token) == 0) {
                word_list[i].count++;
                found = 1;  // 标记为已找到
                break;
            }
        }

        if (!found) {
            strcpy(word_list[*word_count].word, token);
            word_list[*word_count].count = 1;
            (*word_count)++;
        }

        token = strtok(NULL, " \n\t.,;:!?()[]\"'");  // 继续分割，token为NULL时终止loop
    }
}

void replace_word() {
    
}