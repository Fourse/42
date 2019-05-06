#!/bin/sh
ifconfig | grep "ether " | cut -c 8- | cut -c -17;
