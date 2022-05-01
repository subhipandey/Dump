echo "Display top 10 processes in descending order"
ps|sort -r|head -10
echo "OS NAME IS:"
uname;
echo "release no is:"
uname -r;
whoami
echo "current shell,home directory,os type,current path,current working directory"
echo $SHELL
echo $HOME
echo $OSTYPE
echo $PATH
pwd
echo "current process id :$$"