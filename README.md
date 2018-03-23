# Multilevel-FeedBack-Queue-And-RealTime-Share-Scheduling-In-C
This project is for the creation of the simulation of different kind of scheduling algorithms on either real life problem or simple CPU process.
1) Level 1 : Fixed priority preemptive Scheduling.
   
   Level 2 : Round Robin Scheduling.
   
   For a Fixed priority preemptive Scheduling (Queue 1), the Priority 0 is highest priority. If one
   process P1 is scheduled and running , another process P2 with higher priority comes. The New
   process (high priority) process P2 preempts currently running process P1 and process P1 will go
   to second level queue. Time for which process will strictly execute must be considered in the
   multiples of 2..
   All the processes in second level queue will complete their execution according to round robin
   scheduling.
   Consider: 
   1. Queue 2 will be processed after Queue 1 becomes empty.
   2. Priority of Queue 2 has lower priority than in Queue 1.
 
2) Sudesh Sharma is a Linux expert who wants to have an online system where he can
   handle student queries. Since there can be multiple requests at any time he wishes to dedicate a
   fixed amount of time to every request so that everyone gets a fair share of his time. He will log
   into the system from 10am to 12am only. He wants to have separate requests queues for students
   and faculty. Implement a strategy for the same. The summary at the end of the session should
   include the total time he spent on handling queries and average query time.
   
