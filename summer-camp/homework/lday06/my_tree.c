#include<func.h>

int directories = 0, files = 0;

void dfs_print(const char* path, int width){
    // 打开目录流
    DIR* stream = opendir(path);
    if(!stream){
        error(1, errno, "opender %s", path);
    }

    //递归的遍历每一个目录项
    errno = 0;
    struct dirent* pdirent;
    while((pdirent = readdir(stream)) != NULL){
        const char * filename = pdirent->d_name;
        // 忽略 . 和 ..
     	if(strcmp(filename,".") == 0 || strcmp(filename, "..") == 0){
            continue;
        }
        // 打印这个目录项的名字
        for(int i = 0; i < width; i++){
            putchar(' ');
        }
        puts(filename);
        //判定是不是目录

        if(pdirent->d_type == DT_DIR){
            directories++;
            //递归的处理, 拼接路径
            char subpath[128];
            sprintf(subpath, "%s/%s", path, filename);
            dfs_print(subpath, width + 4);
        }else{
            files++;
        }
    }//pdirent == NULL;

    closedir(stream);

    if(errno){
        error(1, errno, "readdir");
    }
}

int main(int argc, char *argv[]){
    //./young_tree_dir
    if(argc != 2){
        printf("Error!");
    }
    puts(argv[1]);

    dfs_print(argv[1], 4);

    printf("\n%d directories, %d files\n",directories, files);

    return 0;
}
