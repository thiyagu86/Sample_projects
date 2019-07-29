#include <iostream>
typedef union epoll_data
{
  void *ptr;
  int fd;
  uint32_t u32;
  uint64_t u64;
} epoll_data_t;

struct epoll_event
{
  uint32_t events;      /* Epoll events */
  epoll_data_t data;    /* User data variable */
};

struct epoll_event g_aEpollEvents[20010];
int main()
{
    printf("size = %d\n", sizeof(g_aEpollEvents));
    memset(g_aEpollEvents, 0, sizeof(g_aEpollEvents));
    return 0;
}
