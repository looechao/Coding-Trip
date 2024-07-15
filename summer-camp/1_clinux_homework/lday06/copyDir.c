#include <func.h>


void copyFile(const char* src, const char* dst) {
	// 复制文件
    int src_fd = open(src, O_RDONLY);
    if (src_fd == -1) {
        error(1, errno, "open %s failed", src);
    }

    int dst_fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dst_fd == -1) {
        error(1, errno, "open %s failed", dst);
    }

    char buffer[4096];
    int bytes;
    while ((bytes = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dst_fd, buffer, bytes);
    }

    close(src_fd);
    close(dst_fd);

    if (bytes < 0) {
        error(1, errno, "read");
    }
}

void copyDir(const char* src, const char* dst) {
    // 创建dst目录
    mkdir(dst, 0777);
    // 打开src目录
    DIR* pdir = opendir(src);
    if (pdir == NULL) {
        error(1, errno, "opendir");
    }
    // 遍历目录流
    struct dirent* pdirent;
    while((pdirent = readdir(pdir)) != NULL) {
        // 忽略.和..
        const char* name = pdirent->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
            continue;
        }

        char subsrc[1024];
        char subdst[1024];
        sprintf(subsrc, "%s/%s", src, name);
        sprintf(subdst, "%s/%s", dst, name);
        // 如果该目录项是目录，则调用copyDir递归复制
        if (pdirent->d_type == DT_DIR) {
            copyDir(subsrc, subdst);
        } else if (pdirent->d_type == DT_REG) {
        // 如果该目录项是文件，则调用copyFile复制文件
            copyFile(subsrc, subdst);
        }
    }

    // 关闭目录流
    closedir(pdir);
    if (errno) {
        error(1, errno, "readdir");
    }
}

int main(int argc, char* argv[]) {
    // ./copyDir src dst
    if (argc != 3) {
        error(1, 0, "参数输入不正确");
    }
    copyDir(argv[1], argv[2]);
    return 0;
}
