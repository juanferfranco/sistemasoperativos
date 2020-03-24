Semana 10
===========


Material de la semana
----------------------

Esta semana vamos a analizar cómo sincronizar el acceso 
a recursos compartidos en un mismo procesos utilizando semáforos. En `este 
enlace <https://docs.google.com/presentation/d/1EfixM_Svf4z5tO_WYw1K7T2CH7ofUykifvB7b2LTqQk/edit?usp=sharing>`__
se encuentra el material de trabajo.


Solución al parcial 2
----------------------

Con respecto a la evaluación anterior esta es una posible solución con sus respectivos archivos.


Grupo 2 a 4:
^^^^^^^^^^^^^
Se muestra una posible solución a los problemas de cada sesión:

Sesión 1
#########

Código proceso 1:

.. code-block:: c
   :linenos:

    #include <stdio.h>
	#include <stdlib.h>

	struct _keyValue{
	    char key[21];
	    int value;
	};

	struct _keyValue keyValueArr[100];

	int main(int argc, char * argv[]){


	    FILE *fin = fopen(argv[1],"r");
	    FILE *fout = fopen(argv[2],"w");

	    int status = 0;
	    int lineCounter = 0;

	    // Read each line
	    while(1){

		status = fscanf(fin,"%s %d", keyValueArr[lineCounter].key, &keyValueArr[lineCounter].value);
		if(status != 2) break;
		lineCounter++;
	    }

	    // take from https://www.dummies.com/programming/c/how-to-sort-arrays-in-c-programming/
	    struct _keyValue temp;
	    for(int outer=0; outer < lineCounter; outer++){
		for(int inner=outer+1;inner < lineCounter; inner++){
		    if(keyValueArr[outer].value < keyValueArr[inner].value){
		        temp=keyValueArr[outer];
		        keyValueArr[outer] = keyValueArr[inner];
		        keyValueArr[inner] = temp;
		    }
		}
	    }

	    for(int i= 0; i < lineCounter;i++){
		fprintf(fout,"%s %d\n",keyValueArr[i].key,keyValueArr[i].value);
	    }

	    fclose(fin);
	    fclose(fout);
	    exit(EXIT_SUCCESS);
	}

Código proceso 2:

.. code-block:: c
   :linenos:

    #include <stdio.h>
	#include <stdlib.h>

	struct _keyValue{
	    char key[21];
	    int value;
	};

	struct _keyValue keyValueArr[100];

	int main(int argc, char * argv[]){

	    FILE *fin = fopen(argv[1],"r");
	    FILE *fout = fopen(argv[2],"w");

	    int status = 0;
	    int lineCounter = 0;

	    // Read each line
	    while(1){

		status = fscanf(fin,"%s %d", keyValueArr[lineCounter].key, &keyValueArr[lineCounter].value);
		if(status != 2) break;
		lineCounter++;
	    }

	    for(int i = lineCounter - 1; i >= 0; i--){
		fprintf(fout,"%s %d\n",keyValueArr[i].key,keyValueArr[i].value);
	    }

	    fclose(fin);
	    fclose(fout);
	    exit(EXIT_SUCCESS);
	}

Código proceso 3:

.. code-block:: c
   :linenos:

    #include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/wait.h>

	int main(int argc, char * argv[]){

	    pid_t pid = fork();
	    if(pid < 0){
		perror("first fork: ");
		exit(EXIT_FAILURE);
	    }
	    if(pid == 0){
		char *args[]={"./p1",argv[1],argv[2], NULL};
		execv("./p1",args);    
		perror("first execv fails: ");
	    }
	    else{
		pid = fork();
		if(pid < 0){
		    perror("second fork: ");
		    exit(EXIT_FAILURE);
		}
		if(pid == 0){
		    char *args[]={"./p2",argv[1],argv[3], NULL};
		    execv("./p2",args);    
		    perror("second execv fails: ");
		}
		else{
		    wait(NULL);
		    wait(NULL);
		    
		    FILE * fout1 = fopen(argv[2],"r");
		    FILE * fout2 = fopen(argv[3],"r");
		    char buffer[40];
		    char *status = NULL;
		    printf("%s: \n",argv[2]);
		    while(1){
		        status = fgets(buffer,sizeof buffer,fout1);
		        if(status == NULL) break;
		        printf("%s",buffer);
		    }
		    printf("%s: \n",argv[3]);
		    while(1){
		        status = fgets(buffer,sizeof buffer,fout2);
		        if(status == NULL) break;
		        printf("%s",buffer);
		    }
		    exit(EXIT_SUCCESS);
		}
	    }
	    exit(EXIT_FAILURE);
	}

