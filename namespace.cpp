#include <iostream>

namespace NS_IdleUeCleanUp
{
     //Last Idle UE cleanup triggered time
    bool g_bIdleUeCleanUpTriggered = false;
    const int nThirtyMins = 1800;
};



int main()
{
  std::cout << "NS_IdleUeCleanUp::NS_IdleUeCleanUp" << NS_IdleUeCleanUp::nThirtyMins << std::endl;
}
