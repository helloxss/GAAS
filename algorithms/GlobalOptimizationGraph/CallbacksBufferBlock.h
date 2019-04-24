#ifndef CALLBACK_BUFFER_BLOCK_H
#define CALLBACK_BUFFER_BLOCK_H


//#include <queue>
#include <deque>

template <typename T>
class CallbackBufferBlock
{
public:
    CallbackBufferBlock<T>();
    void onCallbackBlock(const T& msg);
    double queryLastMessageTime();
    T getLastMessage();
    inline int size()
    {
        return this->msgBuffer.size();
    }
private:
    //std::queue<T> msgBuffer;
    std::deque<T> msgBuffer;
    const int buffer_size = 100;
};
template <typename T>
void CallbackBufferBlock<T>::onCallbackBlock(const T& msg)
{
    //access: .front(),.back().
    //push_front,push_back();
    //pop_front,pop_back();
    //at(),operator []
    this->msgBuffer.push_front(msg); //msgBuffer.front() oldest.msgBuffer.end() latest.
    if (this->msgBuffer.size()>=this->buffer_size)
    {
        this->msgBuffer.pop_back();
    }
}
template <typename T>
double CallbackBufferBlock<T>::queryLastMessageTime()
{
    return this->msgBuffer.front().header.stamp.toSec();
}
template <typename T>
T CallbackBufferBlock<T>::getLastMessage()
{
    if (this->msgBuffer.size() > 0)
    {
        return this->msgBuffer.front();
    }
}

#endif




