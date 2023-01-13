<command> --help

BASIC COMMANDS:

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
    mv <source> <dest>:rename SOURCE to dest or move SOURCE to DIRECTORY; 
    cp <PATH>[<parameter>]* <PATH> : copy the content from a directory to another, accordingly to the parameter passed(learn)
    tar -cvf <PATH1>.tar <PATH2> : create a tar archive; PATH1 is where the tar archive will be created and the PATH2 is what file or directory will be archived in type tar;
    tar -cvzf <path1>.tar.gz <path2> : creates a tar archive already zipped and compacted;
    tar -cvjf <path1>.tar.bz2 <path2> : creates a tar archive compacted different than gzip;
    tar -rvf <PATH1> <PATH2> : add more files or directories to a tar archive; the PATH1 is the tar file and the PATH2 is the files to be added;
    tar -tvf <PATH> : see the content of a tar file;
    tar -xvf <PATH> : extracts a tar file;
    tar -xvf <PATH OR FILE> <PATH> : extracts only one file from the tar;
    tar --extract --file=<PATH OR FILE>.tar <PATH> : extracts only one file;
     tar -zxvf <PATH OR FILE>tar.gz <PATH> : extracts only one file from the tar.gzip;
     tar -xvf <PATH OR FILE> "<PATH1>" "<PATH2>" : extracts more than one file;
    tar -xvf <PATH OR FILE> --wildcards '*.<type>' : extracts all the files in the tar that ar form the especiffied type;
    tar -rvf <path1>.tar <path2> : insert a file in a tar archive;
    gzip <FILE> : compact a file
    gzip -c <file1> >> <fil2> : concatenate two files in one zipped file;
    gzip -d <file1>: decompress a zip file;
    gunzip -c <file>.gz > <new_file> : maintain the zip file and creates a new one decompressed; 
    
3-TXT files

    less <PATH> : read the content of a file in one page;
        /<FILE> : in the less page, you use / and the name of the file or anything else to search this word in the less page;
        ps : show all the process in the current directory;
        ps aux | less: show all the process happening in your linux;
        tail <option> <file>: list the last lines of a file;
        head <option> <file>: list the first lines of a file;
        cut <option> <file>: list a selected part of a file;
        grep <option> PATTERN <file> : search for patterns in a file;
        
4 - Locating files:

	locate <option> <pattern> : find files and directories searched in a db;
	find [-H] [-L] [-P] [-Olevel] [-D debugopts] [path...] [expression] : find files and directories with more filters;
	find <path> -name <name> : filter and search a name in a file or directory;
	find <path> -size <+ or -> <sizeinnumber>M : filter and search for files or directories with more or less megabytes of size;
	find <path> -user <user> -ls : find files per user;
	grep <option> PATTERN <file> : search for patterns in a file;
	
5 - Basic of shell script:

	<var_name>=<> : assign a value to a variable;
	echo <<$var> or <anything you text>> : print what you want;
	local<var_name><=value> : creates a local variable;
	set : show all the shell commands;
	vim /etc/profile/ : shows bash configs;
	vim /etc/enviroment/ : show your PATHS;
	alias <key>='<command>' : define a shortcut for commands;
	
6 - Manage processes:

	There is two types of processes: shell scripts and deamons, or foreground and background processes.
	top : shows all the processes happening;
	jobs : show all the processes happening or happen in the shell  terminal and their status;
	hystory : show your commands history/
	!<number> : will run the command of number <> of your history;
	!! : last command;
	!?<string>? : run the command that is most near of the string;
	CTRL + R :
7 - Commands of conection and expansion:

	| (<command1> | <command2>): (pipe), connect the output of a command to the input of other;
	& : runs a command in background;
	; (<command1> ; <command2> ; <command3>) : make a list to execute commands;
	$(<command>) : runs a command in a print message;
	$[<number1> <operator> <number2>] : math operations;
	
	ls /bin : show all the commands native from your distro;
	help; <command> --help; info; man <command>;
	
	vim .bashrc; vim .bash; vim .bash_profile 
	
8 - System informations:

	unname <option>: print system information; 
	lshw : show all hardware system informations;
	al
	
9 - Input and output:

	<command> > <file or path> : directs the output of the command to a file;
	ls *s > files.txt
	<command> < <file or path> : directs a file to an input of a command; 
	wc -l < files.txt
	9
	>> : appends an already present file in the directory
	
10 - child shell parent shell:

	bash; ps -f; ps -forest;
	
11- Sort:

	sort <option> <file> : sort the content in the file;
	-m, -M, -k, -t, -nr
	
