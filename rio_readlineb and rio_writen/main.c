#include <unistd.h>
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <string.h>
#include <csapp.h>

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n) {
    int cnt;

    while (rp->rio_cnt <= 0) {
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
        if (rp->rio_cnt < 0) {
            if (errno != EINTR)  //遇到中断类型错误的话应该进行读取，否则就返回错误
                return -1;
        } else if (rp->rio_cnt == 0)   //读取到了EOF
            return 0;
        else
            rp->rio_bufptr = rp->rio_buf;       //重置bufptr指针，令其指向第一个未读取字节，然后便退出循环
    }

    cnt = n;
    if ((size_t) rp->rio_cnt < n)
        cnt = rp->rio_cnt;
    memcpy(usrbuf, rp->rio_bufptr, n);
    rp->rio_bufptr += cnt;      //读取后需要更新指针
    rp->rio_cnt -= cnt;         //未读取字节也会减少

    return cnt;
}

void rio_readinitb(rio_t *rp, int fd) {
    rp->rio_fd = fd;
    rp->rio_cnt = 0;
    rp->rio_bufptr = rp->rio_buf;
}

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen) {
    int n, rc;
    char c, *bufp = usrbuf;

    for (n = 1; n < maxlen; n++) {
        if ((rc = rio_read(rp, &c, 1)) == 1) {
            *bufp++ = c;
            if (c == '\n') {
                n++;
                break;
            }
        } else if (rc == 0) {
            if (n == 1)
                return 0; /* EOF, no data read */
            else
                break;    /* EOF, some data was read */
        } else
            return -1;      /* Error */
    }
    *bufp = 0;
    return n - 1;
}

ssize_t rio_writen(int fd, void *usrbuf, size_t n) {
    size_t nleft = n;
    ssize_t nwritten;
    char *bufp = usrbuf;

    while (nleft > 0) {
        if ((nwritten = write(fd, bufp, nleft)) <= 0) {
            if (errno == EINTR)  /* Interrupted by sig handler return */
                nwritten = 0;    /* and call write() again */
            else
                return -1;       /* errno set by write() */
        }
        nleft -= nwritten;
        bufp += nwritten;
    }
    return n;
}

int main() {
    size_t n;
    rio_t rio;
    char buf[512];

    rio_readinitb(&rio, STDIN_FILENO);
    while ((n = rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        rio_writen(STDOUT_FILENO, buf, n);
    }
    return 0;
}
