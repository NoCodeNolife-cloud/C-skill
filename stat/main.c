#include <csapp.h>

int main() {
    struct stat st;
    if (-1 == stat("test.txt", &st)) {
        printf("获得文件状态失败\n");
        return -1;
    }

    printf("包含此文件的设备ID:%d\n", st.st_dev);
    printf("此文件的节点:%d\n", st.st_ino);
    printf("此文件的保护模式:%d\n", st.st_mode);
    printf("此文件的硬链接数:%d\n", st.st_nlink);
    printf("此文件的所有者ID:%d\n", st.st_uid);
    printf("此文件的所有者的组ID:%d\n", st.st_gid);
    printf("此设备ID（如果此设备为特殊设备）:%d\n", st.st_rdev);
    printf("此文件的大小:%d\n", st.st_size);
    printf("此文件的所在文件系统块大小:%d\n", st.st_blksize);
    printf("此文件的占用块数量:%d\n", st.st_blksize);
    printf("此文件的最后访问时间:%d\n", st.st_atime);
    printf("此文件的最后修改时间:%d\n", st.st_mtime);
    printf("此文件的最后状态改变时间:%d\n", st.st_ctime);
    return 0;
}
