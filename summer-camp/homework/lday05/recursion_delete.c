#include <func.h>
#include <unistd.h>

void deleteDir(const char* path);


int main(int argc, char *argv[])
{
    // ./deleteDir dir
    ARGS_CHECK(argc, 2);
    DIR* pdir = opendir(".");
    ERROR_CHECK(pdir, NULL, "opendir");

    long loc = telldir()
                
    deleteDir(argv[1]);
    return 0;
}

void deleteDir(const char* path) {
	// 打开目录
    // 遍历目录流，依次删除每一个目录项
    while ((pdirent = readdir(pdir)) != NULL) {
        // 忽略.和..
        // 如果该目录项是目录，则调用deleteDir递归删除
        // 如果该目录项是文件，则调用unlink删除文件
    }

    // 目录为空了，可以删除该目录了
	// 关闭目录流
}
