<comand> --help

BASIC COMANDS:

1 - Linux directories

    pwd : show the path to your current directory, show where you are;
    cd <directory or path> / cd .. : navigate/enter in directories ; back to previous directory;
    ls / ls -l/ ls -a/ ls -la : show what is in the current directory, show with details and show the ocult files;
    mount / df -Th / findmnt: show how the kernel and all of the os is mount;
    du <file, path or directory> / du -h/ du -h -s : show the size of a file or directory and all the files inside it, show it with a lot of detail;

2 - Files in Linux

The name files in Linux are case sensite so A.txt is a different file than a.txt;

    touch <name><type> : create a file in the current directory;
    mkdir <name> / mkdir <PATH> : create a directory in current directory;
    rmdir <name> / rmdir <PATH> : remove or delete an empty directory;
    rm -r <name> OR <path> : remove or delete a directory with his content inside
    cp <PATH>[<parameter>]* <PATH> : copy the content from a directory to another, accordingly to the parameter passed(learn)
    tar -cvf <PATH1>.tar <PATH2> : create a tar archive; PATH1 is where the tar archive will be created and the PATH2 is what file or directory will be archived in type tar
    tar -rvf <PATH1> <PATH2> : add more files or directories to a tar archive; the PATH1 is the tar file and the PATH2 is the files to be added;
    tar -tvf <PATH> : see the content of a tar file;
    tar -xvf <PATH> : extracts a tar file;
    gzip <FILE> : compact a file

3-TXT files

    less <PATH> : read the content of a file in one page;
        /<FILE> : in the less page 
