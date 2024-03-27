#ifndef POINTER_H
#define POINTER_H

class Counter{
    private:
        unsigned int m_counter;
    public:
        Counter():m_counter(0){}

        void resetCounter(){
            m_counter = 0;
        }
};

template <typename T>
class SharePointer{
    public:
};


template <typename T>
class WeakPointer{
    public:
};


#endif