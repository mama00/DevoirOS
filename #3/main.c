#include <stdio.h>
#include <windows.h>
#include <string.h>
#define DEST_SIZE 100
#include <stdbool.h>


bool is_number (char* verify)

{
    int i =0;
    if ((verify[0]=='+'&& verify[1]!='\0') )
        i=1;
    if (verify[0]=='0')
        return false;
    while(verify[i]!= '\0')
    {
        if (!isdigit(verify[i]))
        {
            return false;
        }
        i++;
    }
    return true;

}

int main(VOID)

{
    char str[20];

    do
    {
        printf("Entrer un nombre superieur a zero: ");
        scanf("%s", &str);
    }
    while(!is_number(str) );



    char dest[DEST_SIZE] = "devoir.exe ";

    strcat(dest, str);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    /* allocate memory */
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    /* create child process */
    if (!CreateProcess(NULL, /* use command line */
                       dest, /* command */
                       NULL, /* don’t inherit process handle */
                       NULL, /* don’t inherit thread handle */
                       FALSE, /* disable handle inheritance */
                       0, /* no creation flags */
                       NULL, /* use parent’s environment block */
                       NULL, /* use parent’s existing directory */
                       &si,
                       &pi))
    {
        fprintf(stderr, "Create Process Failed");
        return -1;
    }
    /* parent will wait for the child to complete */
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("\nChild Complete");
    /* close handles */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
