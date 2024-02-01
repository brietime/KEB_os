# operating_system

how to use named_pipe.out
//mkfifo testfifo
//exec 3<> testfifo //add file descriptor
//echo hello > testfifo
//./named_pipe.out

//exec 3>&- //remove file descriptor
