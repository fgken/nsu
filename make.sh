#!/bin/sh
gcc -D __DEBUG__ main.c nsu.c nsu_utils.c nsu_tcp.c nsu_udp.c nsu_ipv4.c nsu_ipv6.c nsu_ethernet.c nsu_nic.c debuglib.c
