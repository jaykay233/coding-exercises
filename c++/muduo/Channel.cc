#include "Channel.h"
#include "EventLoop.h"
#include "Logger.h"
#include <sys/epoll.h>

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = EPOLLIN | EPOLLPRI;
const int Channel::kWriteEvent = EPOLLOUT;

// EventLoop: ChannelList, Poller
Channel::Channel(EventLoop *loop, int fd) : loop_(loop), fd_(fd), events_(0), revents_(0), index_(-1), tie_(false)
{
}

Channel::~Channel()
{

}

// channel的tie方法什么时候调用过？
void Channel::tie(const std::shared_ptr<void>&)
{
    tie_ = obj;
    tied_ = true;
}

/*
    当改变channel所表示fd的events事件后，update负责在poller里面更改fd相应的事件epoll_ctl
    EventLoop => ChannelList Poller
*/
void Channel::update()
{
    // 通过channel所属的EventLoop调用poller的相应方法，注册fd的event事件
    // add code ...
    // loop_->updateChannel(this);
}

// 在Channel所属的EventLoop中，把当前的channel删除掉
void Channel::remove()
{
    // add code ...
    // loop_->removeChannel(this);
}

void Channel::handleEvent(Timestamp receiveTime)
{
    if(tied_)
    {
        std::shared_ptr<void> guard = tie_.lock();
        if(guard)
        {
            handleEventWithGuard(receiveTime);
        }
    }
    else{
        handleEventWithGuard(receiveTime);
    }
}

// 根据poller通知的Channel发生的具体事件，由Channel负责调用具体的回调操作  __FUNCTION__ __LINE__
void Channel::handleEventWithGuard(Timestamp receiveTime)
{
    LOG_INFO("channel handleEvent revents:%d", revents_);

    if ((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN))
    {
        if(closeCallback_)
        {
            closeCallback_();
        }
    }

    if (revents_ & EPOLLERR)
    {
        if (errorCallback_)
        {
            errorCallback_();
        }
    }

    if (revents_ & (EPOLLIN | EPOLLPRI))
    {
        if(readCallback_)
        {
            readCallback_(receiveTime);
        }
    }

    if (revents & EPOLLOUT)
    {
        if (writeCallback_)
        {
            writeCallback_();
        }
    }
}