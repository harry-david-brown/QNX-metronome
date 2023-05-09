# QNX-metronome
C program that works like a metronome, printing a time-signature beat to the correct timing in real-time. Uses timers, message passing, and a resource manager

### Output ###
Usage: ./metronome beats-per-minute time-signature-top time-signature-bottom  
$./metronome 100 2 4  
:1&2&  
:1&2&  
:1&2&  
...  
"One and two and one and two and one and two and one and two and..."

### Valid Inputs ###
<pre>
+----------------------+-------------------------+----------------------------------------+----------------------------------------------+  
| Time-signature-top   | Time-signature-bottom    | Number of Intervals within each beat   | Pattern for Intervals within Each Beat      |  
+----------------------+-------------------------+----------------------------------------+----------------------------------------------+  
| 2                    | 4                       | 4                                      | 1&2&                                         |  
| 3                    | 4                       | 6                                      | 1&2&3&                                       |  
| 4                    | 4                       | 8                                      | 1&2&3&4&                                     |  
| 5                    | 4                       | 10                                     | 1&2&3&4-5-                                   |  
| 3                    | 8                       | 6                                      | 1-2-3-                                       |  
| 6                    | 8                       | 6                                      | 1&a2&a                                       |  
| 9                    | 8                       | 9                                      | 1&a2&a3&a                                    |  
| 12                   | 8                       | 12                                     | 1&a2&a3&a4&a                                 |  
+----------------------+-------------------------+----------------------------------------+----------------------------------------------+  
</pre>

### Note ###
This project was made using QNX Momentics for a QNX Neutrino operating system. You will need to import this project if you would like to use it.