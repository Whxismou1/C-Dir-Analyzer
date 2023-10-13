# Práctica 3 de Sistemas Operativos - C.Dir-Analyzer

Este repositorio contiene el código fuente de la Práctica 3 de la asignatura de Sistemas Operativos. El objetivo de esta práctica es implementar un script en C que calcule estadísticas sobre un directorio, siguiendo un enunciado específico.

## Descripción

La Práctica 3 se centra en el desarrollo de un script en C que acepta un directorio como argumento o trabaja en el directorio actual si no se proporciona ningún argumento. El script permite al usuario realizar las siguientes tareas:

1. Calcular el número de archivos en el directorio.
2. Calcular el número de subdirectorios en el directorio.
3. Encontrar el nombre del fichero más grande.
4. Encontrar el nombre del fichero más pequeño.
5. Calcular el espacio total ocupado por el directorio en un formato legible (Mb, Gb, etc.).
6. Determinar el número de archivos con permiso de lectura para el usuario que ejecuta el script.
7. Determinar el número de archivos con permiso de escritura para el usuario que ejecuta el script.
8. Determinar el número de archivos con permiso de ejecución para el usuario que ejecuta el script.
9. Listar los ficheros con permiso de ejecución para todos los usuarios.
10. Salir del script.

El usuario puede seleccionar una opción del menú y ejecutar la tarea correspondiente. El script informará al usuario y le permitirá realizar más tareas hasta que elija salir.

## Uso

Para ejecutar el script, sigue estos pasos:

1. Clona este repositorio o descarga el código fuente.

2. Abre una terminal y navega al directorio que contiene el script.

3. Ejecuta el script proporcionando el directorio de trabajo como argumento, o simplemente ejecútalo sin argumentos para usar el directorio actual:

   ```shell
   ./dir_stats_script [directorio_de_trabajo]
