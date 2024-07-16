#include <func.h>

int main(int argc, char* argv[])
{
    // ./p01 text1
    if( argc != 2 ){
        error(1, 0, "Usage: ./%s text", argv[0]);
    }//打开文件
    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
    //将文件的大小截断为40959
    off_t length;
    length = 40959;
    if(fd == -1){
        error(1, errno, "open %s failed", argv[1]);
    };
    if(ftruncate(fd, length) == -1){
        error(1, errno, "ftuncate %s failed", argv[1]);
    };
;   // 将off_t 移动到末尾
    length = lseek(fd, 0, SEEK_END);
    
    char* str = "Hello world\n";
    if( write(fd, str, strlen(str)) == -1 ){
        error(1, errno, "write %s failed", argv[1]);
    }
    struct stat sb; //存储元数据信息
    if(fstat(fd, &sb) == -1){
        error(1, errno, "fstat %d", fd);
    }

    //打印出实际占用的块数
    printf("blocks: %d\n", sb.st_blocks);
    return 0;
}

