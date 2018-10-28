#include <iostream>


int main() {

    struct carTimes
    {
        int beggingHours, beggingMinutes;
        int endingHours, endingMinutes;
        int time;
    };

    carTimes cars[3];
    carTimes swap;
    int shortestTime = 0, longestTime = 0;

    while(cars[0].beggingHours > 24 || cars[0].beggingHours < 0 || cars[0].beggingMinutes > 60  ||
     cars[0].beggingMinutes < 0 || cars[0].endingHours > 24 || cars[0].endingHours < 0 || cars[0].endingMinutes > 60 || cars[0].endingMinutes < 0)
     {
        std::cin >> cars[0].beggingHours >> cars[0].beggingMinutes >> cars[0].endingHours >> cars[0].endingMinutes;
     }
    while(cars[1].beggingHours > 24 || cars[1].beggingHours < 0 || cars[1].beggingMinutes > 60  ||
     cars[1].beggingMinutes < 0 || cars[1].endingHours > 24 || cars[1].endingHours < 0 || cars[1].endingMinutes > 60 || cars[1].endingMinutes < 0)
     {
        std::cin >> cars[1].beggingHours >> cars[1].beggingMinutes >> cars[1].endingHours >> cars[1].endingMinutes;
     }

    while(cars[2].beggingHours > 24 || cars[2].beggingHours < 0 || cars[2].beggingMinutes > 60  ||
     cars[2].beggingMinutes < 0 || cars[2].endingHours > 24 || cars[2].endingHours < 0 || cars[2].endingMinutes > 60 || cars[2].endingMinutes < 0)
     {
        std::cin >> cars[2].beggingHours >> cars[2].beggingMinutes >> cars[2].endingHours >> cars[2].endingMinutes;
     }

    cars[0].time = (cars[0].endingMinutes + cars[0].endingHours*60) - (cars[0].beggingMinutes + cars[0].beggingHours*60); 
    cars[1].time = (cars[1].endingMinutes + cars[1].endingHours*60) - (cars[1].beggingMinutes + cars[1].beggingHours*60); 
    cars[2].time = (cars[2].endingMinutes + cars[2].endingHours*60) - (cars[2].beggingMinutes + cars[2].beggingHours*60); 
    
    for(int i = 0; i < 3; i++)
    {
        if(cars[i].time < 0) cars[i].time += 60*24;
        /*Explanation of this method:
        This is not the most optimal method to solving the problem, 
            when the arrival time is less than (in other words, the car arrived the next day) the starting time
        We fix this, by adding 24 hours to the total time
        */
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2 - i; j++)
        {
            if(cars[j].time > cars[j+1].time)
            {
                swap = cars[j];
                cars[j] = cars[j+1];
                cars[j+1] = swap;
            }
        }
    }

    std::cout << cars[0].time / 60;
    if(cars[0].time % 60 < 10) std::cout << ":0" << cars[0].time % 60;
    else std::cout << ":" << cars[0].time % 60;

    std::cout << "\n" << cars[2].time / 60;
    if(cars[2].time % 60 < 10) std::cout << ":0" << cars[2].time % 60;
    else std::cout << ":" << cars[2].time % 60;

    return 0;
}