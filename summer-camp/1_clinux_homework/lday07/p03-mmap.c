#include <func.h>

#define MMAP_SIZE (4096 * 10)  //以页为单位

int main(int argc, char* argv[]){
    // ./map_cp stc dst
    if(argc != 3){
        error(1, 0, "Usage: %s src dst", arg[0]);
    }

    int srcfd = open(argv[1], O_RDONLY);
    if(srcfd == -1){
        errpr(1, errno, "open %s", argv[1]);
    }

    int dstfd = open(argv[2], O_RDWR | R_CREAT | R_TRUNC, 0666);
    if(dstfd == -1){
        close(srcfd);
        error(1, errno, "open %s", argv[2]);
    }

    //1. 文件大小需要事先确定 lseek或者fstat
    // 获取src的大小
    struct stat sb;  //stat buffer
    fstat(srcfd, &sb);  //sb.st_size
    off_t fsize = sb.st_size;
    // 将dst文件的大小设置为 sb.st_size;
    ftruncate(dstfd, sb.st_size);

 	off_t offset = 0; //已复制的数据
    while(offset < sb.st_size){
        off_t length;  // 映射区的长度
        if(fsize - offset >= MMAP_SIZE){
            length = MMAP_SIZE;
        }else{
            length = fsize - offset;
        }

        void* addr1 = mmap(NULL, length, PROT_READ, MAP_SHARED, srcfd, offset);
        if(addr1 == MAP_FAILED){
            error(1, errno, "mmap %s", argv[1]);
        }
        void* addr2 = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, srcfd, offset);
        if(addr2 == MAP_FAILED){
            error(1, errno, "mmap %s", argv[2]);
        }
        // 以操作内存的方式，操作文件
        memcpy(addr2, addr1, length);

        // 解除映射
        int err = munmap(addr1, length);
        if (err) {
            error(1, errno, "munmap");
        }
        err = munmap(addr2, length);
        if (err) {
            error(1, errno, "munmap");
        }

        offset += length;
    } // offset == sb.st_size

    // 关闭文件
    close(src);
    close(dst);

    return 0;
}
