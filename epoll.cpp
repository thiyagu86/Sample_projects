#include <iostream>
#include <sys/epoll.h>

#define MAX_FD 3
using namespace std;
struct epoll_event ev, *events;
int main()
{
    cout << "entering Main" << endl;
  
    epoll_create(MAX_FD);
    for (;;)
    {
        nfds = epoll_wait(kdpfd, events, maxevents, -1);
        for (n = 0; n < nfds; ++n)
        {
            if (events[n].data.fd == listener)
            {
                client = accept(listener, (struct sockaddr *) &local,
                                &addrlen);
                if (client < 0)
                {
                    perror("accept");
                    continue;
                }
                setnonblocking(client);
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = client;
                if (epoll_ctl(kdpfd, EPOLL_CTL_ADD, client, &ev) < 0)
                {
                    cout << "epoll set insertion error: fd= "<<client;
                    return -1;
                }
            }
            else
            {
                do_use_fd(events[n].data.fd);
            }
        }
    }
}