Archivo de entrada:

.. code-block:: c
   :linenos:

    dddd 4444
    aaaa 1111
    bbbb 5555
    cccc 3333
    eeee 2222
    ffff 8888

Sesión 2
#########

Código del programa:

.. code-block:: c
   :linenos:


    #include <stdio.h>
	#include <stdlib.h>
	#include <pthread.h>
	#include <string.h>

	struct _reg{
	    char name[21];
	    char job[21];
	    int age;
	};

	struct _reg regArr[100];

	void * th1(void *arg);
	void * th2(void *arg);

	struct _threadParam{
	    int regCounter;
	    char *pFilename;
	};


	int main(int argc, char *argv[]){

	    FILE *fin = fopen(argv[1],"r");
	    int status = 0;
	    int regCounter = 0;

	    printf("In file: \n");
	    while(1){
		status = fscanf(fin,"%s %s %d",regArr[regCounter].name, regArr[regCounter].job, &regArr[regCounter].age);
		if(status != 3) break;
		printf("%s %s %d\n",regArr[regCounter].name, regArr[regCounter].job, regArr[regCounter].age);
		regCounter++;
	    }
	    fclose(fin);


	    pthread_t id[2];
	    struct _threadParam par1= {regCounter,argv[2]};
	    struct _threadParam par2= {regCounter,argv[3]};
	    pthread_create(&id[0], NULL, th1,&par1);
	    pthread_create(&id[1], NULL, th2,&par2);
	    pthread_join(id[0],NULL);
	    pthread_join(id[1],NULL);


	    char buffer[100]; 
	    FILE *fout = fopen(argv[2],"r");
	    printf("\n%s file: \n",argv[2]);
	    for(int i = 0; i < regCounter; i++) printf("%s", fgets(buffer,sizeof buffer,fout));
	    fclose(fout);

	    fout = fopen(argv[3],"r");
	    printf("\n\n%s file: \n",argv[3]);
	    for(int i = 0; i < regCounter; i++) printf("%s", fgets(buffer,sizeof buffer,fout));
	    printf("\n");

	    fclose(fout);
	    exit(EXIT_SUCCESS);
	}

	void * th1(void *arg){
	    int regCounter = ((struct _threadParam *)arg)->regCounter;
	    FILE *fout = fopen(((struct _threadParam *)arg)->pFilename,"w");

	    for(int i= regCounter-1; i >= 0;i--){
		fprintf(fout, "%s %s %d",regArr[i].name, regArr[i].job, regArr[i].age);
		if(i != 0) fprintf(fout,"\n");
	    }

	    fclose(fout);
	    pthread_exit(0);
	}

	void * th2(void *arg){
	    int regCounter = ((struct _threadParam *)arg)->regCounter;
	    FILE *fout = fopen(((struct _threadParam *)arg)->pFilename,"w");

	    int index[regCounter];

	    for(int i = 0; i < regCounter;i++){
		index[i] = i;
	    }

	    int temp;
	    for(int outer = 0; outer < regCounter; outer++){
		for(int inner = outer+1; inner < regCounter; inner++){
		    if( ( strcmp(regArr[index[outer]].job , regArr[index[inner]].job ) ) > 0 ){
		        temp = index[outer];
		        index[outer] = index[inner];
		        index[inner] = temp;
		    }
		}
	    }

	    for(int i= 0; i < regCounter; i++){
		fprintf(fout, "%s %s %d",regArr[ index[i] ].name, regArr[ index[i] ].job, regArr[ index[i] ].age);
		if(i != (regCounter -1) ) fprintf(fout,"\n");
	    } 

	    fclose(fout);
	    pthread_exit(0);
	}

Archivo de entrada:

.. code-block:: c
   :linenos:

    oooo ppp 8
    yyyy zzz 13
    gggg hhh 4
    uuuu vvv 11
    aaaa bbb 1
    mmmm nnn 7
    kkkk lll 6
    qqqq rrr 9
    cccc ddd 2
    iiii jjj 5
    ssss ttt 10
    wwww xxx 12
    eeee fff 3

Grupo 4 a 6:
^^^^^^^^^^^^^
Se muestra una posible solución a los problemas de cada sesión:

