---
layout: page
title: Intro to Computer Communications
permalink: /comms/
description: My notes for the intro to computer communications course
sitemap:
  priority: 0.7
  changefreq: "monthly"
date: '2024-05-04'
categories: cpp
tags:
- Communications
- UDP
- TCP
- ComputerCommunications
---

TCP/IP Model

5. Application

    - Message

4. Transport

    - Segment

3. Network

    - Datagram

2. Link

    - Frame 

1. Physical

OSI Model takes the Application layer and splits it to 3 different "layers":

* Application

* Presentation

* Session


8 Bits = 1 Byte

IPv4: 

    * 32 bit address = 4 bytes 

    * 8 bits.8 bits.8 bits.8 bits In binary

    * Each section can get values from 0-255 = 256 total values

    * Network Address = set all host bits to 0 

    * Broadcast address = set all host bits to 1 

    * number of available host addresses - need to subtract 2 from # of available addresses (cause of net address and broadcast address) 


Packet transmission delay: L (bits) / R (bits/sec)

Propagation delay:

    *  d(length of physical link)/s (prop speed)

    *  Often times use speed of light 3*10^8 for fiber 

    *  For copper use 2 * 10^8 

    *  Still quite fast but will never get to speed of light 

ARP: 

   *  Send a request via MAC to broadcast and ask for someone’s IP

   *  MAC broadcast is all bits set to 1, which in HEX will result in an address with lot of F’s

   *  It is a layer 2-ish protocol 

TTL: 
   *  time to live - 1 byte - so can be from 0 to 255 

   *  Measured in hops not seconds or any other time unit

   *  Start with X for TTL, Every router we pass, TTL = TTL-1

   *  Once we get to 0, packet gets dropped and often we get an ICMP response telling us that happened 

TCP: 
   *  NO BROADCAST EXISTS HERE  

        - As we need a destination port and 3 way handshake with someone

TCP Socket: 

   *  Needs all 4 of these:  SRC IP, SRC PORT, DEST IP, DEST PORT
   
   *  Socket is two-way like a pipe with opening on both sides (src - dest)      

Broadcast packet never gets past the router (gets dropped), otherwise many more computers than anticipated will get these packets

Switch - Internal to a network 

Forwarding table - Where to send packet to

Router: 

   *  Sits between your network and the internet (more or less)

   *  Converts your internal IP to a public one via Network Address Translation

ICMP: 

   *  Wrapped in an IP packet

   *   If it is an error report, you will get IP header - ICMP header - IP header 

         -  2nd ip header is a minimum of first 8 bytes of the packet that caused the error
         -  Can and may be more bytes of previous packet

   *  Layer 3ish protocol 



### Helpful Links


https://gaia.cs.umass.edu/kurose_ross/interactive/ (practice quizzes) 


https://www2.ic.uff.br/~michael/kr1999/1-introduction/1_06-delay.htm
