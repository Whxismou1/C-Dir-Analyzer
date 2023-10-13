#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printMenu();

int main(int argc, char *argv[])
{

    int opcion;

    char dirActual[100];
    if (argc == 1)
    {
        strcpy(dirActual, "./");
    }
    else
    {
        strcpy(dirActual, argv[1]);
        char cmd[100];
        sprintf(cmd, "test -d %s", argv[1]);
        if (system(cmd) != 0)
        {
            printf("%s", cmd);
            printf("ERROR: El directorio no se ha encontrado!");
            return 1;
        }
    }

    do
    {
        char numArchivos[1000], numSubdirectorios[1000];
        printMenu();
        printf("Introduce una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            sprintf(numArchivos, "find %s -type f | wc -l", dirActual);
            FILE *pipe = popen(numArchivos, "r");
            if (pipe == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'find' con 'wc -l'\n");
                return 1;
            }
            int nA;
            fscanf(pipe, "%d", &nA);
            pclose(pipe);

            printf("\nNúmero de archivos en %s: %d\n", dirActual, nA);
            break;
        case 2:
            sprintf(numSubdirectorios, "find %s -type d | wc -l", dirActual);
            FILE *pipeSubdir = popen(numSubdirectorios, "r");

            if (pipeSubdir == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'find' con 'wc -l'\n");
                return 1;
            }

            int nS;
            fscanf(pipeSubdir, "%d", &nS);
            pclose(pipeSubdir);

            printf("\nNúmero de subdirectorios en %s: %d\n", dirActual, nS);
            break;
        case 3:
            char ficheroMasGrande[1000];
            sprintf(ficheroMasGrande, "find %s -type f -exec du -h {} + | sort -rh | head -n 1 | cut -f2", dirActual);
            FILE *pipeGrande = popen(ficheroMasGrande, "r");

            if (pipeGrande == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'find' para el fichero más grande\n");
                return 1;
            }

            char ficheroGrande[1000];
            fgets(ficheroGrande, sizeof(ficheroGrande), pipeGrande);
            pclose(pipeGrande);

            printf("Fichero más grande en %s: %s", dirActual, ficheroGrande);
            break;

        case 4:
            char ficheroMasPequeno[1000];
            sprintf(ficheroMasPequeno, "find %s -type f -exec du -h {} + | sort -h | head -n 1 | cut -f2", dirActual);
            FILE *pipePequeno = popen(ficheroMasPequeno, "r");

            if (pipePequeno == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'find' para el fichero más pequeño\n");
                return 1;
            }

            char ficheroPequeno[1000];
            fgets(ficheroPequeno, sizeof(ficheroPequeno), pipePequeno);
            pclose(pipePequeno);

            printf("Fichero más pequeño en %s: %s", dirActual, ficheroPequeno);
            break;

        case 5:
            char espacioTotal[1000];
            sprintf(espacioTotal, "du -sh %s | cut -f1", dirActual);
            FILE *pipeEspacio = popen(espacioTotal, "r");

            if (pipeEspacio == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'du' para calcular el espacio total ocupado\n");
                return 1;
            }

            char espacio[100];
            fgets(espacio, sizeof(espacio), pipeEspacio);
            pclose(pipeEspacio);

            printf("Espacio total ocupado en %s: %s\n", dirActual, espacio);
            break;

        case 6:
            char numLectura[1000];
            sprintf(numLectura, "find %s -type f -perm -u=r | wc -l", dirActual);
            FILE *pipeLectura = popen(numLectura, "r");

            if (pipeLectura == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'find' para el número de archivos con permiso de lectura\n");
                return 1;
            }

            int nL;
            fscanf(pipeLectura, "%d", &nL);
            pclose(pipeLectura);

            printf("Número de archivos con permiso de lectura para el usuario en %s: %d\n", dirActual, nL);
            break;

        case 7:
            char numEscritura[1000];
            sprintf(numEscritura, "find %s -type f -perm -u=w | wc -l", dirActual);
            FILE *pipeEscritura = popen(numEscritura, "r");

            if (pipeEscritura == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'find' para el número de archivos con permiso de escritura\n");
                return 1;
            }

            int nE;
            fscanf(pipeEscritura, "%d", &nE);
            pclose(pipeEscritura);

            printf("Número de archivos con permiso de escritura para el usuario en %s: %d\n", dirActual, nE);
            break;

        case 8:
            char numEjecucion[1000];
            sprintf(numEjecucion, "find %s -type f -perm -u=x | wc -l", dirActual);
            FILE *pipeEjecucion = popen(numEjecucion, "r");

            if (pipeEjecucion == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'find' para el número de archivos con permiso de ejecución\n");
                return 1;
            }

            int nEx;
            fscanf(pipeEjecucion, "%d", &nEx);
            pclose(pipeEjecucion);

            printf("Número de archivos con permiso de ejecución para el usuario en %s: %d\n", dirActual, nEx);
            break;

        case 9:
            char ficherosEjecucion[1000];
            sprintf(ficherosEjecucion, "find %s -type f -perm -a=x", dirActual);
            FILE *pipeFicherosEjecucion = popen(ficherosEjecucion, "r");

            if (pipeFicherosEjecucion == NULL)
            {
                printf("ERROR: No se pudo abrir el comando 'find' para ficheros con permiso de ejecución\n");
                return 1;
            }

            char ficherosEjec[1000];
            while (fgets(ficherosEjec, sizeof(ficherosEjec), pipeFicherosEjecucion) != NULL)
            {
                printf("%s", ficherosEjec);
            }
            pclose(pipeFicherosEjecucion);

            printf("Ficheros con permiso de ejecución para todos los usuarios en %s:\n");
            break;

        case 10:
            printf("Saliendo del programa...");
            break;

        default:
            printf("ERROR: Opcion no valida!\n");
        }
    } while (opcion != 10);
    return 0;
}

void printMenu()
{
    printf("Menú de estadisticas");
    printf("\n1) Numero de archivos");
    printf("\n2) Numero de subdirectorios");
    printf("\n3) Fichero más grande");
    printf("\n4) Fichero más pequeño");
    printf("\n5) Espacio total ocupado");
    printf("\n6) Número de ficheros con permiso de lectura para el usuario");
    printf("\n7) Número de ficheros con permiso de escritura para el usuario");
    printf("\n8) Número de ficheros con permiso de ejecución para el usuario");
    printf("\n9) Ficheros con permiso de ejecución para todos los usuarios");
    printf("\n10) Salir\n");
}