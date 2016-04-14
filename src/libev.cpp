//============================================================================
// Name        : libev.cpp
// Author      : song
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <ev.h>
#include <stdio.h>

ev_io stdin_watcher;
ev_timer timeout_watcher;

static void stdin_cb(EV_P_ ev_io *w,int revents)
{
    puts ("stdin ready");
    ev_io_stop(EV_A_ w);
    ev_break (EV_A_ EVBREAK_ALL);
}

static void timeout_cb (EV_P_ ev_timer *w,int revents)
{
    puts ("timeout");
    ev_break( EV_A_ EVBREAK_ONE );
}

int main(int argc,char* argv[])
{
    struct ev_loop *loop = EV_DEFAULT;

    ev_io_init(&stdin_watcher,stdin_cb,0,EV_READ);
    ev_io_start (loop,&stdin_watcher);

    ev_timer_init (&timeout_watcher,timeout_cb,20.5,0); // in document the last is 0. not 0,I don't know why yet
    ev_timer_start (loop,&timeout_watcher);

    ev_run (loop,0);

    return 0;
}
