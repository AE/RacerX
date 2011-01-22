#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

#define FWD 0
#define REV 1

#define LFT 0
#define RGT 1

#define SPD 0
#define UNITS 1

#define MPH 0
#define KPH 1
#define FPSEC 2

int speed_units = MPH;
int speed = 0;
double telemetry[4];

typedef struct command_data COMMAND_DATA;

struct command_data {
    char command;       // command code
    int param1;
    double param2;     
    int done;           // to specify if the command has been executed 
    long int time_usec; // the amount of time in microseconds that the command is to be executed
    COMMAND_DATA *next;
};


int command_parser(COMMAND_DATA *command_node, char command[20]) 
{
    char ch = command[0];
    int i = 4;
    int j = 0;
    char param2[20];
    char time_usec[20];
    switch (ch) 
    {   
        case ('m') :
        case ('M') :    // Move
                        
                        command_node->command = 'm';
                        if (command[2] == 'f' || command[2] == 'F')
                        {
                            command_node->param1 = FWD;
                        }
                        else if (command[2] == 'r' || command[2] == 'R')
                        {
                            command_node->param1 = REV;
                        }
                            else
                            {
                                    return 2;
                            }
                        break;
                            
        case ('t') :
        case ('T') :    // Turn

                        command_node->command = 't';
                        if (command[2] == 'l' || command[2] == 'L')
                        {
                            command_node->param1 = LFT;
                        }
                        else if (command[2] == 'r' || command[2] == 'R')
                        {
                            command_node->param1 = RGT;
                        }
                            else
                            {
                                    return 2;
                            }
                        break;

        case ('s') :
        case ('S') :    // set speed/units
                        command_node->command = 's';
                        if (command[2] == 's' || command[2] == 'S')
                        {
                            command_node->param1 = SPD;
                            ch = command[i];
                            while (i < 20 && !isspace(ch))
                            {
                                param2[j] = ch;
                                i++;
                                ch = command[i];
                                j++;
                            }
                            command_node->param2 = atoi(param2);
                            if(command_node->param2 < 0 || command_node->param2 > 100)
                                return 4;
                        }
                        else if (command[2] == 'u' || command[2] == 'U')
                        {
                            command_node->param1 = UNITS;
                            int units = command[4] - '0';
                            command_node->param2 = units;
                            if(command_node->param2 < 0.0 || command_node->param2 > 2.0)
                            {
                                return 4;
                            }
                        }
                            else
                            {
                                    return 2;
                            }
                        command_node->time_usec = 500; 
                        break;
        default :
                        // should not be here
                        return 0;


    }
    if(command_node->command == 'm' || command_node->command == 't')
    {
        ch = command[i];
        while (i < 20 && !isspace(ch))
        {
            param2[j] = ch;
            i++;
            ch = command[i];
            j++;
        }
        command_node->param2 = atof(param2);
        if (command_node->param2 == 0.0)
        {
            return 4;
        }
        i++;
        j = 0;
        ch = command[i];
        while (i < 20 && !isspace(ch))
        {
          time_usec[j] = ch;
          i++;
          ch = command[i];
          j++;
        }
        command_node->time_usec = strtol(time_usec, NULL, 10);
        if (command_node->time_usec < 10 || command_node->time_usec > 10000000)
        {
          return 19;
        }
          
    }

    return 21;     
}


double get_telemetry_info(void) 
{
    /*
     * telemetry[0] = speed
     * telemetry[1] = latitude
     * telemetry[2] = longitude
     * telemetry[3] = orientation
     */

    telemetry[0] = rand() % 100;
    telemetry[1] = 42.348988;  
    telemetry[2] = -71.104243;  
    telemetry[3] = rand() % 360;
}

double set_speed(int percentage)
{
    speed = percentage;
    printf("Setting speed to %d. \n", percentage); 

}

int move(int direction, double distance)
{
    if(direction)
        printf("Moving the buggy by a distance of %lf, in the reverse direction. \n", distance);
    else
        printf("Moving the buggy by a distance of %lf, in the forward direction. \n", distance);

}

int turn(int direction, double angle)
{
    if(direction)
        printf("Turning the buggy by an angle of %lf, in the right direction. \n", angle);
    else
        printf("Turning the buggy by an angle of %lf, in the left direction. \n", angle);

}

int set_speed_units(int units)
{
    printf("Setting speed to unit %d.\n", units);
    speed_units = units;
}

int execute_command(char cmd, int param1, double param2)
{
    switch (cmd)
    {
        case 'm':
                move(param1, param2);
                break;
        case 't':
                turn(param1, param2);
                break;
        case 's':
                if(param1) 
                    set_speed_units((int) param2);
                else
                    set_speed((int) param2);
    }
    
}

