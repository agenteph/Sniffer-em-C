struct ip {
	       unsigned int        ip_length:4;         /* length of ip-header in 32-bit
                                                           words*/
 	       unsigned int        ip_version:4;        /* set to "4", for Ipv4 */
	       unsigned char       ip_tos;              /* type of service*/
	       unsigned short      ip_total_length;     /* Total length of ip datagram in
                                                           bytes */
	       unsigned short      ip_id;               /*identification field*/
	       unsigned short      ip_flags;
	       unsigned char       ip_ttl;              /*time-to-live, sets upper limit
                                                          for max number of routers to 
                                                          go through before the packet is
                                                          discarded*/

	       unsigned char       ip_protocol;         /*identifies the correct transport
			                                  protocol */
	       unsigned short      ip_cksum;            /*calculated for the ip header ONLY*/
               unsigned int        ip_source;           /*source ip */
               unsigned int        ip_dest;             /*dest ip*/
	};



	struct tcp {
                 unsigned short     tcp_source_port; /*tcp source port*/
	         unsigned short     tcp_dest_port;   /*tcp dest port*/
	         unsigned int       tcp_seqno;       /*tcp sequence number,
                                                       identifies the byte in the 
                                                       stream of data*/
	         unsigned int       tcp_ackno;       /*contains the next seq num that
                                                       the sender expects to recieve*/
	         unsigned int       tcp_res1:4,      /*little-endian*/
                                    tcp_hlen:4,      /*length of tcp header in 32-bit
                                                       words*/ 
	                            tcp_fin:1,       /*Finish flag "fin"*/
                                    tcp_syn:1,       /*Synchronize sequence
                                                       numbers to start a connection
		                    tcp_rst:1,       /*Reset flag */
                                    tcp_psh:1,       /*Push, sends data to the
                                                       application*/
                                    tcp_ack:1,       /*acknowledge*/
                                    tcp_urg:1,       /*urgent pointer*/
                                    tcp_res2:2;
                 unsigned short     tcp_winsize;     /*maxinum number of bytes able
		                                       to recieve*/
	         unsigned short     tcp_cksum;       /*checksum to cover the tcp
                                                       header and data portion of the
                                                       packet*/

	         unsigned short     tcp_urgent;     /*vaild only if the urgent flag is
			                              set, used to transmit
                                                      emergency data */
	};