Sesión 1
#########

Código del proceso 1:

.. code-block:: c
   :linenos:

    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	struct _word{
	    char* wordPointer;
	    int charNumber;
	};

	struct _word wordArray[100];


	int main(int argc, char * argv[]){


	    FILE *fin = fopen(argv[1],"r");
	    FILE *fout = fopen(argv[2],"w");

	    char buffer[100]; // read a line with 100 words max
	    fgets(buffer, sizeof buffer,fin);
	    
	    const char s[2] = " ";
	    char *token;
	    token = strtok(buffer, s);
	    int wordCounter = 0;

	    while( token != NULL ) {
	      wordArray[wordCounter].wordPointer = token;
	      wordArray[wordCounter].charNumber = strlen(token);
	      wordCounter++;  
	      token = strtok(NULL, s);
	    }

	    // take from https://www.dummies.com/programming/c/how-to-sort-arrays-in-c-programming/
	    struct _word temp;
	    for(int outer=0; outer < wordCounter; outer++){
		for(int inner=outer+1;inner < wordCounter; inner++){
		    if(wordArray[outer].charNumber > wordArray[inner].charNumber){
		        temp=wordArray[outer];
		        wordArray[outer] = wordArray[inner];
		        wordArray[inner] = temp;
		    }
		}
	    }

	    for(int i= 0; i < wordCounter;i++){
		fprintf(fout,"%s",wordArray[i].wordPointer);
		if( i != (wordCounter - 1) ) fprintf(fout," ");
	    }

	    fclose(fin);
	    fclose(fout);
	    exit(EXIT_SUCCESS);
	}

Código del proceso 2:

.. code-block:: c
   :linenos:

    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	struct _word{
	    char* wordPointer;
	    int charNumber;
	};

	struct _word wordArray[100];


	int main(int argc, char * argv[]){


	    FILE *fin = fopen(argv[1],"r");
	    FILE *fout = fopen(argv[2],"w");

	    char buffer[100]; // read a line with 100 words max
	    fgets(buffer, sizeof buffer,fin);
	    
	    const char s[2] = " ";
	    char *token;
	    token = strtok(buffer, s);
	    int wordCounter = 0;

	    while( token != NULL ) {
	      wordArray[wordCounter].wordPointer = token;
	      wordArray[wordCounter].charNumber = strlen(token);
	      wordCounter++;  
	      token = strtok(NULL, s);
	    }

	    for(int i= (wordCounter-1); i >= 0;i--){
		fprintf(fout,"%s",wordArray[i].wordPointer);
		if( i != 0 ) fprintf(fout,"\n");
	    }

	    fclose(fin);
	    fclose(fout);
	    exit(EXIT_SUCCESS);
	}

Código del proceso 3:

.. code-block:: c
   :linenos:

    #include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/wait.h>

	int main(int argc, char * argv[]){

	    pid_t pid = fork();
	    if(pid < 0){
		perror("first fork: ");
		exit(EXIT_FAILURE);
	    }
	    if(pid == 0){
		char *args[]={"./p1",argv[1],argv[2], NULL};
		execv("./p1",args);    
		perror("first execv fails: ");
	    }
	    else{
		pid = fork();
		if(pid < 0){
		    perror("second fork: ");
		    exit(EXIT_FAILURE);
		}
		if(pid == 0){
		    char *args[]={"./p2",argv[1],argv[3], NULL};
		    execv("./p2",args);    
		    perror("second execv fails: ");
		}
		else{
		    wait(NULL);
		    wait(NULL);
		    
		    FILE * fout1 = fopen(argv[2],"r");
		    FILE * fout2 = fopen(argv[3],"r");
		    char buffer[40];
		    char *status = NULL;
		    printf("%s: \n",argv[2]);
		    while(1){
		        status = fgets(buffer,sizeof buffer,fout1);
		        if(status == NULL) break;
		        printf("%s",buffer);
		    }
		    printf("\n\n%s: \n",argv[3]);
		    while(1){
		        status = fgets(buffer,sizeof buffer,fout2);
		        if(status == NULL) break;
		        printf("%s",buffer);
		    }
		    printf("\n");
		    exit(EXIT_SUCCESS);
		}
	    }
	    exit(EXIT_FAILURE);
	}

Archivo de entrada:

.. code-block:: c
   :linenos:

    zzzzzz wwwww bbbb ccc dd a

Sesión 2
#########

