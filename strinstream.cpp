#include <iostream>
#include <sstream>
#define RHP_BUFFER_SIZE "HIHOWAREYOU"
int main()
{
    std::stringstream strbuf;
    std::string strFapCurSwVersion = "2.0";
    std::string strFapHwVersion = "3.0";
    char acTime[24];
    time_t t = time(NULL);
    strftime(acTime, 25, "%Y-%m-%d %H:%M:%S%z", localtime(&t));
    //std::cout << acTime<< std::endl;
    unsigned int unfapid = 20;
    std::string strServiceClass ="OUAP";
    
    strbuf<<"create or replace view HnbView1 as "
		<<"(select * from FGW_DBS_CLT_HNB_REG_TBL1 where FAP_REGTIME >= DATE_SUB(NOW(), INTERVAL 1 DAY)) "
		<<"union "
		<<"(select * from FGW_DBS_CLT_HNB_REG_TBL3 where FAP_REGTIME >= DATE_SUB(NOW(), INTERVAL 1 DAY))";	
    std::cout << strbuf.str() << std::endl;
    return 0;

}
