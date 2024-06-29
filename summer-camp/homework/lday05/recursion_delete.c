#include <func.h>

void deleteDir(const char* path) {
    // 删除每一个目录项
    // 打开目录流
    DIR* pdir = opendir(path);
    if (pdir == NULL) {
        error(1, errno, "opendir");
    }
    // 遍历目录流，递归地删除每一个目录项
    errno = 0;
    struct dirent* pdirent;
    while ((pdirent = readdir(pdir)) != NULL) {
        // 忽略 . 和 ..
        char* name = pdirent->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
            continue;
        }

        char subpath[1024];
        sprintf(subpath, "%s/%s", path, name);
        if (pdirent->d_type == DT_DIR) {
            // 拼接路径
            deleteDir(subpath);
        } else if (pdirent->d_type == DT_REG) {
            unlink(subpath);
        }
    } // pdirent == NULL

    closedir(pdir);

    if (errno) {
        error(1, errno, "readdir");
    }

    // 再删除改目录
    rmdir(path);
}

int main(int argc, char *argv[])
{
    // ./deleteDir path
    // 参数校验
    if (argc != 2) {
        error(1, 0, "参数教研失败");
    }

    // 递归地删除这个目录
    deleteDir(argv[1]);
    return 0;
}
