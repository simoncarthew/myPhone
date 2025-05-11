# myPHONE: A phone that I made for me.

# FIRMAWARE

## Architechture

The work is split across the two cores of the ESP32. The main thread handles all the bulk of the work from the applications. The supporting thread does tasks for the main thread applications that would otherwise take away from the continuous flow of the main thread. 

### Main Thread
On start up the main thread enters the home application. The user can enter and exit applications from the home application. The home application is also a derivation of the app class with same structure. 

Every application must check for interrupts from supporting thread in idle state. When a supporting interrupt occurs, the interrupt handler decides which application to start in response to the interrupt. 

### Supporting Thread
On start up the supporting thread enters the continuous task function. Here, it calls the continuous function of every application that requires continuous support. The supporting thread keeps track of time and passes time since of last call to the continuous tasks and the continuous tasks themselves decides if they should run.

At the end of every continuous task, the thread checks for support request. If there is a request, the request task function of the necessary class is called.

Continuous or requested tasks may output an interrupt for the main thread that is shared via the global interrupt string. 