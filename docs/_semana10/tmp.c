

id = msgget(key, IPC_CREAT | S_IRUSR | S_IWUSR);
if (id == -1) perror(msgget);

if (msgctl(id, IPC_RMID, NULL) == -1) perror("msgctl");
    

key_t key;
int id;
key = ftok("/mydir/myfile", 'x');
if (key == -1) perrror("ftok");

id = msgget(key, IPC_CREAT | S_IRUSR | S_IWUSR);
if (id == -1) perror("msgget");

