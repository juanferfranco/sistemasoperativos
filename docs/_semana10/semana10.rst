Semana 10
===========
El plan de esta semana será:

* En la sesión 1: solución de dudas para la evaluación
* En la sesión 2: evaluación sumativa 2

Sesión 1
---------

El código que analizamos en clase hoy:

.. code-block:: c
   :linenos:

   #include <stdio.h>
   #include <stdlib.h>
   
   int minInt(int argInts[], int size );
   
   int main(int argc, char *argv[]){
       
       int argParams[argc-1];
       int status = 0;
       int exitStatus = EXIT_SUCCESS;
   
       if(argc > 1){
           for(int i= 1; i < argc ;i++){
               status = sscanf(argv[i], "%d", &argParams[i-1]);
               if(status != 1){
                   printf("Invalid parameter \n");
                   exit(EXIT_FAILURE);
               } 
           }
           printf("Min int: %d\n", minInt(argParams,argc-1));
       }
       else{
           printf("Min int: no arguments\n");
           exitStatus = EXIT_FAILURE;
       }
       exit(exitStatus);
   }
   
   int minInt(int argInts[], int size ){
       int value = argInts[0];
   
       for(int i = 1; i< size;i++){
           if(value > argInts[i]) value =  argInts[i];
       }
       return value; 
   }
   
.. code-block:: c
   :linenos:

   #include <stdio.h>
   #include <stdlib.h>
   
   int maxInt(int argInts[], int size );
   
   int main(int argc, char *argv[]){
       
       int argParams[argc-1];
       int status = 0;
       int exitStatus = EXIT_SUCCESS;
   
       if(argc > 1){
           for(int i= 1; i < argc ;i++){
               status = sscanf(argv[i], "%d", &argParams[i-1]);
               if(status != 1){
                   printf("Invalid parameter \n");
                   exit(EXIT_FAILURE);
               } 
           }
           printf("Max int: %d\n", maxInt(argParams,argc-1));
       }
       else{
           printf("Max int: no arguments\n");
           exitStatus = EXIT_FAILURE;
       }    
       exit(exitStatus);
   }
   
   int maxInt(int argInts[], int size ){
       int value = argInts[0];
   
       for(int i = 1; i< size;i++){
           if(argInts[i] > value) value =  argInts[i];
       }
   
       return value; 
   }
   
.. code-block:: c
   :linenos:

   #include <stdio.h>
   #include <stdlib.h>
   
   double meanInt(int argInts[], int size );
   
   int main(int argc, char *argv[]){
       int argParams[argc-1];
       int status = 0;
       int exitStatus = EXIT_SUCCESS;
       if(argc > 1){
           for(int i= 1; i < argc ;i++){
               status = sscanf(argv[i], "%d", &argParams[i-1]);
               if(status != 1){
                   printf("Invalid parameter \n");
                   exit(EXIT_FAILURE);
               } 
           }
           printf("Mean: %lf\n", meanInt(argParams,argc-1));
       }
       else{
           printf("Mean: no arguments\n");
           exitStatus = EXIT_FAILURE;
       }    
       exit(exitStatus);
   }
   
   double meanInt(int argInts[], int size ){
       double value = 0;
   
       for(int i = 0; i< size;i++){
           value = value + argInts[i];
       }
   
       return value/size; 
   }   
   


.. code-block:: c
   :linenos:

   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   #include <sys/types.h>
   #include <sys/wait.h>
   
   int main(int argc, char *argv[]){
   
       char *argvFork[argc+1];
       
       for(int i = 1; i < argc;i++){
           argvFork[i] = argv[i];
       }
       argvFork[argc] = NULL;
   
       pid_t hijo;    
       for(int i = 1; i <= 3;i++){
           hijo = fork();
           switch(hijo){
               case -1:
                   printf("error al crear hijo %d\n", i);
                   exit(EXIT_FAILURE);
               break;
               case 0:
                   if(i == 1) argvFork[0]= "./min";
                   else if(i==2) argvFork[0]= "./max";
                   else argvFork[0]= "./mean";
                   execv(argvFork[0],argvFork);
                   printf("HIJO%d:",i);
                   perror("execv fail");
                   exit(EXIT_FAILURE);
               break;            
               default:
               break;
           }
       }
       wait(NULL);
       wait(NULL);
       wait(NULL);
       exit(EXIT_SUCCESS);
   }
   

Sesión 2
---------