Código del programa:

.. code-block:: c
   :linenos:

    #include <stdio.h>
	#include <stdlib.h>
	#include <pthread.h>
	#include <string.h>

	struct _reg{
	    char name[21];
	    char job[21];
	    int age;
	};

	struct _reg regArr[100];

	void * th1(void *arg);
	void * th2(void *arg);

	struct _threadParam{
	    int regCounter;
	    char *pFilename;
	};


	int main(int argc, char *argv[]){

	    FILE *fin = fopen(argv[1],"r");
	    int status = 0;
	    int regCounter = 0;

	    printf("In file: \n");
	    while(1){
		status = fscanf(fin,"%s %s %d",regArr[regCounter].name, regArr[regCounter].job, &regArr[regCounter].age);
		if(status != 3) break;
		printf("%s %s %d\n",regArr[regCounter].name, regArr[regCounter].job, regArr[regCounter].age);
		regCounter++;
	    }
	    fclose(fin);


	    pthread_t id[2];
	    struct _threadParam par1= {regCounter,argv[2]};
	    struct _threadParam par2= {regCounter,argv[3]};
	    pthread_create(&id[0], NULL, th1,&par1);
	    pthread_create(&id[1], NULL, th2,&par2);
	    pthread_join(id[0],NULL);
	    pthread_join(id[1],NULL);


	    char buffer[100]; 
	    FILE *fout = fopen(argv[2],"r");
	    printf("\n%s file: \n",argv[2]);
	    for(int i = 0; i < regCounter; i++) printf("%s", fgets(buffer,sizeof buffer,fout));
	    fclose(fout);

	    fout = fopen(argv[3],"r");
	    printf("\n\n%s file: \n",argv[3]);
	    for(int i = 0; i < regCounter; i++) printf("%s", fgets(buffer,sizeof buffer,fout));
	    printf("\n");



	    fclose(fout);
	    exit(EXIT_SUCCESS);
	}

	void * th1(void *arg){
	    int regCounter = ((struct _threadParam *)arg)->regCounter;
	    FILE *fout = fopen(((struct _threadParam *)arg)->pFilename,"w");



	    int index[regCounter];
	    for(int i = 0; i < regCounter;i++){
		index[i] = i;
	    }


	    int temp;
	    for(int outer = 0; outer < regCounter; outer++){
		for(int inner = outer+1; inner < regCounter; inner++){
		    if( regArr[index[outer]].age >  regArr[index[inner]].age){
		        temp = index[outer];
		        index[outer] = index[inner];
		        index[inner] = temp;
		    }
		}
	    }

	    for(int i= 0; i < regCounter; i++){
		fprintf(fout, "%s %s %d",regArr[ index[i] ].name, regArr[ index[i] ].job, regArr[ index[i] ].age);
		if(i != (regCounter -1) ) fprintf(fout,"\n");
	    } 


	    fclose(fout);
	    pthread_exit(0);
	}

	void * th2(void *arg){
	    int regCounter = ((struct _threadParam *)arg)->regCounter;
	    FILE *fout = fopen(((struct _threadParam *)arg)->pFilename,"w");

	    int index[regCounter];

	    for(int i = 0; i < regCounter;i++){
		index[i] = i;
	    }

	    int temp;
	    for(int outer = 0; outer < regCounter; outer++){
		for(int inner = outer+1; inner < regCounter; inner++){
		    if( strlen(regArr[index[outer]].name) > strlen(regArr[index[inner]].name) ){
		        temp = index[outer];
		        index[outer] = index[inner];
		        index[inner] = temp;
		    }
		}
	    }

	    for(int i= 0; i < regCounter; i++){
		fprintf(fout, "%s %s %d",regArr[ index[i] ].name, regArr[ index[i] ].job, regArr[ index[i] ].age);
		if(i != (regCounter -1) ) fprintf(fout,"\n");
	    } 

	    fclose(fout);
	    pthread_exit(0);
	}


Archivo de entrada:

.. code-block:: c
   :linenos:

    ooooooooooooo ppp 8
	yyyyyyyyyyyy zzz 13
	ggggggggggg hhh 4
	uuuuuuuuuu vvv 11
	aaaaaaaaa bbb 1
	mmmmmmmm nnn 7
	kkkkkkk lll 6
	qqqqqq rrr 9
	ccccc ddd 2
	iiii jjj 5
	sss ttt 10
	ww xxx 12
	e fff 3

