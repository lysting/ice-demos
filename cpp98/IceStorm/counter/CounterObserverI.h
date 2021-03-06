// **********************************************************************
//
// Copyright (c) 2003-2017 ZeroC, Inc. All rights reserved.
//
// **********************************************************************

#ifndef COUNTER_OBSERVER_I
#define COUNTER_OBSERVER_I

#include <Counter.h>

class MTPrinter : public IceUtil::Shared
{
public:

    MTPrinter()
    {
    }
    
    void print(const std::string& data)
    {
        IceUtil::Mutex::Lock sync(_mutex);
        std::cout << data << std::flush;
    }
    
private:

    IceUtil::Mutex _mutex;
};
typedef IceUtil::Handle<MTPrinter> MTPrinterPtr;

class CounterObserverI : public Demo::CounterObserver
{
public:

    CounterObserverI(const MTPrinterPtr& printer);

    virtual void init(int, const Ice::Current&);
    virtual void inc(int, const Ice::Current&);

private:

    int _value;
    MTPrinterPtr _printer;
    IceUtil::Mutex _mutex;
};

#endif
