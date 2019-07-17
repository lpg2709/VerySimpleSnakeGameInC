# Very simple snake game in C [Only for windows]

<p align="center">
  <img src=".img/jogoMap.png">
</p>

## Whats is this code:

This is a version of the snake game made with C running in prompt. The code is not the best version or logic for this game. The focus is a simple code for beginners understand arrays and simple concepts of a game logic.

## Whats is need to run this code:

You only need a compiler for C/C++ whogameOver can compile for Windows. All header used in this project is standard headers on compilers for Windows.

## Explaining the code:

- The headres:
    - ```stdio.h```
    
    ```c
    // Funcrtion used of stdio.h
    int printf ( const char * format, ... );
    FILE * fopen ( const char * filename, const char * mode );
    size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
    int fclose ( FILE * stream );
    size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
    ```
    - ```stdlib.h```
    ```c
    // Funcrtion used of stdlib.h
    int rand (void);
    void srand (unsigned int seed);
    void exit (int status);
    int system (const char* command);
    ```
    - ```conio.h```
    
    >Header only for windows
    ```c
    // Funcrtion used of conio.h
    
    ```
    - ```windows.h```
    
    >Header only for windows
    ```c
    // Funcrtion used of windows.h
    
    ```
    - ```time.h```
    ```c
    // Funcrtion used of time.h
    time_t time (time_t* timer);
    
    ```
- Functions:
    ```c
    void setUp(); // read the record file and startup the variables
    void mapa(); // the output function, draw the map
    void entrada(); // the input function, read the keyboard without interruptions
    void logica(); // all the checks and logic of the game    
    ```




<p align="center">
  <img src=".img/gameOver.PNG">
</p>

<p align="center">
  <img src=".img/record.PNG">
</p>





## References:

[stdio.h](http://www.cplusplus.com/reference/cstdio/)

[stdlib.h](http://www.cplusplus.com/reference/cstdlib/)

[time.h](http://www.cplusplus.com/reference/ctime/)