#!/bin/sh
gcc -D __DEBUG__ main.c nsu.c nsu_utils.c nsu_tcp.c nsu_ip.c nsu_ethernet.c debuglib.c
