#include <iostream>
#include "/home/thiyagu/off/log4cplus/include/log4cplus/logger.h"
#include "log4cplus/include/log4cplus/logger.h"
#include "log4cplus/include/log4cplus/fileappender.h"
#include "log4cplus/include/log4cplus/loglevel.h"
#include "log4cplus/include/log4cplus/configurator.h"
Logger OM_Log = Logger::getInstance("SampleForLog4Cplus.cpp");


using namespace std;

int main()
{
    LOG4CPLUS_INFO(OM_Log,"Hi how are you?");
    return 0;
}
