#include <func.h>

int main(int argc, char* argv[])
{
    // ./copy src dst
    if (argc != 3) {
        error(1, errno, "Usage: %s src dst", argv[0]);
    }
    // 1. 打开src和dst
    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        error(1, errno, "open %s", argv[1]);
    }
    int dst = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if (dst == -1) {
        error(1, errno, "open %s", argv[2]);
    }
    // 2. 复制文件
    char buffer[4096];
    int bytes;
    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        // 实际读了bytes个字节，所以写入bytes字节
        write(dst, buffer, bytes);
    }
    // 3. 关闭文件
    close(src);
    close(dst);
    return 0;
}
