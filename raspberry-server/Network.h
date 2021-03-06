/* ====================================================================
 * This file is part of Raspcopter.
 *
 * Copyright (C) 2014 - Florent Revest <florent.revest666@gmail.com>

 * Raspcopter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Raspcopter is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Raspcopter.  If not, see <http://www.gnu.org/licenses/>.
 * ================================================================== */

#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <stdio.h>
#include <enet/enet.h>
#include <pthread.h>
#include <string.h>

// Opcodes received from the Ground Control Station
#define SET_WANTED_ROLL     0x00
#define SET_WANTED_PITCH    0x01
#define SET_WANTED_YAW      0x02
#define SET_WANTED_THROTTLE 0x03
#define SET_PID_VALUES      0x04

// Opcodes sent to the Ground Control Station
#define SET_MEASURED_VALUES 0x05
#define SET_CPU_USAGE       0x06
#define SET_MEMORY_USAGE    0x07

class Network
{
public:
    Network();
    ~Network();
    static void *readThread(void *);
    void send(char opcode, const void *data, size_t dataLength, bool reliable);

private:
    static ENetPeer *client;
    static ENetHost *server;

    pthread_t thread;
    static pthread_mutex_t net_mutex;
};

#endif // _NETWORK_H
