 FGW_LOG_FN_ENTRY();
    CFasApplication* pCFasApplnObj = &CFasApplication::GetInstance();
    /*TODO:Need to Get the IpAddress of the FAP in question from WSH*/
    sFapWshMessage* psFapWshMessage=(sFapWshMessage*)pThreadParam;
    CFasTr069JobHandler *pTJHObj = CFasTr069JobHandler::GetInstance();
    uint32_t sockfd =   pCFasApplnObj->GetDeregFapSockfd();
    char *pPacket = NULL;
    struct icmp *icp = NULL;
    PING_DATA *pdp = NULL;
    struct timezone tz;

    pPacket = (char * )malloc( SIZE_ICMP_HDR + sizeof(PING_DATA));

    if ( pPacket == NULL)
    {
        FGW_LOG_ERROR("FAS ERROR : Malloc Failure : Cant Allocate Packet. Exiting Thread");
        pCFasApplnObj->SetSyncFlag(false);
        return 1;
    }

    for ( int j = 0 ; j < PING_COUNT_PER_HOST ; j++)
    {
#ifndef __FGW_MT__
        usleep(1000);
#endif
        if (psFapWshMessage->uRecvCount==0)
        {
            memset( pPacket, 0,sizeof(pPacket));
            icp = (struct icmp*) (pPacket );
            icp->icmp_type = ICMP_ECHO;
            icp->icmp_code = 0;
            icp->icmp_cksum = 0;
            icp->icmp_seq = 1;
            pdp = ( PING_DATA* )( pPacket + SIZE_ICMP_HDR );
            gettimeofday( &(pdp->ping_ts), &tz );
            pdp->ping_count = 1;
icp->icmp_id = sockfd & 0xFFFF;
            icp->icmp_cksum = in_cksum( ( u_short* )icp,  SIZE_ICMP_HDR + sizeof(PING_DATA) );
            if ( sendto(sockfd, pPacket, SIZE_ICMP_HDR + sizeof(PING_DATA), 0, (struct sockaddr *)&(psFapWshMessage->addr), sizeof(struct sockaddr_in)) < 0)
            {
                FGW_LOG_ERROR("FAS ERROR : Sent Error for Host %s  : %s",psFapWshMessage->sFapIp,strerror(errno));
            }
            else
            {
                psFapWshMessage->uSendCount++;
                FGW_LOG_ERROR("FAS ERROR:Ping Request Sent sucessfully to host %s",psFapWshMessage->sFapIp);
            }
        }
    }

    pCFasApplnObj->SetSyncFlag(false);

    FGW_LOG_DEBUG("FAS DEBUG: Finished Sending Ping Requests");
    if ((psFapWshMessage->uSendCount == PING_COUNT_PER_HOST ) && (psFapWshMessage->uRecvCount==0 ))
    {
        FGW_LOG_DEBUG("FAS DEBUG: Host %s Unreachable. Sending FAP Not Connected to WSH",psFapWshMessage->sFapIp);
        /*TODO Put Send Message Code in Here to Send FAP Not Connected Message to WSH*/
        free(pPacket);
        return WSH_FAP_NOT_CONNECTED;
    }
    free(pPacket);
    FGW_LOG_FN_EXIT();
    return 1;
}
